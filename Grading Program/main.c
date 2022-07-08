#include <stdio.h>
    //printf("test"); I paste this sometimes.                              
//Braxton McCormack - Lab3

int count(FILE* examFile){
    int count = 0;
    char ch;    
    if (examFile == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //4
        while ((ch = fgetc(examFile)) != EOF)
        {
            //printf("%c", ch);
            count += 1;
        }
    }

    //5
    fclose(examFile);
    return count;
}

void gradeFunction(char fileArray[],int size) {
    int i;
    int userCount = 0;
    int count = 0;
    int toggle = 0;
    char a = fileArray[0];
    int questions = a - '0';
    char key[questions-1];
    for (i = 0; i < size; i++){                                                 //pulls key out of array
        if (fileArray[i] == ' '){
            toggle = 1;
        }
        if (toggle == 1){
            key[count] = fileArray[i];
            count += 1;
 
        }
        if (fileArray[i] == '\n'){
            toggle = 0;
            break;
        }
    }
    for (i = 0; i < size; i++){                                                 //This counts the users.
        if (fileArray[i] == '\n'){
            userCount += 1;
        }
    }  
    
    float Grades[userCount-1];               
    int missedBy[questions-1];
    count = 0;
    int countTwo = 0;


    
    for (i = 10; i < size + 1; i++){                                                 //This counts the users.
        //printf("%d",i);
        //printf(" ");
        if (i > 12 && i < 21){
           //printf("%c",fileArray[i]); 
           //printf("%c",key[count+1]);
           if (fileArray[i] != key[count + 1]){
               missedBy[count] += 1;
               Grades[countTwo] += 1;
               count += 1;
               countTwo += 1;
               
           }
        }
        if (i > 25 && i < 33){
           if (fileArray[i] != key[count + 1]){
               missedBy[count] += 1;
               Grades[countTwo] += 1;
               count += 1;
               countTwo += 1;
               
           }
        }
        if (i > 37 && i < 45){
           if (fileArray[i] != key[count + 1]){
               missedBy[count] += 1;
               Grades[countTwo] += 1;
               count += 1;
               countTwo += 1;
            
           }
        } 
        if (i > 49 && i < 57){
           if (fileArray[i] != key[count + 1]){
               missedBy[count] += 1;
               Grades[countTwo] += 1;
               count += 1;
               countTwo += 1;
               
           } 
        } 
        if (i > 61 && i < 71){
           if (fileArray[i] != key[count + 1]){
               missedBy[count] += 1;
               Grades[countTwo] += 1;
               count += 1;
               countTwo += 1;
               
           }
        }
        if (count == 6){                             
            count = 0;
        }
        if (countTwo == 4){
            countTwo = 0;
        }
    } 
    
    
    //print formating below
    printf("Question        1 2 3 4 5 6 7\n");
    printf("Answer        ");
    for (i = 0; i < 8; i++){                                                 //This counts the users.
        printf("%c",key[i]); 
        printf(" ");
    }    
    printf("\n");
    printf("ID  Grade(%%) \n");
    printf("%c%c%c",fileArray[10],fileArray[11],fileArray[12]); printf(" "); printf("%.2f\n",7 / Grades[0]);
    printf("%c%c%c",fileArray[22],fileArray[23],fileArray[24]); printf(" "); printf("%.2f\n",7 / Grades[1]);    
    printf("%c%c%c",fileArray[34],fileArray[35],fileArray[36]); printf(" "); printf("%.2f\n",7 / Grades[2]);  
    printf("%c%c%c",fileArray[46],fileArray[47],fileArray[48]); printf(" "); printf("%.2f\n",7 / Grades[3]);    
    printf("%c%c%c",fileArray[58],fileArray[59],fileArray[60]); printf(" "); printf("%.2f\n",7 / Grades[4]);    

    printf("Question        1 2 3 4 5 6 7\n");
    printf("Missed by   "); printf("%d%d%d%d%d%d%d",missedBy[0],missedBy[1],missedBy[2],missedBy[3],missedBy[4],missedBy[5],missedBy[6]);
    return;
}





int main(void) 
{
    //1
    FILE* filePointer;
    char ch;
    filePointer = fopen("/public/lab3/exam.txt", "r");
    int size = count(filePointer);
    filePointer = fopen("/public/lab3/exam.txt", "r");
    char fileArray[size];
    int count = 0;
    //printf("%d",size);
    
    
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //4
        while ((ch = fgetc(filePointer)) != EOF)
        {
            fileArray[count] = ch;
            count += 1;
            //printf("%c", ch);
        }
    }

    //5
    fclose(filePointer);


    gradeFunction(fileArray,size);







    return 0;
  
    

    
    

}
