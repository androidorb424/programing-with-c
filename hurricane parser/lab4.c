#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Braxton McCormack
//Lab 4

FILE *output; //output file
FILE *input; //input file
//*******************
int read(char* list[]) {                  //this function reads in list while alloticating memory and returns hurricane count
    input = fopen("/public/lab4/hurricanes.csv", "r");
    if (input == NULL) {                //if there is a problem getting the file this will print. probally wrong directory problem
        printf("Unable to open file. Check file directory.");
        exit(0);
    }
    int i = 0;
    do {
        list[i] = malloc(sizeof(char) * 100);
    } while (fgets(list[i++], 100, input) != NULL);
    --i;
    fclose(input);    
    return i;
}
//*******************
void listSort(char* list[], int size) {      //alphabetically orders the list
    char *temp;                             
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (strcmp(list[i], list[j]) > 0) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    return;
}
//*******************
void listPrint(char* list[], int size) {     //this function formats the output so it looks nice and matches the requirements
    output = fopen("output.txt", "w"); 
    fprintf(output, "Hurricanes in Florida with category and date \n"); 
    char *token; 
    for (int i = 0; i < size; i++) {        //uses strtok to break the strings into char *token
        token = strtok(list[i], ",");
        fprintf(output, "%-10s", token);
        token = strtok(NULL, ",");
        fprintf(output, "%c   ", token[9]);
        token = strtok(NULL, ",");
        fprintf(output, "%s ", token);
        token = strtok(NULL, ",");        
        fprintf(output, "%s", token);
    }
    fclose(output);
    return;
}
//*******************
int main(void) {
    char *hurricaneArray[100];  
    int size = 0;
    size = read(hurricaneArray);
    listSort(hurricaneArray, size);
    listPrint(hurricaneArray, size);
    return(0);
}