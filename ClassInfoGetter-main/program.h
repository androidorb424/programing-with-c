#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char classNumber[10];
    char className[40];
    int seats;
    char professor[40];  
    char days[20]; 
    char time[12]; 

} ClassesStruct;

int main(void);
int readin(ClassesStruct*);
void userInputHandler(ClassesStruct*, int);
void print(ClassesStruct);
