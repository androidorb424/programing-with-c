//
// Created by captl on 4/25/2022.
//

#ifndef PROGRAM2_STUDENT_H
#define PROGRAM2_STUDENT_H
#include "person.h"

class Student: public Person {  //"10 points – Employee and Student classes inherit from Person with the data attributes in Person unless they are specific to an employee or a student"
private:    //"10 points - have all your data as private in your classes (except for Person – the data will be protected so the child classes can access it)"
    vector<Student> studentVect;
    int curCredits;
public:     //getters and setters
    int getCurCredits() {
        return curCredits;
    }
    void setCurCredits(int a) {
        curCredits = a;
    }
    vector<Student> getVect() {
        return studentVect;
    }
    friend ostream& operator<<(ostream& os, Student& Stdnt);    //functions longer than two lines
    void readStudent ();
};

#endif //PROGRAM2_STUDENT_H
