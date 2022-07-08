//
// Created by captl on 4/25/2022.
//

#ifndef PROGRAM2_EMPLOYEE_H
#define PROGRAM2_EMPLOYEE_H
#include "person.h"

class Employee: public Person { //"10 points – Employee and Student classes inherit from Person with the data attributes in Person unless they are specific to an employee or a student"
private:    //"10 points - have all your data as private in your classes (except for Person – the data will be protected so the child classes can access it)"
    vector<Employee> employeeVect;
    string empType;
    string dept;
public:                     //getters and setters
    string getEmpType() {
        return empType;
    }
    void setEmpType(string a) {
        empType = a;
    }
    string getDept() {
        return dept;
    }
    void setDept(string a) {
        dept = a;
    }
    vector<Employee> getVect() {
        return employeeVect;
    }
    friend ostream& operator<<(ostream& os, Employee& emp); //longer than two line functions
    void readEmployee ();
};

#endif //PROGRAM2_EMPLOYEE_H
