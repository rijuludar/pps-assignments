#include <stdio.h>
#include <string.h>

// Declare funtion beforehand
void stroperator(int choice);

// Removes '\n' from buffer to ensure it does not leak into fgets input
void removenewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

//Begin Main function
int main() {
    int choice = 0;
    char rerun = 'Y';

    //Keep running as long as rerun is set to y
    while (rerun == 'Y' || rerun == 'y') {
        printf("================================\n");
        printf("In-built String Operations In C \n");
        printf("================================\n\n");

        printf("Choose Operation:\n");
        printf("1 : Measure String (strlen) \n");
        printf("2 : Compare Strings (strcmp) \n");
        printf("3 : Concatenate Strings (strcat) \n");
        printf("4 : Copy String (strcpy) \n");
        //printf("5 : Exit \n");

        printf("\n: ");
        scanf("%d", &choice);
        
        while (getchar() != '\n'); // Clear buffer
        
        stroperator(choice); //pass choice value to stroperator to perform respective operations

        printf("Enter Y to rerun: ");
        scanf(" %c", &rerun);

        printf("\n\n");
    }

    printf("----------------------\n");
    printf("| Program Terminated |\n");
    printf("----------------------\n");

    return 0;
}

//Custom Function
//No output 'void', requires an int input
void stroperator(int choice) {
    
    char str1[2002], str2[1001];

    switch (choice) {
        case 1:
            printf("\n");    
            printf("---------------------------\n");
            printf("1 : Measure String (strlen)\n");
            printf("---------------------------\n");

            printf("Enter String: ");
            fgets(str1, sizeof(str1), stdin);
            removenewline(str1);

            int str1length =  strlen(str1);

            printf("\n\nResult: ");
            printf("\nLength of String: %d characters ", str1length);

            printf("\n-------------------------\n");

            printf("\n\n");

            break;


        case 2:
            printf("\n");    
            printf("----------------------------\n");
            printf("2 : Compare Strings (strcmp)\n");
            printf("----------------------------\n");

            printf("Enter String 1: ");
            fgets(str1, sizeof(str1), stdin);
            removenewline(str1);

            printf("\n");
            printf("Enter String 2: ");
            fgets(str2, sizeof(str2), stdin);
            removenewline(str2);

            printf("\n\nResult: \n");
            if (strcmp(str1, str2) == 0) {
                printf("Strings are identical");
            } else {
                printf("Strings are NOT identical");
            }
            printf("\n----------------------------\n");

            printf("\n\n");
            

            break;


        case 3:
            printf("\n");    
            printf("--------------------------------\n");
            printf("3 : Concatenate Strings (strcat)\n");
            printf("--------------------------------\n");

            printf("Enter String 1: ");
            fgets(str1, 1001, stdin);
            removenewline(str1);

            printf("\n");
            printf("Enter String 2: ");
            fgets(str2, sizeof(str2), stdin);
            removenewline(str2);

            strcat(str1, str2);

            printf("\n\nResult \n");
            printf("Concatenated String (str1 + str2): %s", str1);
            printf("\n--------------------------------\n");

            printf("\n\n");
            

            break;

        case 4:
            printf("\n");    
            printf("------------------------\n");
            printf("4 : Copy String (strcpy)\n");
            printf("------------------------\n");

            printf("Enter String 1: ");
            fgets(str1, sizeof(str1), stdin);
            removenewline(str1);

            printf("\n");
            printf("Enter String 2: ");
            fgets(str2, sizeof(str2), stdin);
            removenewline(str2);

            strcpy(str1, str2);

            printf("\n\nResult \n");
            printf("String 1: %s", str1);
            printf("\n------------------------\n");

            printf("\n\n");
            

            break;

        /*case 5:
            printf("\n\nGoodbye");
            break; */

        default:
            printf("Invalid Choice, Try Again.");
            printf("\n\n");
            
            break;
    }
}

