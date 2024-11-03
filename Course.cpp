#include "Course.h"
#include "date.h"
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;
Course::Course(int cc,string cn,int chr,vector<Student> s,int m):courseCode(cc),courseName(cn),creditHours(chr),enrolledStudents(s),maxCapacity(m)
{
    //ctor
}

Course::~Course()
{
    //dtor
}


Course::Course(const Course& other):courseCode(other.courseCode),courseName(other.courseName),creditHours(other.creditHours),enrolledStudents(other.enrolledStudents),maxCapacity(other.maxCapacity)
{

}

int Course::get_courseCode()
{
    return courseCode;
}

string Course::get_courseName()
{
    return courseName;
}

int Course::get_creditHours()
{
    return creditHours;
}

vector <Student> Course::get_enrolledStudents()
{
    return enrolledStudents;
}

int Course::get_maxCapacity()
{
    return maxCapacity;
}

void Course::set_courseCode(int cc)
{
    this->courseCode=cc;
}

void Course::set_courseName(string cn)
{
    this->courseName=cn;
}

void Course::set_creditHours(int ch)
{
    this->creditHours=ch;
}

void Course::set_enrolledStudents(vector<Student>& eS)
{
    this->enrolledStudents=eS;
}

void Course::set_maxCapacity(int c)
{
    this->maxCapacity=c;
}

Teacher Course::get_instructor()
{
    return instructor;
}

void Course::set_instructor(Teacher instructor)
{
    this->instructor=instructor;
}

void Course::printCourseData()
{
    cout << "Course Code: " << get_courseCode() << endl;
    cout << "Course Name: " << get_courseName() << endl;
    cout << "Credit Hours: " << get_creditHours() << endl;
    cout << "Max Capacity: " << get_maxCapacity() << endl;
}

void Course::printEnrolledStudents()
{
    int totalStudents=get_enrolledStudents().size();
    for(int i=0;i<totalStudents;i++)
    {
        cout<<"Student ID is:"<<enrolledStudents[i].get_studentID()<<" and Name:"<<enrolledStudents[i].get_name()<<endl;
    }
}

void Course::enrollStudent(Student data)
{
    enrolledStudents.push_back(data);
}


