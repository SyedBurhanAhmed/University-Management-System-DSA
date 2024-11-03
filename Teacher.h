#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "date.h"
#include <vector>
class Course;

class Teacher : public Person
{
    private:
        int employeeID;
        std::vector<Course> coursesTaught;
        date DOJ;
        std::string designation;
        std::string email;
    public:
        int get_empID();
        date get_DOJ();
        std::string get_designation();
        std::string get_email();
        void set_empID(int);
        void set_DOJ(date);
        void set_designation(std::string);
        void set_email(std::string);
        Teacher(std::string="",int=0,std::string="",std::string="",date= date(),std::string="",int=0,std::vector<Course> =std::vector<Course> (),date=date(),std::string="",std::string="");
        ~Teacher();
        Teacher(const Teacher& other);
        void display() override;
        void displayNameID();


};

#endif // TEACHER_H
