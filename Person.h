#ifndef PERSON_H
#define PERSON_H
#include "date.h"

class Person
{
    private:
        std::string name;
        int age;
        std::string CNIC;
        std::string address;
        date DOB;
        std::string phone_num;
    public:
        std::string get_name();
        int get_age();
        std::string get_CNIC();
        std::string get_address();
        date get_DOB();
        std::string get_phone_num();
        void set_name(std::string);
        void set_age(int);
        void set_CNIC(std::string);
        void set_address(std::string);
        void set_DOB(date);
        void set_phone_num(std::string);
        Person(std::string = "",int = 0,std::string = "",std::string = "",date = date(),std::string = "");
        ~Person();
        Person(const Person& other);
        virtual void display();


};

#endif // PERSON_H
