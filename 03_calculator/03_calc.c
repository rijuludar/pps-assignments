#include <stdio.h>

int main() {
    float num1, num2, result;
    char operand, rerun;
    
    printf("Calculator\n\n");
    
    printf("Enter 1st number: ");

    while (scanf("%f", &num1) != 1) {
        while ( getchar() != '\n' );
        printf("Invalid Input, try again: ");
    }
    
    	  
    printf("Enter Operand (+, -, *, /) : ");
    scanf(" %c", &operand);
    
    printf("Enter 2nd number: ");
    
    while (scanf("%f", &num2) != 1) {
        while ( getchar() != '\n' );
        printf("Invalid Input, try again: ");
    }
    
    //carry out operation as per entered operand
    switch (operand) {
        case '+':
            result = num1 + num2;
            printf("%f + %f = %g", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%f - %f = %g", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%f * %f = %g", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) { //prevent division by 0
                printf("Cannot Divide By 0, please try again.");
                break;
                
            }else {
                result = num1 / num2;
                printf("%g / %g = %g", num1, num2, result);
                break;
            }
        default:
            printf("Invalid Operand Entered!");

    }
    
    printf("\n\nInput 'Y' to Run Again: ");
    scanf(" %c", &rerun);
        
    //ask user if they want to perform another operation
    switch (rerun) {
        case 'Y':
        case 'y':
            printf("\n\n");
            main();
            break;
        default:
            printf("\n----------------------\n");
            printf("| Program Terminated |\n");
            printf("----------------------\n");
            return 0;
        
    }
    
}



