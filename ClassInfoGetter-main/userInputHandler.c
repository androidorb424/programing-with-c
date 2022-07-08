#include "program.h"

void userInputHandler(ClassesStruct myArray[], int num)
{
    char userInput;
    char nl;
    char input[70];
    
    while(userInput != 'q')
    {
        printf("Choices: \n");
        printf("n - print class given number \n");
        printf("d - print all classes for a given day combo \n");
        printf("p - print all classes for a given professor \n");
        printf("q - quit \n");
        scanf(" %c%c", &userInput, &nl);
    
        if (userInput == 'n')
        {
            printf("Enter class number: ");
            scanf("%[^\n]", input);
            for (int i = 0; i < num; i++)
            {
                if (strncmp(myArray[i].classNumber, input, strlen(input)) == 0)
                {
                    print(myArray[i]);
                }

            }
        }
        
        else if (userInput == 'd')
        {
            printf("Enter class days to print (MWF or TR): ");
            scanf("%s", input);
            printf("List of classes for %s: \n", input);
            for (int i = 0; i < num; i++)
            {
                if (strncmp(myArray[i].days, input, 3) == 0)
                {
                    print(myArray[i]);
                }
            }
        }

        else if(userInput == 'p')
        {
            printf("Enter Professor's Last Name: ");
            scanf("%s", input);
            printf("List of classes for Professor %s: \n", input);
            for (int i = 0; i < num; i++)
            {
                if (strncmp(myArray[i].professor, input, strlen(input)) == 0)
                {
                    print(myArray[i]);
                }
        
            }
            
        }
    }

    return;
}
