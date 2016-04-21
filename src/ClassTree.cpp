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
    cout<<node->time<<" "<<node->day<<endl;
    if(node->enrollment == node->capacity){
        cout<<"Class is full"<<endl;
    }
    else{
    cout<<"Enrollment/Capacity: "<<node->enrollment<<"/"<<node->capacity<<endl;
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
                cout << foundClass->name << " has been successfully added to your schedule." << endl;
                foundClass->enrollment++;
                addClassToSchedule(foundClass->name, foundClass->department, foundClass->courseNumber, foundClass->teacher, foundClass->time, foundClass->day);
            }
        }
    }
    else{
        cout << "Class not found." << endl;
    }
}

void ClassTree::addClassToSchedule(string name, string department, int courseNumber, string teacher, string time, string day){

    bool found = false;

    for(int i = 0; i < schedule.size(); i++)
    {
        if(schedule[i].name == name)
        {
            found = true;
        }
    }

    if(found == false)
    {
        ClassNode newclass;
        newclass.name = name;
        newclass.department = department;
        newclass.courseNumber = courseNumber;
        newclass.teacher = teacher;
        newclass.time = time;
        newclass.day = day;
        schedule.push_back(newclass);
    }
}

void ClassTree::dropClass(string title){

}

void ClassTree::printClassSchedule(){
    for(int i = 0; i < schedule.size(); i++){
        cout << "Class: "<< schedule[i].name<< " (" << schedule[i].department << " " << schedule[i].courseNumber << ")" << endl;
        cout << "Teacher: " << schedule[i].teacher << endl;
        cout << schedule[i].time << " " << schedule[i].day <<endl;
        cout<<"-----------"<<endl;
    }
}
