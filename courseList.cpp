#include "courseList.h"
#include <iostream>
#include "Course.h"
using namespace std;
#include <vector>

courseList::courseList(int m):maxSize(m),usedSize(0)
{
    elements=new Course[maxSize];
}


courseList::~courseList()
{
    //dtor
}


courseList::courseList(const courseList& other):elements(other.elements),usedSize(other.usedSize),maxSize(other.maxSize)
{
    //copy ctor
}


Course* courseList::get_elements()
{
     return elements;
}


void courseList::set_elements(Course* e)
{
     this->elements=e;;
}


int courseList::get_usedSize()
{
    return usedSize;
}


void courseList::set_usedSize(int u)
{
     this->usedSize=u;
}


int courseList::get_maxSize()
{
    return maxSize;
}


void courseList::set_maxSize(int m)
{
     this->maxSize=m;
}

void courseList::Swap(Course& c1,Course& c2)
{
    Course temp=c1;
    c1=c2;
    c2=temp;
}
void courseList::sortWrtCreditHours()
{
    int sizeOfArray=this->get_usedSize();
    for(int i=0;i<sizeOfArray-1;i++)
    {
        for(int j=0;j<sizeOfArray-i-1;j++)
        {
        if(elements[j].get_creditHours()>elements[j+1].get_creditHours())
        {
            Swap(elements[j],elements[j+1]);
        }
        }
    }

}

void courseList::sortWrtCourseName()
{
    int sizeOfArray=this->get_usedSize();
    for(int i=0;i<sizeOfArray-1;i++)
    {
        for(int j=0;j<sizeOfArray-i-1;j++)
        {
        if(elements[j].get_courseName()>elements[j+1].get_courseName())
        {
            Swap(elements[j],elements[j+1]);
        }
        }
    }

}

int courseList::searchbyCourseCode(int code)
{
    int sizeOfArray=this->get_usedSize();
    for(int i=0;i<sizeOfArray;i++)
    {
    if(code==elements[i].get_courseCode())
    {
        return i;
    }
    }
    return -1;
}

Course* courseList::findbyCourseCode(int code)
{
    int sizeOfArray=this->get_usedSize();
    for(int i=0;i<sizeOfArray;i++)
    {
    if(code==elements[i].get_courseCode())
    {
        return &elements[i];
    }
    }
    return nullptr;
}

Course* courseList::findCoursebyName(string name)
{
    int sizeOfArray=this->get_usedSize();
    for(int i=0;i<sizeOfArray;i++)
    {
    if(name==elements[i].get_courseName())
    {
        return &elements[i];
    }
    }
    return nullptr;
}
void courseList::insertCourseAtStart(Course data)
{
    int sizeOfArray=get_usedSize();

    for(int i=sizeOfArray;i>0;i--)
    {
        elements[i]=elements[i-1];
    }
    elements[0]=data;
    set_usedSize(get_usedSize()+1);
}

void courseList::insertCourseAtIndex(Course data,int index)
{
    int sizeOfArray=get_usedSize();
    if(index>sizeOfArray)
    {
        cout<<"Invalid Index."<<endl;
    }
    else
    {
    for (int i = sizeOfArray; i > index; i--)
        {
            elements[i] = elements[i - 1];
        }
        elements[index] = data;
        set_usedSize(get_usedSize() + 1);
    }
    }

void courseList::insertCourseAtEnd(Course data)
{
    int sizeOfArray=get_usedSize();
    elements[sizeOfArray] = data;
    set_usedSize(get_usedSize() + 1);

}


void courseList::deleteCourse(int index)
{
    int sizeOfArray=get_usedSize();
    if(index>sizeOfArray)
    {
        cout<<"Invalid Index."<<endl;
    }
    else
    {
        for(int i=index;i<sizeOfArray;i++)
        {
            elements[i]=elements[i+1];
        }
        set_usedSize(get_usedSize()-1);
    }
}

void courseList::printCourses()
{
    int sizeOfArray=get_usedSize();
    for(int i=0;i<sizeOfArray;i++)
    {
        elements[i].printCourseData();
    }
}

vector<Course> courseList::getCourses()
{
    vector<Course> courseVector;
    int sizeOfArray = get_usedSize();
    for (int i = 0; i < sizeOfArray; i++)
    {
        courseVector.push_back(elements[i]);
    }
    return courseVector;
}

