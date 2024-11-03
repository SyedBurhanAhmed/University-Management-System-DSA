#include "Department.h"
#include <string>
#include <iostream>

using namespace std;

Department::Department(string d):departmentName(d),coursesOffered(10)
{
    //ctor
}

Department::~Department()
{
    //dtor
}

Department::Department(const Department& other):departmentName(other.departmentName)
{
    //copy ctor
}

string Department::get_department()
{
    return departmentName;
}

void Department::set_department(string departmentName)
{
    this->departmentName=departmentName;
}

void Department::displayHOD()
{
    cout<<"HOD of "<<get_department()<<":"<<endl;
    HOD.displayNameID();
}

void Department::displayOfferedCourses()
{
    cout<<"Courses Offered in "<<get_department()<<" are:"<<endl;
    coursesOffered.printCourses();
}

void Department::displayInstructors()
{
    cout<<"Instructors of  "<<get_department()<<" are:"<<endl;
    for(int i=0;i<Instructors.size();i++)
    {
        Instructors[i].displayNameID();
    }
}

void Department::enrollStudentInCourse(Student* data,int code)
{
    coursesOffered.findbyCourseCode(code)->enrollStudent(*data);
    cout << "Student " << data->get_name() << " enrolled in course  " <<coursesOffered.findbyCourseCode(code)->get_courseName() <<endl;

}

void Department::assignTeacherToCourse(Teacher* data,int code)
{
    coursesOffered.findbyCourseCode(code)->set_instructor(*data);
    cout << "Teacher " << data->get_name() << " assigned to course " << coursesOffered.findbyCourseCode(code)->get_courseName() <<endl;

}


void Department::displayStudentsInCourse(int code)
{
    coursesOffered.findbyCourseCode(code)->printEnrolledStudents();
}


void Department::set_HOD(Teacher HOD)
{
    this->HOD=HOD;
}

Teacher Department::get_HOD()
{
    return HOD;
}

void Department::addInstructor(Teacher teachr)
{
    Instructors.push_back(teachr);
}

void Department::addCourse(Course data)
{
    coursesOffered.insertCourseAtEnd(data);
}

Course* Department::findCourse(string name)
{
    return coursesOffered.findCoursebyName(name);
}

void Department::removeCourse(int code)
{
    coursesOffered.deleteCourse(code);
}

Teacher* Department::findTeacher(int id)
{
    for (auto &Teacher : Instructors)
    {
        if (Teacher.get_empID() == id)
        {
            return &Teacher;
        }
    }
    return nullptr;
}
