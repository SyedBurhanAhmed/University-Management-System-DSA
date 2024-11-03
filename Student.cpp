#include "Student.h"
#include "Person.h"
#include "date.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Student::Student(string n,int ag,string c,string add,date d,string p,string id,float gpa,date AD):Person(n,ag,c,add,d,p),studentID(id),cgpa(gpa),DOA(AD)
{
    //this->set_studentID(id);
}

Student::~Student()
{
    //dtor
}

Student::Student(const Student& other):Person(other),studentID(other.studentID),cgpa(other.cgpa),DOA(other.DOA)

{
    //copy ctor
}

string Student::get_studentID()
{
    return studentID;
}

float Student::get_cgpa()
{
    return cgpa;
}

date Student::get_DOA()
{
    return DOA;
}

void Student::set_studentID(string studentID)
{
    this->studentID=studentID;
}

void Student::set_cgpa(float cgpa)
{
    this->cgpa=cgpa;
}


void Student::set_DOA(date DOA)
{
    this->DOA=DOA;
}

void Student::display()
{
    Person::display();
    cout<<"Student's ID:"<<this->get_studentID()<<endl;
    cout<<"Student's CGPA:"<<this->get_cgpa()<<endl;
    cout<<"Student's Date of Admission:";this->get_DOA().display_date();
}

void Student::displayNameID()
{
    cout<<"Student's ID:"<<this->get_studentID()<<endl;
    cout<<"Student's Name:"<<this->get_name()<<endl;
}



