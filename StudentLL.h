#ifndef STUDENTLL_H
#define STUDENTLL_H
#include "Node.h"
#include "Student.h"
#include <string>
class StudentLL
{
    private:
        Node<Student>* head;
    public:
        Node<Student>* get_head();
        void set_head(Node<Student>*);
        StudentLL(Node<Student>* =nullptr);
        ~StudentLL();
        StudentLL(const StudentLL& other);
        void insertAtStart(Student data);
        void insertAfterIndex(Student data,int);
        void insertAtEnd(Student data);
        void deleteFromStart();
        void deleteFromEnd();
        void deleteWithGivenStudentID(std::string);
        void deleteWithGivenName(std::string);
        Student* findStudentbyName(std::string);
        Student* findStudentbyStudentID(std::string);
        int getCurrentSize();
        void sortStudentsbyCGPA();
        void sortStudentsbyName();
        void Swap(Node<Student>*,Node<Student>*);
        void traverseLL();
        void detailedTraversal();

};


#endif // STUDENTLL_H
