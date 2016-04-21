#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "ClassTree.h"

using namespace std;

int main()
{
    ClassTree A; //create instance of ClassTree

    ifstream inFile;
    string data;

    inFile.open("CourseOptions.txt");
    if(inFile.good())
    {
        while(getline(inFile, data))  //read/get every line of the file and store it
        {
            stringstream ss(data);

            string name;
            getline(ss, name, ',');
            //cout<<name<<endl;

            string department;
            getline(ss, department, ',');
            //cout<<department<<endl;

            int courseNumber;
            string temp;
            getline(ss, temp, ',');
            courseNumber = atoi(temp.c_str());
            //cout<<courseNumber<<endl;

            string teacher;
            getline(ss, teacher, ',');
            //cout<<teacher<<endl;

            string time;
            getline(ss, time, ',');
            //cout<<time<<endl;

            string day;
            getline(ss, day, ',');
            //cout<<day<<endl;

            int enrollment;
            string temp1;
            getline(ss, temp1, ',');
            enrollment = atoi(temp1.c_str());
            //cout<<enrollment<<endl;

            int capacity;
            string temp2;
            getline(ss, temp2, ',');
            capacity = atoi(temp2.c_str());
            //cout<<capacity<<endl;

            A.addClassNode(name, department, courseNumber, teacher, time, day, enrollment, capacity);
        }
    }
    else {
            cout<<"Error loading file."<<endl;
    }

    string userInput;
    bool quit = false;

    while(!quit)
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Print Class Options" << endl;
        cout << "2. Enroll In a Class" << endl;
        cout << "3. Drop a Class" << endl;
        cout << "4. Print Schedule" << endl;
        cout << "5. Quit" << endl;
        getline(cin, userInput);

        if(userInput == "1")
        {
            A.printClassInventory();
        }
        else if(userInput == "2")
        {
            string title;
            cout<<"Class Title: "<<endl;
            getline(cin, title);
            A.enrollClass(title);
        }
        else if(userInput == "3")
        {

        }
        else if(userInput == "4")
        {
            A.printClassSchedule();
        }
        else if(userInput == "5")
        {
            quit = true;
        }

    }
    cout<<"Goodbye!"<<endl;

    return 0;
}
