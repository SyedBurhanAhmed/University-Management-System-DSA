#include <iostream>
#include "Student.h"
#include "Person.h"
#include "Teacher.h"
#include "Course.h"
#include "CourseList.h"
#include "StudentList.h"
#include "StudentQueue.h"
#include "Department.h"
#include "University.h"
#include <string>
using namespace std;

int main()
{
    University myUniversity("University of Management and Technology");

    int choice = 0;
    do
    {
        cout << "\n=============================================";
        cout << "\n|               UNIVERSITY MENU              |";
        cout << "\n=============================================";
        cout << "\n| 1. Add Department                          |";
        cout << "\n| 2. Remove Department                       |";
        cout << "\n| 3. Show Departments                        |";
        cout << "\n| 4. Admit Student                            |";
        cout << "\n| 5. Remove Student                           |";
        cout << "\n| 6. Show Students                           |";
        cout << "\n| 7. Access Departments                      |";
        cout << "\n| 0. Exit                                    |";
        cout << "\n=============================================";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        { {
            // Add Department
            string depName;
            cout << "Enter the name of the department: ";
            cin.ignore(); // Consume newline left in the buffer
            getline(cin, depName);
            Department newDepartment(depName);
            myUniversity.addDepartment(newDepartment);
            cout << "Department added successfully.\n";
            break;
        }
        case 2:
        {
            string depName;
            cout << "Enter the name of the department to remove: ";
            cin.ignore();
            getline(cin, depName);
            myUniversity.removeDepartment(depName);
            break;
        }
        case 3:
            myUniversity.displayDepartments();
            break;
        case 4:
            {
            string studentName, studentID,CNIC,phoneNum,address;
            int studentAge,Bday,Bmonth,Byear,Aday,Amonth,Ayear;
            float studentCGPA;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, studentName);
            cout << "Enter student age: ";
            cin >> studentAge;
            cout<<"Enter CNIC:";
            cin.ignore();
            getline(cin, CNIC);
            cout<<"Enter Address:";
            //cin.ignore();
            getline(cin, address);
            cout<<"Enter Date of Birth(Day,Month,Year):";
            cin>>Bday>>Bmonth>>Byear;
            cout<<"Enter Phone Number:";
            cin.ignore();
            getline(cin, phoneNum);
            cout << "Enter student ID: ";
           // //cin.ignore();
            getline(cin, studentID);
            cout << "Enter student CGPA: ";
            cin >> studentCGPA;
            cout<<"Enter Date of Admission(Day,Month,Year)";
            cin>>Aday>>Amonth>>Ayear;
            myUniversity.admitStudent(Student(studentName, studentAge,CNIC,address,date(Bday,Bmonth,Byear),phoneNum,studentID, studentCGPA,date(Aday,Amonth,Ayear)));
            cout << "Student admitted successfully.\n";
            break;
        }
        case 5:
        {
            string studentID;
            cout << "Enter student ID : ";
            cin >> ws;
            getline(cin, studentID);
            myUniversity.removeStudent(studentID);
            break;
        }
        case 6:
        {
            myUniversity.displayStudents();
            break;
        }
        case 7:
        {
            string depName;
            cout << "Enter the name of the department to access: ";
            cin.ignore();
            getline(cin, depName);
            Department *accessedDep = myUniversity.findDepartmentByName(depName);
            if (accessedDep)
            {
                int depChoice;
                do
                {
                    cout << "\n=============================================";
                    cout << "\n|               DEPARTMENT MENU              |";
                    cout << "\n=============================================";
                    cout << "\n| 1. Add Course                              |";
                    cout << "\n| 2. Remove Course                           |";
                    cout << "\n| 3. Show Courses                            |";
                    cout << "\n| 4. Show Instructors                        |";
                    cout << "\n| 5. Access Courses                          |";
                    cout << "\n| 6. Enroll Student to Course                |";
                    cout << "\n| 7. Assign Teacher to Course                |";
                    cout << "\n| 0. Exit                                    |";
                    cout << "\n=============================================";

                    cout << "\n\nEnter your choice: ";
                    cin >> depChoice;

                    switch (depChoice)
                    {
                    case 1:
                        {
                        int code,creditHour,maxCap;
                        string name;
                        cout<<"Enter course code:";
                        cin>>code;
                        cout<<"Enter course name:";
                        cin.ignore();
                        getline(cin,name);
                        cout<<"Enter credit hours:";
                        cin>>creditHour;
                        cout<<"Enter max capacity:";
                        cin>>maxCap;
                        accessedDep->addCourse(Course(code,name,creditHour,{},maxCap));
                        break;
                    }
                    case 2:
                    {
                        int code;
                        cout<<"Enter course code to remove course:";
                        cin>>code;
                        accessedDep->removeCourse(code);
                        break;
                    }
                    case 3:
                    {
                        accessedDep->displayOfferedCourses();
                        break;
                    }
                    case 4:
                    {
                     accessedDep->displayInstructors();
                        break;
                    }
                    case 5:
                    {
                        // Access Courses within the department
                        int courseChoice;
                        do
                        {
                            cout << "\n=============================================";
                            cout << "\n|               COURSES MENU                 |";
                            cout << "\n=============================================";
                            cout << "\n| 1. Show Enrolled Students                  |";
                            cout << "\n| 2. Show Instructors                        |";
                            cout << "\n| 0. Exit                                    |";
                            cout << "\n=============================================";

                            cout << "\n\nEnter your choice: ";
                            cin >> courseChoice;
                            //accessedDep->find
                            switch (courseChoice)
                            {
                            case 1:
                            {
                                string name;
                                cout<<"Enter course name to show its students:";
                                cin.ignore();
                                getline(cin,name);
                                Course* accessedCourse=accessedDep->findCourse(name);
                                accessedCourse->printEnrolledStudents();
                            }
                                break;
                            case 2:
                            {
                                string name;
                                cout<<"Enter course name to show its instructors:";
                                cin.ignore();
                                getline(cin,name);
                                Course* accessedCourse=accessedDep->findCourse(name);
                                accessedCourse->get_instructor().displayNameID();
                            }
                                break;
                            case 0:
                                cout << "Exiting Courses Menu.\n";
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                            }
                        } while (courseChoice != 0);
                        break;
                    }
                    case 6:
                        {
                        string studentId;
                        int code;
                        cout << "Enter student ID for the student to enroll: ";
                        cin.ignore();
                        getline(cin, studentId);
                        cout<<"Enter course code to enroll student in it:";
                        cin>>code;
                        accessedDep->enrollStudentInCourse(myUniversity.findStudent(studentId),code);
                        break;
                        }
                    case 7:
                        {
                        int code,empId;
                        cout << "Enter Teacher ID to assign it to the course: ";
                        cin>>empId;
                        cout<<"Enter course code assign the teacher to it: ";
                        cin>>code;
                        accessedDep->assignTeacherToCourse(accessedDep->findTeacher(empId),code);
                        }
                        break;
                    case 0:
                        cout << "Exiting Department Menu.\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }
                } while (depChoice != 0);
            }
            else
            {
                cout << "Department not found.\n";
            }
            break;
        }
            }
        case 0:
                cout << "Exiting University Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }

    } while (choice != 0);

    return 0;
}


