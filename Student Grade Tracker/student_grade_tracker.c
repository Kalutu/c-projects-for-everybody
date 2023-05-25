#include <stdio.h>

#define MAX_SUBJECTS 5

struct Student {
    char name[50];
    int grades[MAX_SUBJECTS];
};

void calculateAverage(struct Student student) {
    int sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += student.grades[i];
    }

    float average = (float)sum / MAX_SUBJECTS;
    printf("Average grade: %.2f\n", average);
}

void calculateFinalGrade(struct Student student) {
    int sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += student.grades[i];
    }

    float average = (float)sum / MAX_SUBJECTS;
    char finalGrade;

    if (average >= 90) {
        finalGrade = 'A';
    } else if (average >= 80) {
        finalGrade = 'B';
    } else if (average >= 70) {
        finalGrade = 'C';
    } else if (average >= 60) {
        finalGrade = 'D';
    } else {
        finalGrade = 'F';
    }

    printf("Final grade: %c\n", finalGrade);
}

int main() {
    struct Student student;

    printf("Enter student name: ");
    scanf("%s", student.name);

    printf("Enter grades for %s\n", student.name);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter grade for Subject %d: ", i + 1);
        scanf("%d", &student.grades[i]);
    }

    printf("\n--- Grade Report ---\n");
    printf("Student: %s\n", student.name);
    calculateAverage(student);
    calculateFinalGrade(student);

    return 0;
}

