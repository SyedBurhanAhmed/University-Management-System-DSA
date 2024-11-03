#ifndef COURSELIST_H
#define COURSELIST_H
#include "Course.h"

class courseList
{
    private:
        Course* elements;
        int usedSize;
        int maxSize;
    public:
        courseList(int=0);
        ~courseList();
        courseList(const courseList& other);
        Course* get_elements();
        int get_usedSize();
        int get_maxSize();
        void set_elements(Course*);
        void set_usedSize(int);
        void set_maxSize(int);
        void Swap(Course&,Course&);
        void sortWrtCreditHours();
        void sortWrtCourseName();
        int searchbyCourseCode(int);
        Course* findbyCourseCode(int);
        Course* findCoursebyName(std::string);
        void insertCourseAtStart(Course);
        void insertCourseAtIndex(Course,int);
        void insertCourseAtEnd(Course);
        void deleteCourse(int);
        void printCourses();
        std::vector<Course> getCourses();




};



#endif // COURSELIST_H

