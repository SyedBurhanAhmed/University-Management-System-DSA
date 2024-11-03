#include "StudentQueue.h"
#include <iostream>
#include <string>

using namespace std;

StudentQueue::StudentQueue(int s):maxSize(s)
{
    //ctor
}

StudentQueue::~StudentQueue()
{
    //dtor
}

StudentQueue::StudentQueue(const StudentQueue& other):maxSize(other.maxSize)
{
    //copy ctor
}

int StudentQueue::get_maxSize(){

    return maxSize;

}


void StudentQueue::set_maxSize(int maxSize)
{
    this->maxSize=maxSize;
}


bool StudentQueue::isEmpty()
{
    return (front.getCurrentSize()==0);
}

bool StudentQueue::isFull()
{
    return (!isEmpty()&&front.getCurrentSize()>=get_maxSize());
}

void StudentQueue::enqueue(Student value)
{
    if(isFull())
    {
        cout<<"Cannot enqueue, capacity full."<<endl;
    }
    else{
        front.insertAtEnd(value);
    }
}

void StudentQueue::dequeue()
{
    if(isEmpty())
    {
        cout<<"Cannot dequeue, no Student in Queue.."<<endl;
    }
    else
    {
        front.deleteFromStart();
    }
}

void StudentQueue::peek()
{
    if(isEmpty())
    {
        cout<<"Cannot peek, no Student in Queue."<<endl;
    }
    else
    {
        cout<<"Top of Queue is:";front.get_head()->get_data().displayNameID();

    }
}

void StudentQueue::printQueue()
{
    if(isEmpty())
    {
        cout<<"Cannot display, no students present"<<endl;
    }
    else
    {
        cout<<"Students in Queue are:"<<endl;
        front.traverseLL();
    }

}

void StudentQueue::searchQueue()
{
    if(isEmpty())
    {
        cout<<"Cannot search, no students present."<<endl;
    }
    else{
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
                if(front.findStudentbyStudentID(id))
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
                if(front.findStudentbyName(name))
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


