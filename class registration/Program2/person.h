//
// Created by captl on 4/25/2022.
//

#ifndef PROGRAM2_PERSON_H
#define PROGRAM2_PERSON_H

using namespace std;

class Person {
protected:  //"10 points - have all your data as private in your classes (except for Person – the data will be protected so the child classes can access it)"
    string fname;
    string lname;
    string id;
    int creditLimit;
public:     //getters and setters
    string getFname() {
        return fname;
    }
    void setFname(string a) {
        fname = a;
    }
    string getLname() {
        return lname;
    }
    void setLname(string a) {
        lname = a;
    }
    string getId() {
        return id;
    }
    void setId(string a) {
        id = a;
    }
    int getCreditLimit() {
        return creditLimit;
    }
    void setCreditLimit(int a) {
        creditLimit = a;
    }
};

#endif //PROGRAM2_PERSON_H
