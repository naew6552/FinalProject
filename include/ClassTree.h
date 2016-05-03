#include <iostream>
#include <vector>
#ifndef CLASSTREE_H
#define CLASSTREE_H

using namespace std;

struct ClassNode{
    string name;
    string department;
    int courseNumber;
    string teacher;
    string time;
    string day;
    int enrollment;
    int capacity;
    ClassNode *parent;
    ClassNode *left;
    ClassNode *right;

    ClassNode(){};

    ClassNode(string in_name, string in_department, int in_courseNumber, string in_teacher, string in_time, string in_day, int in_enrollment, int in_capacity)
    {
        name = in_name;
        department = in_department;
        courseNumber = in_courseNumber;
        teacher = in_teacher;
        time = in_time;
        day = in_day;
        enrollment = in_enrollment;
        capacity = in_capacity;
    }
};

class ClassTree
{
    public:
        ClassTree();
        ~ClassTree();
        void printClassInventory();
        void addClassNode(string name, string department, int courseNumber, string teacher, string time, string day, int enrollment, int capacity);
        void enrollClass(string title); //calls addClassToSchedule in it's function
        void dropClass(string title);
        void addClassToSchedule(string name, string department, int courseNumber, string teacher, string time, string day);
        void printClassSchedule();
        void searchByTime();
    protected:
    private:
        std::vector<ClassNode> schedule;
        void printClassInventory(ClassNode *node);
        void searchByTime(ClassNode *n, string time);
        ClassNode* search(string name);
        ClassNode *root;
};

#endif // CLASSTREE_H
