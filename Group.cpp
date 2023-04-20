#include <iostream>
#include <vector>
#include <stdexcept>
#include "Group.h"
#include "Student.h"
using namespace std;

Group::Group() {
    name = "No Name!";
}

Group::Group(const string& _name) {
    setName(_name);
}

string Group::getName() const {
    return name;
}

void Group::setName(const string& value) {
    if (!value.empty()) {
        name = value;
    }
    else {
        throw invalid_argument("Wrong name fromat!");
    }
}

void Group::addStudent(Student student) {
    Student* new_students = new Student[count + 1];
    for (int i = 0; i < count; i++) {
        new_students[i] = students[i];
    }
    new_students[count] = student;
    delete[] students;
    students = new_students;
    count++;
}

void Group::print() {
    cout << "------ GROUP " << name << " ------" << endl;
    if (count == 0) {
        cout << "The group is empty!" << endl;
    }
    for (int i = 0; i < count; i++) {
        cout << students[i];
    }
}

void Group::getHighGPAstudents() {
    int counter = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].getAverageGrade() > 4.0) {
            cout << students[i];
            counter += 1;
        }
    }
    if (counter == 0) {
        cout << "There is no such students!" << endl;
    }
}

void Group::sortByPlace() {
    Student temp;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (students[j] > students[j + 1]) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    print();
}

bool operator > (const Student& student1, const Student& student2) {
    return (int(student1.getPlace()[0]) > int(student2.getPlace()[0]));
}
