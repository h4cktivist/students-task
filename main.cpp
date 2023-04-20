#include <iostream>
#include <vector>
#include <stdexcept>
#include "Group.h"
using namespace std;

void menu() {
    cout << "1. Create group." << endl;
    cout << "2. Create student." << endl;
    cout << "3. Output all the groups and its students." << endl;
    cout << "4. Output all the students with GPA above 4.0." << endl;
    cout << "5. Sort the students by place of birth." << endl;
    cout << "6. Exit." << endl;
    cout << ">> ";
    cout << endl;
}

void createGroup(vector<Group> &groups) {
    string name;
    cout << "Enter the name of the group: ";
    cin >> name;
    try {
        Group g = Group(name);
        groups.push_back(g);
    }
    catch (invalid_argument ex) {
        cout << ex.what() << endl;
        exit(1);
    }
}

void createStudent(vector<Group> &groups) {
    string name, place, g_name;
    vector<float> grades;
    cout << "Enter student's name (format: N.N. Name): " << endl;
    cin >> name;
    cout << "Enter student's place of birth: " << endl;
    cin >> place;
    cout << "Enter five grades of the student: " << endl;
    float grade;
    for (int i = 0; i < 5; i++) {
        cin >> grade;
        grades.push_back(grade);
    }
    cout << "Enter the group name: " << endl;
    cin >> g_name;
    try {
        Student s = Student(name, place, grades);
        bool is_found = false;
        for (auto & group : groups) {
            if (group.getName() == g_name) {
                group.addStudent(s);
                is_found = true;
            }
        }
        if (!is_found) {
            throw invalid_argument("Group is not found!");
        }
    }
    catch (invalid_argument ex) {
        cout << ex.what() << endl;
        exit(1);
    }
}

int main() {
    int m = 0;
    vector<Group> groups;
    while (m != 6) {
        menu();
        cin >> m;
        if (m == 1) {
            createGroup(groups);
        }
        else if (m == 2) {
            createStudent(groups);
        }
        else if (m == 3) {
            for (auto & group : groups) {
                group.print();
            }
        }
        else if (m == 4) {
            for (auto & group : groups) {
                cout << "Group: " << group.getName() << endl;
                group.getHighGPAstudents();
            }
        }
        else if (m == 5) {
            for (auto & group : groups) {
                cout << "Group: " << group.getName() << endl;
                group.sortByPlace();
            }
        }
    }
}
