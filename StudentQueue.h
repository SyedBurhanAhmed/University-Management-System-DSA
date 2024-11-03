#ifndef STUDENTQUEUE_H
#define STUDENTQUEUE_H
#include "Student.h"
#include "StudentLL.h"

class StudentQueue
{
    private:
        StudentLL front;
        int maxSize;
    public:
        StudentQueue(int = 0);
        ~StudentQueue();
        StudentQueue(const StudentQueue& other);
        int get_maxSize();
        void set_maxSize(int);
        void enqueue(Student);
        void dequeue();
        void peek();
        bool isFull();
        bool isEmpty();
        void printQueue();
        void searchQueue();

};

#endif // STUDENTQUEUE_H
