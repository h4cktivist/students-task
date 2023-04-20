#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Student
{
public:
    Student();
    Student(const string& _name, const string& _place, vector<float> _grades);

    string getName() const;
    string getPlace() const;
    vector<float> getGrades() const;
    float getAverageGrade() const;

    void setName(const string& value);
    void setPlace(const string& value);
    void setGrades(vector<float> values);

private:
    string name;
    string place_of_birth;
    vector<float> grades;
};

ostream& operator << (ostream& os, const Student& student);
