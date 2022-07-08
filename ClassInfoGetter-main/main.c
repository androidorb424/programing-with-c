#include <stdio.h>
#include <stdlib.h>
#include "program.h"

int main()
{
    int numClasses;                             //initializes a int for class numbers
    ClassesStruct classes[30];                  //Creates "array of structs that stores all the data for the classes"
    numClasses = readin(classes);               //reads in class data and passes struct array
    userInputHandler(classes, numClasses);      //passes struct array and number of classes to choice
    return(0);                                  //retursn
}
