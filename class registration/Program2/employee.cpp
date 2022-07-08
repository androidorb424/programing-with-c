#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "employee.h"

ostream& operator<<(ostream& os, Employee& emp)     //overload function for Employee
{
    os << "\nEmployee name: " << emp.getFname() << " " << emp.getLname() << " ID: " << emp.getId() << " Type: " << emp.getEmpType() << " Works in: " << emp.getDept();
    return os;
}

void Employee::readEmployee () {    //Employee:: allows the class to use this.
    int num;        //This is for string to int conversions.
    string fileName = "C:\\Users\\captl\\CLionProjects\\Program2\\employees.csv";   //file location
    vector<vector<string>> content;     //holds the rows
    vector<string> row;                 //rows
    string line, word;

    fstream file (fileName, ios::in);   //writes the cvs file to the above vectors for parsing
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
    else {                                      //lets me know I didn't have the correct file address
        cout << "Could not find the file";
    }

    for (int i = 0; i < content.size(); i++) {  //parses through the vectors and adds the relevant
        Employee temp;                          //information to a class of the correct type for each row.
        num = 7;    //default to full time credits.
        if (content[i][3] == "PT"){
            num = 3;
        }
        //#################
        temp.setLname(content[i][0]);
        temp.setFname(content[i][1]);
        temp.setId(content[i][2]);
        temp.setEmpType(content[i][3]);
        temp.setDept(content[i][4]);
        temp.setCreditLimit(num);
        employeeVect.push_back(temp);
    }
}