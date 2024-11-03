#include "University.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
University::University(string n,StudentList s,vector<Department> d):universityName(n),Students(500),departments(d)
{
    //Students.set_maxSize(50);
}

University::~University()
{
    //dtor
}

University::University(const University& other):universityName(other.universityName),Students(other.Students),departments(other.departments)
{
    //copy ctor
}

string University::get_universityName()
{
    return universityName;
}

void University::set_universityName(string universityName)
{
    this->universityName=universityName;
}

void University::addDepartment(Department& dep)
{
    departments.push_back(dep);
}

void University::displayStudents()
{
    Students.printList();
}

void University::removeDepartment(string depName)
{
    for (auto it = departments.begin(); it != departments.end(); ++it) {
        if (it->get_department() == depName) {
            departments.erase(it);
            cout << "Department '" << depName << "' removed successfully." << endl;
            return;
        }
    }

    cout << "Department '" << depName << "' not found." << endl;
}


void University::admitStudent(Student data)
{
    Students.insertAtEnd(data);
}

void University::removeStudent(string id)
{
    Students.deletion(id);
}


Department* University::findDepartmentByName(string departmentName)
{
    for (auto &department : departments)
    {
        if (department.get_department() == departmentName)
        {
            return &department;
        }
    }
    return nullptr;
}

void University::displayDepartments()
{
    cout<<"Departments are:"<<endl;
    for(int i=0;i<departments.size();i++)
    {
       cout<<"Department Name is:"<< departments[i].get_department()<<endl;
    }
}

Student* University::findStudent(string StudentId)
{
    return Students.findStudentbyID(StudentId);
}
