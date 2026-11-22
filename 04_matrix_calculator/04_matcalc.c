#include <stdio.h>

int main() {
    char rerun;
    
    
    // Wrap in a loop so program can run again
    do {
        //Program Title
        printf("[ X X ]\n");
        printf("[ X X ]\n");
        printf("Matrix Calculator\n");
        printf("\n");
        
        //Get row and column inputs to define the matrix
        int row, column;
        printf("Define Matrix Dimensions \n");
        printf("Row Count: ");
        while (scanf("%d", &row) != 1 || row <= 0) {
            while ( getchar() != '\n' );
            printf("Invalid Input! Try again: ");
        }
        
        printf("Column Count: ");
        while (scanf("%d", &column) != 1 || column <= 0) {
            while ( getchar() != '\n' );
            printf("Invalid Input! Try again: ");
        }
        
        //Initialise matrices, array index pointers and 'display' variables
        float matrix1[row][column], matrix2[row][column], result[row][column];
        int r, c;
        int displayrow, displaycolumn;

        //Get Matrix 1 Input
        printf("\n");
        printf("=================================\n");
        printf("Enter Matrix 1 [%d x %d] Elements: \n", row, column);
        printf("=================================\n");
        for(r=0; r<row; r++) {
            for(c=0; c<column; c++) {
                
                displayrow = r + 1;
                displaycolumn = c + 1;
                
                printf("Row %d ; Column %d: ", displayrow, displaycolumn);
                while(scanf("%f", &matrix1[r][c]) != 1) {
                    while ( getchar() != '\n' );
                    printf("Invalid Input for [%d][%d], try again", r, c);
                }
                while ( getchar() != '\n' );
            }
        }

        //Output the saved Matrix for better visualisation
        printf("\n");
        printf("Matrix 1 Saved:");
        printf("\n");
        
        for(r=0; r<row; r++) {
            printf("[");
            for(c=0; c<column; c++) {
                printf("%g ", matrix1[r][c]);
            }
            printf("]\n");
        }
        
        displayrow = row;
        displaycolumn = column;

        //Get Matrix 2 Input
        printf("\n");
        printf("=================================\n");
        printf("Enter Matrix 2 [%d x %d] Elements: \n", row, column);
        printf("=================================\n");
        for(r=0; r<row; r++) {
            for(c=0; c<column; c++) {

                displayrow = r + 1;
                displaycolumn = c + 1;

                printf("Row %d ; Column %d: ", displayrow, displaycolumn);
                while(scanf("%f", &matrix2[r][c]) != 1) {
                    while ( getchar() != '\n' );
                    printf("Invalid Input for [%d][%d], try again", r, c); 
                }
                while ( getchar() != '\n' );
            }
        }

        //Output the saved Matrix for better visualisation
        printf("\n");
        printf("Matrix 2 Saved:");
        printf("\n");
        
        for(r=0; r<row; r++) {
            printf("[");
            for(c=0; c<column; c++) {
                printf("%g ", matrix2[r][c]);
            }
            printf("]\n");
        }

        //Get input for operations
        char operator;
        char outputresult; //var to check if the result should be output

        printf("\n");
        printf("Enter Operator (+, -): ");
        scanf(" %c", &operator);

        switch (operator) {
            case '+':
                for(r=0; r<row; r++) {
                    for(c=0; c<column; c++) {
                        result[r][c] = matrix1[r][c] + matrix2[r][c];
                    }        
                }
                outputresult = 'T';
                break;
            case '-':
                for(r=0; r<row; r++) {
                    for(c=0; c<column; c++) {
                        result[r][c] = matrix1[r][c] - matrix2[r][c];
                    }        
                }
                outputresult = 'T';
                break;
            default:
                printf("Invalid Operand Entered\n");
                outputresult = 'F';
                break;
        }

        if (outputresult == 'T') {
            printf("\n");
            printf("=========\n");
            printf("Result: \n");
            printf("=========\n");
            for(r=0; r<row; r++) {
                printf("[");
                for(c=0; c<column; c++) {
                    printf("%g ", result[r][c]);
                }
                printf("]\n");
            }
        }
        

        //Check if user wants to rerun code
        printf("\n\nInput 'Y' to Run Again: ");
        scanf(" %c", &rerun);
        
        if (rerun == 'Y' || rerun == 'y') {
            printf("\n\n");
            printf("============================================\n");
            printf("\n\n");
        } else {
            printf("\n----------------------\n");
            printf("| Program Terminated |\n");
            printf("----------------------\n");
        }
        
    } while (rerun == 'Y' || rerun == 'y'); 

    return 0;
}

