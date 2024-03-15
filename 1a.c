#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
    char *name;
    int date;
    char *activity;
};


struct Day createDay() {
    struct Day day;


    day.name = (char *)malloc(sizeof(char) * 20);
    printf("Enter day name: ");
    scanf("%s", day.name);

    printf("Enter date: ");
    scanf("%d", &day.date);


    day.activity = (char *)malloc(sizeof(char) * 100);
    printf("Enter activity: ");
    scanf(" %[^\n]s", day.activity);

    return day;
}

void readCalendar(struct Day *calendar, int size) {
    for (int i = 0; i < size; ++i) {
        calendar[i] = createDay();
    }
}

void displayCalendar(struct Day *calendar, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Day: %s\n", calendar[i].name);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n\n", calendar[i].activity);
    }
}


void freeCalendar(struct Day *calendar, int size) {
    for (int i = 0; i < size; ++i) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
}

int main() {
    int size;


    printf("Enter the number of days in a week: ");
    scanf("%d", &size);

    
    struct Day *calendar = (struct Day *)malloc(sizeof(struct Day) * size);


    if (calendar == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    
    readCalendar(calendar, size);

    
    printf("\nCalendar Details:\n");
    displayCalendar(calendar, size);

    
    freeCalendar(calendar, size);
    free(calendar);

    return 0; 
}
