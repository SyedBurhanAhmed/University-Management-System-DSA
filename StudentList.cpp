#include "StudentList.h"
#include <iostream>
#include <string>

using namespace std;

StudentList::StudentList(int m):maxSize(m)
{
    //ctor
}

StudentList::~StudentList()
{
    //dtor
}

StudentList::StudentList(const StudentList& other):List(other.List),maxSize(other.maxSize)
{

}
StudentLL StudentList::get_List()
{
    return List;
}

int StudentList::get_maxSize()
{
    return maxSize;
}

void StudentList::set_maxSize(int maxSize)
{
    this->maxSize=maxSize;
}
void StudentList::insertAtStart(Student data)
{
    List.insertAtStart(data);
}

void StudentList::insertAtIndex(Student data,int index)
{
    if(List.getCurrentSize()>=get_maxSize())
    {
        cout<<"Max capacity full."<<endl;
    }
    else{
        if(index<get_maxSize())
        {
            List.insertAfterIndex(data,index);
        }


    }
}

void StudentList::insertAtEnd(Student data)
{
    List.insertAtEnd(data);
}

void StudentList::printList()
{
    if(List.getCurrentSize()==0)
    {
        cout<<"No Students found."<<endl;
    }
    else{
        int choice;
        cout<<"1.Students' Names and IDs"<<endl;
        cout<<"2.Students' full detail"<<endl;
        while(true)
        {
            cout<<"Enter your choice:";
            cin>>choice;
            if(choice==1)
            {
                cout<<"List of Students :"<<endl;
                List.traverseLL();
                break;
            }
            else if(choice==2)
            {
                cout<<"List of Students :"<<endl;
                List.detailedTraversal();
                break;
            }
            else
            {
                cout<<"Invalid Choice\n\n"<<endl;
            }
            }
        }
}

void StudentList::deletion(string id)
{
    if(List.getCurrentSize()==0)
    {
        cout<<"No students, cannot delete."<<endl;
    }
    else{
        List.deleteWithGivenStudentID(id);
    }

}


void StudentList::searchList()
{
    if(List.getCurrentSize()==0)
    {
        cout<<"No students."<<endl;
    }
    else
    {
        int choice;
        string name,id;
        cout<<"1.Find Student with Student ID."<<endl;
        cout<<"2.Find Student with Name."<<endl;

        while(true)
        {
            cout<<"Enter your choice:";
            cin>>choice;
            if(choice==1)
            {
                cout<<"Enter Student ID:";
                cin.ignore();
                getline(cin,id);
                if(List.findStudentbyStudentID(id))
                {
                    cout<<"Student with id "<<id<<" found."<<endl;
                }
                else{
                    cout<<"Student with id "<<id<<" not found."<<endl;
                    }
                break;
                break;
            }
            else if(choice==2)
            {
                cout<<"Enter Student Name:";
                cin.ignore();
                getline(cin,name);
                if(List.findStudentbyName(name))
                {
                    cout<<"Student with name "<<name<<" found."<<endl;
                }
                else{
                    cout<<"Student with name "<<name<<" not found."<<endl;
                    }
                break;
            }
            else
            {
                cout<<"Invalid Choice\n\n"<<endl;
            }
            }
}
}

Student* StudentList::findStudentbyID(string StudentId)
{
    return List.findStudentbyStudentID(StudentId);
}

void StudentList::sortList()
{
    if(List.getCurrentSize()==0)
    {
        cout<<"No students, cannot sort."<<endl;
    }
    else{
        int choice;
        cout<<"1.Sort wrt CGPA."<<endl;
        cout<<"2.Sort wrt Names."<<endl;

        while(true)
        {
            cout<<"Enter your choice:";
            cin>>choice;
            if(choice==1)
            {
                List.sortStudentsbyCGPA();
                break;
            }
            else if(choice==2)
            {
                List.sortStudentsbyName();
                break;
            }
            else
            {
                cout<<"Invalid Choice\n\n"<<endl;
            }
            }
        }
}

bool StudentList::isEmpty()
{
    return (List.getCurrentSize()==0);
}

bool StudentList::isFull()
{
    return (!isEmpty()&&List.getCurrentSize()>=get_maxSize());
}
