#ifndef STUDENT_H
#define STUDENT_H
#include "date.h"
#include "Person.h"
#include <string>
class Student : public Person
{
    private:
        std::string studentID;
        float cgpa;
        date DOA;
    public:
        std::string get_studentID();
        float get_cgpa();
        date get_DOA();
        void set_studentID(std::string);
        void set_cgpa(float);
        void set_DOA(date);
        Student(std::string="",int=0,std::string="",std::string="",date= date(),std::string="",std::string="",float=0.0,date=date() );
        ~Student();
        Student(const Student& other);
        void display() override;
        void displayNameID();


};

    #endif // STUDENT_H
