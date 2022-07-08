#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

#include "poly.h"
#include "term.h"

int main(void) {
    Polynomial polynomial;
    
    polynomial.read();
    
    polynomial.simplify();

    return(0);
}