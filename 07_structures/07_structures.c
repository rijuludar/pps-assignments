#include <stdio.h>

struct studata {
    int rollno;
    char name[100];
    int marks[3]; 
    int total;
    float percentage;
};

int main() {
    char rerun;

    // Wrap in a loop so program can run again
    do {
        printf("=======================================\n");
        printf("       STUDENT GRADE REPORT SYSTEM     \n");
        printf("=======================================\n\n");

        int strength;

        // Get student headcount with input validation
        printf("Enter the number of students: ");
        while (scanf("%d", &strength) != 1 || strength <= 0) {
            while (getchar() != '\n');
            printf("Invalid Input! Enter a positive integer: ");
        }
        while (getchar() != '\n'); // Clear buffer

        //prepare array of structures for headcount
        struct studata s[strength];

        //Loop to accept data for each student
        for (int i = 0; i < strength; i++) {
            printf("\n|===================================|\n");
            printf("|          Student #%d Entry         |\n", i + 1);
            printf("|===================================|\n");

            // Roll Number input
            printf("| Roll Number : ");
            while (scanf("%d", &s[i].rollno) != 1 || s[i].rollno <= 0) {
                while (getchar() != '\n');
                printf("| Invalid Roll No! Try again: ");
            }
            while (getchar() != '\n');

            // Name input
            printf("| Name        : ");
            scanf("%99s", s[i].name);
            while (getchar() != '\n');

            printf("|-----------------------------------|\n");
            printf("| Marks (0 - 100)                   |\n");
            printf("|-----------------------------------|\n");

            s[i].total = 0;

            // Loop through the 3 subjects
            for (int j = 0; j < 3; j++) {
                printf("| Subject %d   : ", j + 1);
                while (scanf("%d", &s[i].marks[j]) != 1 || s[i].marks[j] < 0 || s[i].marks[j] > 100) {
                    while (getchar() != '\n');
                    printf("| Invalid! Enter marks (0-100): ");
                }
                while (getchar() != '\n');

                // Accumulate total marks
                s[i].total += s[i].marks[j];
            }

            printf("|===================================|\n");

            // Calculate percentage
            s[i].percentage = s[i].total / 3.0;
        }

        // Output Result Table (Aligned with borders)
        printf("\n\n");
        printf("========================================================================================\n");
        printf("                                    STUDENT RESULTS                                     \n");
        printf("========================================================================================\n");
        printf("%-10s %-16s %-12s %-12s %-12s %-8s %-10s\n", 
               "Roll No", "Name", "Subject: 1", "Subject: 2", "Subject: 3", "Total", "Percentage");
        printf("----------------------------------------------------------------------------------------\n");

        for (int i = 0; i < strength; i++) {
            printf("%-10d %-16s %-12d %-12d %-12d %-8d %-10.2f\n", 
                   s[i].rollno, 
                   s[i].name, 
                   s[i].marks[0], 
                   s[i].marks[1], 
                   s[i].marks[2], 
                   s[i].total, 
                   s[i].percentage);
        }
        printf("========================================================================================\n");

        // Check if user wants to rerun
        printf("\nInput 'Y' to Run Again: ");
        scanf(" %c", &rerun);

        if (rerun == 'Y' || rerun == 'y') {
            printf("\n\n");
            printf("========================================================================================\n\n");
        } else {
            printf("\n----------------------\n");
            printf("| Program Terminated |\n");
            printf("----------------------\n");
        }

    } while (rerun == 'Y' || rerun == 'y');

    return 0;
}