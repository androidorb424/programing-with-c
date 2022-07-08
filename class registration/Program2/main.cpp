#include <vector>
#include <iostream>
#include "employee.h"   //"5 points – put each class in a separate header and source file (.cpp)(for the class methods
#include "student.h"    //that are longer than 2 lines)"
#include "univClass.h"
using namespace std;

//#################################
int findPrintName (vector<Student> studentVect,vector<Employee> employeeVect,string f,string l) {
    for (Employee i: employeeVect) {                    //parses through employeeVect
        if (i.getFname() == f && i.getLname() == l) {   //if the name is found in the employeeVect
            if (i.getEmpType() == "PT") {               //if they are part time return part time credits
                cout << i;
                return 3;
            }
            else if (i.getEmpType() == "FT") {          //if they are full time return full time credits
                cout << i;
                return 7;
            }
        }
    }
    for (Student i: studentVect) {                      //if the name is found in studentVect
        if (i.getFname() == f && i.getLname() == l) {   //this will print the student class item if it matches and return credit count
            cout << i;
            return 21;
        }
    }
    return 0;
}
//#################################
void printClassSchedule(vector<UnivClass> univVect,vector<string> choiceVect,int avlCrds) {
    int count = 0;                      //keeps track of position in choiceVect for when they run out of avlCrds
    int size = choiceVect.size();       //size of choice vect
    cout << "\nIs registered for: ";    //prints
    for (UnivClass i: univVect) {       //parses through uniVect
        if (i.getClassNumber() == choiceVect[count]) {  //when we find the class that matches
            if (avlCrds <= 0) {                         //I print it out subtract its credits,
                break;                                  //increase counter, prints the class and
            }                                           //if they run out of avlCrds it breaks
            count += 1;
            avlCrds -= i.getCredits();
            cout << i;                  //"10 points – print out the class information for the classes that the user can register for
                                        //based on available credit limits (listed above) as shown in my output above"
        }
    }
    for (int i = count; i < size; i++) {                        //"10 points – print out the names of the classes the user can’t register for based on available
        cout << "\nCould not register for " << choiceVect[i];   //credit limits as shown in my output above."
    }
}
//#################################
int main()
{
    int avlCrds;                    //initializes value for avaliable credits.
    string n;                       //initializes string for name to be pushed back for nameVect.
    string c;                       //initializes string for class number to be pushed back for choiceVector.
    vector<string> nameVect;        //stores first and last name
    vector<string> choiceVector;    //stores the user class choices
    cout << "Enter first name and last name:";  //"10 points – ask user for name and print out the user’s information from the student or employee file as shown in my output above"
                                                //it prints the info in findPrintName when it does cout << i;
    for(int i=0 ; i<2 ; i++)        //pushes input to nameVect
    {
        cin>>n;
        nameVect.push_back(n);
    }
    cout << "Enter classes to take - one line with spaces between: \n"; //"10 points – ask user for list of desired classes (to register for)"
    while(cin>>c)                   //pushes class choice to a choiceVector
    {
        choiceVector.push_back(c);
        if (cin.get() == '\n') {
            break;
        }
    }

    UnivClass univClass;        //initializes the classes
    Employee employee;
    Student student;

    univClass.readUniv();       //reads the classes
    employee.readEmployee();
    student.readStudent();
                                //finds avaliable credits, and then prints the class schedule with their allowed classes.
    avlCrds = findPrintName(student.getVect(),employee.getVect(),nameVect[0],nameVect[1]);
    printClassSchedule(univClass.getVect(),choiceVector,avlCrds);// return void

    return 0;
}