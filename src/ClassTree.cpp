#include "ClassTree.h"

ClassTree::ClassTree()
{
    root = NULL;
    //ctor
}

ClassTree::~ClassTree()
{
    //dtor
}

void ClassTree::addClassNode(string name, string department, int courseNumber, string teacher, string time, string day, int enrollment, int capacity)
{
    ClassNode *temp = root; //set temp to begin it's search at root
    ClassNode *parent = NULL;

    ClassNode *newnode = new ClassNode(name, department, courseNumber, teacher, time, day, enrollment, capacity); //node that temp is being compared against
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;

    while(temp != NULL)
    {
        parent = temp;

        if(newnode->name.compare(temp->name) < 0){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if (parent == NULL){
        root = newnode;
    }
    else if(newnode->name.compare(parent->name) < 0){
        parent->left = newnode;
        newnode->parent = parent;
    }
    else{
        parent->right = newnode;
        newnode->parent = parent;
    }
}

void ClassTree::printClassInventory(){
    printClassInventory(root);
}

void ClassTree::printClassInventory(ClassNode *node){
    if(node->left != NULL){
        printClassInventory(node->left);
    }
    cout<<"Class: "<<node->name<<" ("<<node->department<<" "<<node->courseNumber<<")"<<endl;
    cout<<"Teacher: "<<node->teacher<<endl;
    cout<<"Time: "<< node->time<<", "<<node->day<<endl;
    if(node->enrollment == node->capacity){
        cout<<"This class is full."<<endl;
    }
    else if(node->enrollment == node->capacity-1){
        cout<<"There is 1 spot left in this class."<<endl;
    }
    else{
        int space = node->capacity-node->enrollment;
        //cout<<"Enrollment/Capacity: "<<node->enrollment<<"/"<<node->capacity<<endl;
        cout<<"There are "<<space<<" spots left in this class."<<endl;
    }
    cout<<"-----------"<<endl;
    if(node->right != NULL){
        printClassInventory(node->right);
    }
}


ClassNode* ClassTree::search(string name){
    ClassNode *temp = root;

    while(temp != NULL){

        if(name.compare(temp->name) < 0){
            temp = temp->left;
        }
        else if (name.compare(temp->name) > 0){
            temp = temp->right;
        }
        else{
            return temp;
        }
    }
    return NULL;
}

void ClassTree::enrollClass(string title){
    ClassNode *foundClass = search(title);

    if(foundClass != NULL){
        if(foundClass->enrollment == foundClass->capacity){
            cout << foundClass-> name <<" is full. You cannot enroll in this class." <<endl;
        }
        else{

            bool found = false;

            for(int i = 0; i < schedule.size(); i++){ //check if they already signed up for it
                if(schedule[i].name == title){
                    found = true;
                    cout<<"You are already signed up for "<<schedule[i].name<<"."<<endl;
                }
            }
            if(!found){
                addClassToSchedule(foundClass->name, foundClass->department, foundClass->courseNumber, foundClass->teacher, foundClass->time, foundClass->day);
                foundClass->enrollment++;
                cout << foundClass->name << " has been successfully added to your schedule." << endl;
            }
        }
    }
    else{
        cout << "Class not found." << endl;
    }
}

void ClassTree::addClassToSchedule(string name, string department, int courseNumber, string teacher, string time, string day){

    ClassNode newclass;
    newclass.name = name;
    newclass.department = department;
    newclass.courseNumber = courseNumber;
    newclass.teacher = teacher;
    newclass.time = time;
    newclass.day = day;
    schedule.push_back(newclass);

}

void ClassTree::dropClass(string title){

    bool found = false;

    for(int i = 0; i < schedule.size(); i++){
        if(schedule[i].name == title){
            found = true;
            schedule.erase(schedule.begin() + i);
            cout<<title<< " has been successfully removed from your schedule."<<endl;
        }
    }

    if(!found){
        cout<<title<< " was not found in your schedule."<<endl;
    }

    //increase class enrollment
    if(found){
        ClassNode *foundClass = search(title);
        foundClass->enrollment--;
    }

}

void ClassTree::printClassSchedule(){
    if(schedule.size() == 0){
        cout<<"Your schedule is currently empty. Select option 2 to start adding classes to your schedule."<<endl;
    }
    else{
        for(int i = 0; i < schedule.size(); i++){
            cout << "Class: "<< schedule[i].name<< " (" << schedule[i].department << " " << schedule[i].courseNumber << ")" << endl;
            cout << "Teacher: " << schedule[i].teacher << endl;
            cout << "Time: " << schedule[i].time << ", " << schedule[i].day <<endl;
            cout<<"-----------"<<endl;
        }
    }
}

void ClassTree::searchByTime()
{
    cout << "Please Enter a time for classes to start" << endl;
    string time;
    getline(cin, time);

    searchByTime(root, time);

}

void ClassTree::searchByTime(ClassNode *n, string time)
{
    //take in user's input, then use a for loop to use substring cut time
    //then compare times.

    if(n -> left != NULL)
    {
        searchByTime(n -> left, time);
    }

    string subTime;
    int timePos;
    timePos = n -> time.find("-");
    subTime = n -> time.substr(0, timePos);

    if(time.compare(subTime) == 0)
    {
        cout<<"Class: "<<n->name<<" ("<<n->department<<" "<<n->courseNumber<<")"<<endl;
        cout<<"Teacher: "<<n->teacher<<endl;
        cout<<"Time: "<< n->time<<", "<<n->day<<endl;
    }

    if(n -> right != NULL)
    {
        searchByTime(n -> right, time);
    }
}

