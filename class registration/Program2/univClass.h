//
// Created by captl on 4/25/2022.
//

#ifndef PROGRAM2_UNIVCLASS_H
#define PROGRAM2_UNIVCLASS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "employee.h"
#include "student.h"
#include "person.h"

class UnivClass {

private:    //"10 points - have all your data as private in your classes (except for Person – the data will be protected so the child classes can access it)"
    vector<UnivClass> uniVect;
    int credits;        //this x
    string classNumber; //this x
    string className;   //this x
    string professor;   //this x
    string dateTime;    //this x
    string location;    //this x
public:     //getters and setters
    int getCredits() {
        return credits;
    }
    void setCredits(int a) {
        credits = a;
    }
    string getClassNumber() {
        return classNumber;
    }
    void setClassNumber(string a) {
        classNumber = a;
    }
    string getClassName() {
        return className;
    }
    void setClassName(string a) {
        className = a;
    }
    string getProfessor() {
        return professor;
    }
    void setProfessor(string a) {
        professor = a;
    }
    string getDateTime() {
        return dateTime;
    }
    void setDateTime(string a) {
        dateTime = a;
    }
    string getLocation() {
        return location;
    }
    void setLocation(string a) {
        location = a;
    }
    vector<UnivClass> getVect() {
        return uniVect;
    }
    void readUniv();        //functions longer than two lines.
    friend ostream& operator<<(ostream& os, UnivClass& unvCls);
};








#endif //PROGRAM2_UNIVCLASS_H
