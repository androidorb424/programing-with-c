#include "program.h"

int readin(ClassesStruct myArray[])
{
    FILE* inpFile = fopen("/public/pgm1/classes.csv", "r");
 
    if (inpFile == NULL)
    {
        printf("Error opening file");
    }
    
    int i = 0;
    char* delim = ",";
    char line[100];
    char *datetime;

    while(fgets(line, 100, inpFile) != NULL)
    {
        strcpy(myArray[i].classNumber, strtok(line, delim));
        strcpy(myArray[i].className, strtok(NULL, delim));
        strtok(NULL, delim);
        myArray[i].seats = atoi(strtok(NULL, delim));
        strtok(NULL, delim);
        strtok(NULL, delim);
        strcpy(myArray[i].professor, strtok(NULL, delim));
        datetime = strtok(NULL, delim);
        strcpy(myArray[i].days, strtok(datetime, " "));
        strcpy(myArray[i].time, strtok(NULL, " "));
        i++;
    }
    fclose(inpFile);
    return i;
}
