#include <stdio.h>
#include <math.h>
#include <stdbool.h>


//Braxton McCormack - Lab2

int seperate(int input) { //function to seperate the big integer into individual integers and add the individual numbers
    int sum = 0;
    while (input > 0) {
        int digit = input % 10;
        sum += digit;
        input /= 10;
    }
    return(sum);
}

int divisible(int total) { //function to check if the sum of the values is divisible by 9
    int response = 3;
    if(total % 9 == 0){
        response = 1;
    }
    else{
        response = 0;
    }
    return(response);
}



int main(void) {
    int b = 1;
    int userInput;
    while (b == 1){
        printf("\nEnter an integer: ");  
    
        // reads and stores input
        scanf("%d", &userInput);
        if (userInput == 0){
            //int b = 0;
            break;
        }
        int total = seperate(userInput);
        // displays output
        if (divisible(total) == 1){
            printf("The value you entered is divsible by 9 \nBeceause the sum of the individual digits: ");
            printf("%d", total);            
            printf(" is divisible by 9.");            
        }
        else{
            printf("The value you entered isn't divsible by 9 \nBeceause the sum of the individual digits: ");
            printf("%d", total);            
            printf(" isn't divisible by 9." );            
        }
    }

     

    return(0);
}