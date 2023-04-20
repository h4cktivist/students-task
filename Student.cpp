#include <iostream>
#include <stdexcept>
#include <regex>
#include "Student.h"

Student::Student() {
    name = "No Name Specified!";
    place_of_birth = "No Place of Birth Specified!";
    grades = { 0, 0, 0, 0, 0 };
}

Student::Student(const string& _name, const string& _place, vector<float> _grades) {
    setName(_name);
    setPlace(_place);
    setGrades(_grades);
}

string Student::getName() const {
    return name;
}

void Student::setName(const string& value) {
    regex pattern(R"(^[A-Z]\.[\s]{1}[A-Z]\.[\s]{1}[A-Z][a-z]+$)");
    if (regex_match(value, pattern)) {
        name = value;
    }
    else {
        cout << value;
        throw invalid_argument("Wrong name format!");
    }
}

string Student::getPlace() const {
    return place_of_birth;
}

void Student::setPlace(const string& value) {
    if (!value.empty()) {
        place_of_birth = value;
    }
    else {
        throw invalid_argument("Place of birth can't be empty!");
    }
}

vector<float> Student::getGrades() const {
    return grades;
}

void Student::setGrades(vector<float> values) {
    if (values.size() != 5) {
        throw invalid_argument("Only 5 grades are allowed!");
    }
    for (int i = 0; i < 5; i++) {
        if (values[i] < 2 || values[i] > 5) {
            throw invalid_argument("The grade should be in the range between 2 and 5!");
        }
    }
    grades = values;
}

float Student::getAverageGrade() const {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += grades[i];
    }
    return sum / 5;
}

ostream& operator << (ostream& os, const Student& student) {
    auto grades = student.getGrades();
    return os << "Name: " << student.getName() << endl
              << "Place of birth: " << student.getPlace() << endl
              << "Grades: " << grades[0] << " " << grades[1] << " " << grades[2] << " " << grades[3] << " " << grades[4] << endl
              << "GPA: " << student.getAverageGrade() << endl
              << endl;
}
