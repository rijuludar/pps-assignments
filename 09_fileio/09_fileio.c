#include <stdio.h>
#include <string.h>


int main() {
    printf("==================\n");
    printf("File-Handling in C \n");
    printf("==================\n\n");

    char rerun;

    do{

        char source[100];
        FILE *sptr = NULL;

        //adding a new while loop with a fallback approach
        do {
            printf("Enter Source Filename: ");
            fgets(source, sizeof(source), stdin);
            source[strcspn(source, "\n")] = '\0';
            sptr = fopen(source, "r");

            if ( sptr == NULL ) {
                printf("This file does not exist, Try again \n");
            }
        } while ( sptr == NULL );


        printf("\nFile Opened Successfully\n");
        printf("'%s' Preview: \n", source);
        printf("-------------------------\n");
        
        //Limited length file preview
        char buffer[10];
        int i = 0;        
        // Read until EOF
        while (fgets(buffer, sizeof(buffer), sptr) != NULL && i <= 20) {
            fputs(buffer, stdout); 
            i++;
        }
        printf("\n-------------------------\n");

        printf("\n\n");

        rewind(sptr); // Rewinds the file position back to character 0!


        char destin[100];
        printf("Enter Destination Filename: ");
        fgets(destin, sizeof(destin), stdin);

        // Remove the trailing newline character added by fgets
        destin[strcspn(destin, "\n")] = '\0';

        FILE *dptr = fopen(destin, "w");

        if(dptr == NULL) {
            printf("Unable to Create destination file\n");
            return 1;
        }

        //Copying the contents
        int ch;

        while( (ch = fgetc(sptr)) != EOF) {
            fputc(ch, dptr);
        }

        printf("\nFile Copied Successfully\n");

        fclose(sptr);
        fclose(dptr);

        printf("\nEnter Y to rerun: ");
        scanf("%c", &rerun);
        while (getchar() != '\n');
        printf("\n");

    } while ( rerun == 'Y' || rerun == 'y');
 
    printf("----------------------\n");
    printf("| Program Terminated |\n");
    printf("----------------------\n");

    return 0;

}