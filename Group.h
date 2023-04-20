#pragma once
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Group
{
public:
    Group();
    Group(const string& _name);

    string getName() const;
    void setName(const string& value);
    void addStudent(Student student);
    void print();
    void getHighGPAstudents();
    void sortByPlace();

private:
    string name;
    Student* students = new Student[0];
    int count = 0;
};

bool operator > (const Student& student1, const Student& student2);
