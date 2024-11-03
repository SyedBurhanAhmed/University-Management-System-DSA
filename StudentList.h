#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentLL.h"
#include "Student.h"
class StudentList
{
    private:
        StudentLL List;
        int maxSize;
    public:
        StudentList(int = 0);
        ~StudentList();
        StudentList(const StudentList&);
        int get_maxSize();
        void set_maxSize(int);
        StudentLL get_List();
        Student* findStudentbyName(std::string);
        Student* findStudentbyID(std::string);
        void insertAtStart(Student);
        void insertAtIndex(Student,int);
        void insertAtEnd(Student);
        void deletion(std::string);
        void printList();
        void searchList();
        void sortList();
        bool isFull();
        bool isEmpty();

};

#endif // STUDENTLIST_H
