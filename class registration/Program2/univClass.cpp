#include <vector>
#include <iostream>
#include "univClass.h"

ostream&operator<<(ostream& os, UnivClass& unvCls)  //overload function
{
    os << "\n" << unvCls.getClassNumber() << " " << unvCls.getClassName() << " Taught by " << unvCls.getProfessor() << " At " << unvCls.getDateTime() << " In " << unvCls.getLocation();
    return os;
}

void UnivClass::readUniv() {    //UnivClass:: links this to the header file
//    vector<UnivClass> uniVect;
    int num;        //This is for string to int conversions.
    string fileName = "C:\\Users\\captl\\CLionProjects\\Program2\\classes.csv";
    vector<vector<string>> content;     //holds rows
    vector<string> row;                 //csv rows
    string line, word;

    fstream file (fileName, ios::in);   //reads csv file into above vectors
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
    else {      //lets me know I didn't find the file
        cout << "Could not find the file";
    }

    for (int i = 0; i < content.size(); i++) {      //parses through the vectors and makes a class with the information from each row
        UnivClass temp;
        num = stoi(content[i][9]);
        //#################
        temp.setClassNumber(content[i][0]);
        temp.setClassName(content[i][1]);
        temp.setProfessor(content[i][6]);
        temp.setDateTime(content[i][7]);
        temp.setLocation(content[i][8]);
        temp.setCredits(num);
        uniVect.push_back(temp);
    }
}