#include "Person.h"
#include <iostream>
#include "date.h"

using namespace std;

Person::Person(string n,int ag,string c,string add,date d,string p):age(ag),CNIC(c),address(add),DOB(d),phone_num(p)
{
    for (char& ch : n) {
        ch = tolower(ch);
    }
    this->set_name(n);
}

Person::~Person()
{
    //dtor
}

Person::Person(const Person& other):name(other.name),age(other.age),CNIC(other.CNIC),address(other.address),DOB(other.DOB),phone_num(other.phone_num)
{
    //copy ctor
}

string Person::get_name()
{
    return name;
}

int Person::get_age()
{
    return age;
}

string Person::get_CNIC()
{
    return CNIC;
}

string Person::get_address()
{
    return address;
}

date Person::get_DOB()
{
    return DOB;
}

string Person::get_phone_num()
{
    return phone_num;
}

void Person::set_name(string name)
{
    this->name=name;
}

void Person::set_age(int age)
{
    this->age=age;
}

void Person::set_address(string address)
{
    this->address=address;
}

void Person::set_phone_num(string phone_num)
{
    this->phone_num=phone_num;
}

void Person::set_DOB(date DOB)
{
    this->DOB=DOB;
}

void Person::display()
{
    cout << "Name: " << get_name()<< endl
              << "Age: " << get_age() << endl
              << "CNIC: " << get_CNIC() << endl
              << "Address: " << get_address() << endl
              << "DOB: "; get_DOB().display_date();
    cout << "Phone Number: " << get_phone_num() << endl;
}
