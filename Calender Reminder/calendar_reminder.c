#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMINDERS 10
#define MAX_LENGTH 100

struct Reminder {
    int day;
    char event[MAX_LENGTH];
};

struct Calendar {
    int month;
    int year;
    struct Reminder reminders[MAX_REMINDERS];
    int reminderCount;
};

void displayCalendar(struct Calendar calendar) {
    printf("----- Calendar -----\n");
    printf("      %d/%d\n", calendar.month, calendar.year);
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    // Get the day of the week for the first day of the month
    int startDay = 1;
    // Month offset for Zeller's Congruence (January and February are counted as months 13 and 14 of the previous year)
    int monthOffset = (calendar.month < 3) ? 12 : 0;
    // Year of the century
    int yearOfCentury = calendar.year % 100;
    // Zero-based century
    int century = calendar.year / 100;

    // Zeller's Congruence calculation
    int h = (startDay + 13 * (calendar.month + 1 + monthOffset) / 5 + yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century) % 7;

    // Number of days in the current month
    int daysInMonth;
    if (calendar.month == 2) {
        if ((calendar.year % 4 == 0 && calendar.year % 100 != 0) || (calendar.year % 400 == 0)) {
            daysInMonth = 29; // Leap year
        } else {
            daysInMonth = 28;
        }
    } else if (calendar.month == 4 || calendar.month == 6 || calendar.month == 9 || calendar.month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    // Print the calendar grid
    int dayCounter = 1;
    int i;

    // Print empty cells before the first day of the month
    for (i = 0; i < h; i++) {
        printf("    ");
    }

    // Print the days of the month
    for (i = h; i < 7; i++) {
        printf("%4d", dayCounter);

        // Check if a reminder exists for the current day
        int j;
        for (j = 0; j < calendar.reminderCount; j++) {
            if (calendar.reminders[j].day == dayCounter) {
                printf(" *"); // Print a reminder marker
                break;
            }
        }

        dayCounter++;
    }
    printf("\n");

    // Print the remaining days of the month
    while (dayCounter <= daysInMonth) {
        for (i = 0; i < 7 && dayCounter <= daysInMonth; i++) {
            printf("%4d", dayCounter);

            // Check if a reminder exists for the current day
            int j;
            for (j = 0; j < calendar.reminderCount; j++) {
                if (calendar.reminders[j].day == dayCounter) {
                    printf(" *"); // Print a reminder marker
                    break;
                }
            }

            dayCounter++;
        }
        printf("\n");
    }
}

void addReminder(struct Calendar *calendar) {
    if (calendar->reminderCount >= MAX_REMINDERS) {
        printf("Maximum number of reminders reached.\n");
        return;
    }

    int day;
    printf("Enter the day (1-31): ");
    scanf("%d", &day);

    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return;
    }

    char event[MAX_LENGTH];
    printf("Enter the event: ");
    scanf(" %[^\n]", event);

    struct Reminder reminder;
    reminder.day = day;
    strcpy(reminder.event, event);

    calendar->reminders[calendar->reminderCount++] = reminder;
    printf("Reminder added successfully.\n");
}

void editReminder(struct Calendar *calendar) {
    int day;
    printf("Enter the day (1-31) of the reminder to edit: ");
    scanf("%d", &day);

    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return;
    }

    int i;
    for (i = 0; i < calendar->reminderCount; i++) {
        if (calendar->reminders[i].day == day) {
            char event[MAX_LENGTH];
            printf("Enter the new event: ");
            scanf(" %[^\n]", event);
            strcpy(calendar->reminders[i].event, event);
            printf("Reminder edited successfully.\n");
            return;
        }
    }

    printf("No reminder found for the specified day.\n");
}

void deleteReminder(struct Calendar *calendar) {
    int day;
    printf("Enter the day (1-31) of the reminder to delete: ");
    scanf("%d", &day);

    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return;
    }

    int i;
    for (i = 0; i < calendar->reminderCount; i++) {
        if (calendar->reminders[i].day == day) {
            // Shift reminders to remove the deleted reminder
            for (int j = i; j < calendar->reminderCount - 1; j++) {
                calendar->reminders[j] = calendar->reminders[j + 1];
            }

            calendar->reminderCount--;
            printf("Reminder deleted successfully.\n");
            return;
        }
    }

    printf("No reminder found for the specified day.\n");
}

void displayReminders(struct Calendar calendar) {
    printf("----- Reminders -----\n");

    if (calendar.reminderCount == 0) {
        printf("No reminders found.\n");
        return;
    }

    int i;
    for (i = 0; i < calendar.reminderCount; i++) {
        printf("Day %d: %s\n", calendar.reminders[i].day, calendar.reminders[i].event);
    }
}

int main() {
    struct Calendar calendar;

    printf("Enter the month (1-12): ");
    scanf("%d", &calendar.month);

    if (calendar.month < 1 || calendar.month > 12) {
        printf("Invalid month.\n");
        return 0;
    }

    printf("Enter the year: ");
    scanf("%d", &calendar.year);

    printf("\n");

    int choice;

    do {
        printf("----- Menu -----\n");
        printf("1. Display Calendar\n");
        printf("2. Add Reminder\n");
        printf("3. Edit Reminder\n");
        printf("4. Delete Reminder\n");
        printf("5. Display Reminders\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case 1:
                displayCalendar(calendar);
                break;
            case 2:
                addReminder(&calendar);
                break;
            case 3:
                editReminder(&calendar);
                break;
            case 4:
                deleteReminder(&calendar);
                break;
            case 5:
                displayReminders(calendar);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}

