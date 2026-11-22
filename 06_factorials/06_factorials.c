#include <stdio.h>

//Declare Functions. 'long long' to ensure 64 bit precision
long long int factorial(int num);
long long int recursivefactorial(int num);

int main() {
    long long int num;
    char rerun = 'y';

    //wrap in a while loop to ensure multiple attempts if needed
    while(rerun == 'y' || rerun == 'Y') {
        printf("=======================\n");
        printf("[Factorial Calculator]!\n");
        printf("=======================\n");
        printf("\n");
    
        printf("Enter Number: ");
        //Check for non-numerical inputs
        while(scanf(" %lld", &num) != 1) {   //'ll' = long long
            printf("Invalid Input, Try again: ");
            while (getchar() != '\n');
        } 
        printf("\n");

        
        
        if (num == 0) {
            printf("Result: 1\n"); //0! = 1
        } else if (num < 0) {
            printf("Result: Cant be computed for negative integers."); //-x! does not exist
        } else if (num > 20) {
            printf("Try a smaller number! Limit: 20;\n\n"); // 21! exceeds the 64 bit limit
        } else {
            printf("------------------\n");
            printf("Result:\n");
            printf("%lld [Non-Recursive]", factorial(num));
            printf("\n");
            printf("%lld [Recursive]\n", recursivefactorial(num));
            printf("------------------\n");
        }

        printf("Enter Y to rerun: ");
        scanf(" %c", &rerun);

        printf("\n\n");
    }

    printf("----------------------\n");
    printf("| Program Terminated |\n");
    printf("----------------------\n");


}

//Custom Function 1
//Calculates the factorial in a non-recursive manner.
long long int factorial(int num) {
    long long int result = 1;
    
    for(int i = num; i > 1; i-- ) {
        result = result * i;
    }

    return result;
}

//Custom Function 2
//Calculates factorial in a recursive manner by calling itself
long long int recursivefactorial(int num) {
    if(num != 1) {
        return num * recursivefactorial(num - 1);
    } else if(num == 1) {
        return num;
    }
}

