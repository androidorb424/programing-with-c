#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>
#include <string.h>
#include "term.h"
using namespace std;

class Polynomial {
public:
    vector<Term> vect;                  //input vector
    vector<Term> ovect;                 //output vector
    void read() {
        fstream file;                   // filestream variable file
        string word, t, q, filename;
        filename = "input.txt";         // filename of the file
        file.open(filename.c_str());    // opening file
        while (file >> word)            // extracting words from the file
        {
            Term term;                  //makes a Term called term every loop to be added to the vector
            if (word != "+") {          //this makes us ignore the '+'
                int n = word.length();  //here and below I convert to a char array first                            
                char char_array[n + 1]; // declaring character array
                strcpy(char_array, word.c_str());       // copying the contents of the string to char array
                if (n == 3) {                           // if the term is size 3
                    int hld = char_array[0] - '0';
                    int hldr = char_array[2] - '0';
                    term.coefficient = hld;             
                    term.exponent =  hldr;
                }
                if (n == 1) {                           //if it is one digit  
                    int hld = char_array[0] - '0';
                    term.coefficient = hld;
                    //cout << hld << "coefficient \n";
                }
                else if (n == 2){                       //2digit x in first positon
                    if (char_array[0] == 'x') {                 
                        int hld = char_array[1] - '0';
                        term.exponent = hld;
                        //cout << hld << "exponent \n";
                    }
                    else {                              //2 digit x in second positon
                        int hld = char_array[0] - '0';
                        term.coefficient = hld;
                        term.exponent = 1;
                        //cout << hld << "coefficient \n";
                    }
                }
                //cout << n << "\n";
                vect.push_back(term);
                //term.print();
            }
        }        
    }
    void simplify(){
        Term oterm;                                 //output term
        int likeTerms[vect.size()];                      //array for holding like terms
        for (int i = 0; i < 10; i++){               //this stops at ten beceause for this project I did not find any examples of exponents larger than 10 in the examples.
            for(int j = 0; j < vect.size(); j++){   //loops through vecter finding like exponents for addition
               //vect[i].print();
               if (vect[j].exponent == i){
                   likeTerms[i] += vect[j].coefficient;
               }
            }
        }
        for(int j = vect.size() -1 ; j >= 0; j--){
            if (likeTerms[j] < 100) {
                oterm.exponent = j;
                oterm.coefficient = likeTerms[j];
                ovect.push_back(oterm);
            }
        }
        cout << "output: ";
        for (int i = 0; i < ovect.size(); i++) {
            ovect[i].print();
        }
    }
};



#endif