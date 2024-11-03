#include "Teacher.h"
#include "Person.h"
#include "date.h"
#include "Course.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;



Teacher::Teacher(string n,int ag,string c,string add,date d,
                 string p,int id,vector<Course> cT,date jd,string des,string e):Person(n,ag,c,add,d,p),employeeID(id),coursesTaught(cT),DOJ(jd),designation(des),email(e)
{
    //ctor
}

Teacher::~Teacher()
{
    //dtor
}

Teacher::Teacher(const Teacher& other):Person(other),employeeID(other.employeeID),DOJ(other.DOJ),designation(other.designation),email(other.email)
{
    //copy ctor
}

int Teacher::get_empID()
{
    return employeeID;
}

date Teacher::get_DOJ()
{
    return DOJ;
}

string Teacher::get_designation()
{
    return designation;
}

string Teacher::get_email()
{
    return email;
}

void Teacher::set_empID(int employeeID)
{
    this->employeeID=employeeID;
}

void Teacher::set_DOJ(date DOJ)
{
    this->DOJ=DOJ;
}

void Teacher::set_designation(string designation)
{
    this->designation=designation;
}

void Teacher::set_email(string email)
{
    this->email=email;
}

void Teacher::display()
{
    Person::display();
    cout<<"Teacher's Employee ID:"<<get_empID()<<endl;
    cout<<"Teacher's Date of Joining:";get_DOJ().display_date();
    cout<<"Teacher's Designation:"<<get_designation()<<endl;
    cout<<"Teacher's Email:"<<get_email()<<endl;
    for(int i=0;i<coursesTaught.size();i++)
    {
        coursesTaught[i].printCourseData();
    }
}

void Teacher::displayNameID()
{
    cout<<"Teacher's Name:"<<get_name()<<endl;
    cout<<"Teacher's Employee ID:"<<get_empID()<<endl;
}
