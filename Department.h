#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include "courseList.h"
#include "Teacher.h"
#include "StudentQueue.h"

class Department
{

    private:
        std::string departmentName;
        Teacher HOD;
        courseList coursesOffered;
        StudentQueue waitlist;
        std::vector<Teacher> Instructors;
    public:
        std::string get_department();
        void set_department(std::string);
        Department(std::string="");
        ~Department();
        Department(const Department& other);
        void set_HOD(Teacher);
        Teacher get_HOD();
        void displayHOD();
        void displayWaitlist();
        void enrollStudentInCourse(Student*,int);
        void assignTeacherToCourse(Teacher*,int);
        Teacher* findTeacher(int);
        void displayStudentsInCourse(int);
        void addCourse(Course);
        void displayOfferedCourses();
        void removeCourse(int);
        Course* findCourse(std::string);
        void addInstructor(Teacher);
        void displayInstructors();
        void removeInstructor(int);

};

#endif // DEPARTMENT_H
