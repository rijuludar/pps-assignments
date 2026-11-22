#include <stdio.h>
#include <time.h>

char leapcheck(int *ptr1, int *days);
int firstdayofyear(int year);
//void printcalendar(int year);

int main() {
    printf("▦ Calendar\n");

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year;
    printf("Enter Year: ");

    while (scanf("%d",&year) != 1 || year <= 0) {
        printf("Invalid Input, Try Again: ");
        while(getchar() != '\n' );
    }

    char isleap = leapcheck(&year, days);

    printf("| LOG: Leap Year Status: %c \n", isleap);
    printf("| LOG: February: %d days \n", days[1]);

    char *weekdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" }; 

    int day_index = firstdayofyear(year);

    printf("| LOG: First day of Year %d : %s\n", year, weekdays[day_index]);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //printcalendar(year);

    int day_offset = day_index;

    for(int m=0; m<12; m++) {
        int weekday = 0;
        //printf("Month: %s \n", months[m]);
        printf("\n---------------- %s ----------------\n", months[m]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        
        //initialise spacer index
        for(int i=0; i < day_offset; i++) {
            printf("     ");
            weekday++;
        }
        //initialise day index
        for(int d=1; d<=days[m]; d++) {
            printf("%5d", d);
            weekday++;
            if(weekday == 7) {
                //reset weekday to 0 & newline
                printf("\n");
                weekday = 0;
            }

        }
        //when month ends in the middle of the week
        if (weekday != 0) {
            printf("\n");
        }

        //weekday offset for next month
        day_offset = (day_offset + days[m]) % 7;
    }
}

char leapcheck(int *ptr1, int *days) {

    if(*ptr1 % 4 == 0 && *ptr1 % 100 != 0) {
        days[1] = 29;
        return('T');
    } else if (*ptr1 % 400 == 0){
        days[1] = 29;
        return('T');
    } else {
        return('F');
    }




}

int firstdayofyear(int year) {
    /*struct tm t = {0};

    t.tm_year = year - 1900;
    t.tm_mon = 0;  //0 for January
    t.tm_mday = 1; //1st day of month

    mktime(&t);

    return t.tm_wday;*/

    //Using Gregorian calendar formula to bypass the year 1970 limit of mktime
    int y = year - 1;
    return (y + y / 4 - y / 100 + y / 400 + 1) % 7;
}