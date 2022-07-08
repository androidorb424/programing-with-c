#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "student.h"

ostream& operator<<(ostream& os, Student& Stdnt) //overload function for Student
{
    os << "\nStuden name: " << Stdnt.getFname() << " " << Stdnt.getLname() << " ID: " << Stdnt.getId() << " Current credits: " << Stdnt.getCurCredits();
    return os;
}

void Student::readStudent () {  //Student:: allows the class to use this.
    int num;        //This is for string to int conversions.
    string fileName = "C:\\Users\\captl\\CLionProjects\\Program2\\students.csv";    //file location
    vector<vector<string>> content;     //holds rows
    vector<string> row;                 //each row of csv file
    string line, word;

    fstream file (fileName, ios::in);   //reads csv file to above vectors
    if(file.is_open()) {
        while(getline(file,line)) {
            row.clear();
            stringstream str(line);
            while(getline(str,word,',')) {
                row.push_back(word);
            }
            content.push_back(row); //remove
        }
    }
    else {      //lets me know I didn't have correct address
        cout << "Could not find the file";
    }

    for (int i = 0; i < content.size(); i++) {      //parses through above vectors and adds correct information to the Class
        Student temp;
        num = stoi(content[i][3]);    //default to full time credits.
        //#################
        temp.setLname(content[i][0]);
        temp.setFname(content[i][1]);
        temp.setId(content[i][2]);
        temp.setCurCredits(num);
        temp.setCreditLimit(21);
        studentVect.push_back(temp);
    }
}