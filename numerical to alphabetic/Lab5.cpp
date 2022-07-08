#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;
//Braxton McCormack

void error(string s)                                //function to assist errors
{ 
    throw runtime_error("Error: " + s);
}

vector<string> buildVector(int num)                 //" function (not main) that will build the vector of words"
{          
    vector<string> vectorOne = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> vectorTwo = {"", "no", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    vector<string> vectorThree = {"", "", "", "hundred", "thousand"};
    vector<string> returnVector; 

    int digits = (int)log10(double(num)) + 1;   //gets the number of digits
   
    for (int i = 1; i <= digits; ++i)           //loops throught the input
    { 
        int digit = num % 10;
        num /= 10;
        
        if (i != 2) 
        {
            returnVector.push_back(vectorThree[i]);
            returnVector.push_back(vectorOne[digit]);
        }
        else 
        {
            returnVector.push_back(vectorTwo[digit]);
        } 
    } 
    return returnVector;
}

int main(int a, char** b) 
{

    if (a != 2)                              //if no input
    {                            
        error("Number not on command line.");
    }

    if (b[1][0] == '1')                      //"f the number in the tens place is one,print an error."
    {                    
        error("Second digit cannot be 1.");
    } 
    
    int input = atoi(b[1]);    
    vector<string> myVector = buildVector(input);
    cout << "Number " << input << " is written as ";
    while (!myVector.empty())                   //loops through vector to print
    { 
        cout << myVector.back() << " ";
        myVector.pop_back();
    }    
    return 0;
}