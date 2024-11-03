#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include "Student.h"
#include "Teacher.h"


class Course
{
    private:
        int courseCode;
        std::string courseName;
        int creditHours;
        Teacher instructor;
        std::vector<Student> enrolledStudents;
        int maxCapacity;
    public:
        int get_courseCode();
        std::string get_courseName();
        int get_creditHours();
        std::vector <Student> get_enrolledStudents();
        int get_maxCapacity();
        void set_courseCode(int);
        void set_courseName(std::string);
        void set_creditHours(int);
        void set_enrolledStudents(std::vector <Student>&);
        void set_maxCapacity(int);
        Teacher get_instructor();
        void set_instructor(Teacher);
        Course(int=0,std::string="",int=0,std::vector<Student> =std::vector<Student>(),int=0);
        ~Course();
        Course(const Course&);
        void printCourseData();
        void printEnrolledStudents();
        void enrollStudent(Student);


};

#endif // COURSE_H
