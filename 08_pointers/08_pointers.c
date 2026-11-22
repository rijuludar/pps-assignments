#include <stdio.h>

void swap(int *p1, int *p2);

int main() {
    char rerun;
    int num1, num2;

    do{
        printf("=============================\n");
        printf("Swap 2 numbers using pointers\n");
        printf("=============================\n\n");

        printf("Enter Number 1: ");
        while(scanf("%d", &num1) != 1) {
            printf("Invalid Input, Try Again: ");
            while(getchar() != '\n');
        }

        printf("Enter Number 2: ");
        while(scanf("%d", &num2) != 1) {
            printf("Invalid Input, Try Again: ");
            while(getchar() != '\n');
        }
        printf("\n");

        //Print original values and adresses
        printf("\n");
        printf("----------------------------------------------------\n");
        printf("|                     BEFORE SWAP                  |\n");
        printf("----------------------------------------------------\n");
        printf("| Number 1 -> Address: %p | Value: %d |\n", (void *)&num1, num1);
        printf("| Number 2 -> Address: %p | Value: %d |\n", (void *)&num2, num2);
        printf("----------------------------------------------------\n");

        //Pass address by prefixing with an '&'
        swap(&num1, &num2);

        //Print updated values
        printf("\n");
        printf("----------------------------------------------------\n");
        printf("|                     AFTER SWAP                   |\n");
        printf("----------------------------------------------------\n");
        printf("| Number 1 -> Address: %p | Value: %d |\n", (void *)&num1, num1);
        printf("| Number 2 -> Address: %p | Value: %d |\n", (void *)&num2, num2);
        printf("----------------------------------------------------\n");

        printf("\nEnter Y to rerun : ");
        scanf(" %c", &rerun);
        printf("\n");


    } while (rerun == 'Y' || rerun == 'y');

    printf("----------------------\n");
    printf("| Program Terminated |\n");
    printf("----------------------\n");

    return 0;
}

void swap(int *p1, int *p2) {

    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

}