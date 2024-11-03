#include "StudentLL.h"
#include "Node.h"
#include <iostream>
#include <string>
#include "Node.cpp"
using namespace std;

StudentLL::StudentLL(Node<Student>* h):head(h)
{
    //ctor
}

StudentLL::~StudentLL()
{
    Node<Student>* ptr=head;
    while(ptr!=nullptr)
    {
    Node<Student>* next_node=ptr->get_next();
        delete ptr;
        ptr=next_node;
    }
    head=nullptr;
}

StudentLL::StudentLL(const StudentLL& other):head(other.head)
{
    //copy ctor
}


Node<Student>* StudentLL::get_head()
{
    return head;
}

void StudentLL::set_head(Node<Student>* head)
{
    this->head=head;
}

void StudentLL::insertAtStart(Student value)
{
    Node<Student>* ptr=new Node<Student>(value);
    if(head==nullptr)
    {
        head=ptr;
    }
    else{
    ptr->set_next(head);
    head->set_prev(ptr);
    head=ptr;
    }
}


void StudentLL::insertAfterIndex(Student value,int index)
{
    Node<Student>* new_ptr=new Node<Student>(value);
    if(head==nullptr)
    {
        head=new_ptr;
    }
    else{
    Node<Student>* ptr=head;
    for(int i=1;i<index&&ptr->get_next()!=nullptr;i++)
    {
        ptr=ptr->get_next();
    }

    new_ptr->set_prev(ptr);
    new_ptr->set_next(ptr->get_next());
    ptr->get_next()->set_prev(new_ptr);
    ptr->set_next(new_ptr);

    }
}


void StudentLL::insertAtEnd(Student value)
{
    Node<Student>* new_ptr=new Node<Student>(value);
    if (head==nullptr)
    {
        head=new_ptr;
    }
    else
    {
        Node<Student>* ptr=head;
        while(ptr->get_next()!=nullptr)
        {
            ptr=ptr->get_next();
        }
        new_ptr->set_prev(ptr);
        ptr->set_next(new_ptr);
    }
}

void StudentLL::deleteFromStart()
{
    if (head==nullptr)
    {
        return;
    }
    else
    {
        Node<Student>* ptr=head;
        head=head->get_next();
        head->set_prev(nullptr);
        delete ptr;
    }
}

void StudentLL::deleteFromEnd()
{
    if (head==nullptr)
    {
        return;
    }
    else
    {
        Node<Student>* ptr=head;
        Node<Student>* d_ptr=ptr->get_next();
        if(d_ptr==nullptr)
        {
            head=nullptr;
            delete head;
        }
        else
        {
            while(d_ptr->get_next()!=nullptr)
            {
                ptr=ptr->get_next();
                d_ptr=d_ptr->get_next();
            }
                ptr->set_next(nullptr);
                delete d_ptr;

        }
        }
}

void StudentLL::deleteWithGivenStudentID(string rollNum)
{
    if (head==nullptr)
    {
        cout<<"No Students."<<endl;
        return;
    }
    else
    {
        Node<Student>* ptr=head;
        Node<Student>* d_ptr=head->get_next();
        while(d_ptr->get_data().get_studentID()!=rollNum)
        {
            ptr=ptr->get_next();
            d_ptr=d_ptr->get_next();
        }
            d_ptr->get_next()->set_prev(ptr);
            ptr->set_next(d_ptr->get_next());
            delete d_ptr;

        cout<<"Student removed."<<endl;
    }
}

void StudentLL::deleteWithGivenName(string Name)
{
    for (char& c : Name) {
        c = tolower(c);
    }
    if (head==nullptr)
    {
        return;
    }
    else
    {
        Node<Student>* ptr=head;
        Node<Student>* d_ptr=head->get_next();
        while(d_ptr->get_data().get_name()!=Name)
        {
            ptr=ptr->get_next();
            d_ptr=d_ptr->get_next();
        }
        d_ptr->get_next()->set_prev(ptr);
        ptr->set_next(d_ptr->get_next());
        delete d_ptr;
    }
}

Student* StudentLL::findStudentbyName(string name)
{
    if (head==nullptr)
    {
        cout<<"Empty."<<endl;
    }
    else
    {
        Node<Student>* ptr=head;
        while(ptr!=nullptr)
        {
            if(ptr->get_data().get_name()==name)
            {
                return &ptr->get_data();
            }
            ptr=ptr->get_next();
        }
    }
    return nullptr;
}

Student* StudentLL::findStudentbyStudentID(string id)
{
    if (head==nullptr)
    {
        cout<<"Empty."<<endl;
    }
    else
    {
        Node<Student>* ptr=head;
        while(ptr!=nullptr)
        {
            if(ptr->get_data().get_studentID()==id)
            {
                return &ptr->get_data();
            }
            ptr=ptr->get_next();
        }
    }
    return nullptr;
}

int StudentLL::getCurrentSize()
{
    Node<Student>* ptr=head;
    int counter=0;
    while(ptr!=nullptr)
    {
        ptr=ptr->get_next();
        counter++;
    }
    return counter;
}

void StudentLL::Swap(Node<Student>* ptr1,Node<Student>* ptr2)
{
    Student temp;
    temp=ptr1->get_data();
    ptr1->set_data(ptr2->get_data());
    ptr2->set_data(temp);
}

void StudentLL::sortStudentsbyCGPA()
{
    int sizeOfList=getCurrentSize();
    Node<Student>* ptr1;
    Node<Student>* ptr2;
    for(int i=0;i<sizeOfList;i++)
    {
        ptr1=head;
        ptr2=head->get_next();
        for(int j=0;j<sizeOfList-1;j++)
        {
            if(ptr1->get_data().get_cgpa()>ptr2->get_data().get_cgpa())
            {
                Swap(ptr1,ptr2);
            }
            ptr1=ptr1->get_next();
            ptr2=ptr2->get_next();
        }
    }
}

void StudentLL::sortStudentsbyName()
{
    int sizeOfList=getCurrentSize();
    Node<Student>* ptr1;
    Node<Student>* ptr2;
    for(int i=0;i<sizeOfList;i++)
    {
        ptr1=head;
        ptr2=head->get_next();
        for(int j=0;j<sizeOfList-1;j++)
        {
            if(ptr1->get_data().get_name()>ptr2->get_data().get_name())
            {
                Swap(ptr1,ptr2);
            }
            ptr1=ptr1->get_next();
            ptr2=ptr2->get_next();
        }
    }
}


void StudentLL::traverseLL()
{
    if(head==nullptr)
    {
        return;
    }
    else
    {
        Node<Student>* ptr=head;
        cout<<"Students are:"<<endl;
        while(ptr!=nullptr)
        {
            ptr->get_data().displayNameID();
            ptr=ptr->get_next();

        }
    }
}

void StudentLL::detailedTraversal()
{
    if(head==nullptr)
    {
        return;
    }
    else
    {
        Node<Student>* ptr=head;
        int counter=1;
        while(ptr!=nullptr)
        {
            cout<<"Student "<<counter<<" is:"<<endl;
            ptr->get_data().display();
            ptr=ptr->get_next();
            counter++;
        }
    }
}


