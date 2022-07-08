#ifndef TERM_H
#define TERM_H

using namespace std;

class Term {
public:
    int coefficient = 1;        //I made these 1 and 0 so 3 can be interpreted as 3x^0 
    int exponent = 0;           //and x^4 can be interpreted as 1x^4
    void print() {
        if (exponent == 0) {                    //formating rule for variable polynomial formats. 
            cout << coefficient << " ";         //examples above.
        }
        else if (exponent == 1) {
            cout << coefficient << "x" << " ";
        }
        else if (coefficient == 1) {
            cout << "x" << exponent << " ";
        }
        else {
            cout << coefficient << "x" << exponent << " ";
        }
    }
};

#endif