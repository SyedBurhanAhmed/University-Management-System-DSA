#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
#include "Department.h"
#include "StudentList.h"
class University
{
    private:
        std::string universityName;
        StudentList Students;
        std::vector<Department> departments;
    protected:
    public:
        std::string get_universityName();
        void set_universityName(std::string);
        University(std::string="",StudentList=StudentList(),std::vector<Department> =std::vector<Department>());
        ~University();
        University(const University& other);
        Department* findDepartmentByName(std::string);
        void displayDepartments();
        void addDepartment(Department&);
        void removeDepartment(std::string);
        void admitStudent(Student);
        void removeStudent(std::string);
        void displayStudents();
        Student* findStudent(std::string);


};

#endif // UNIVERSITY_H
