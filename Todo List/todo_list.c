#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100

struct Task {
    char description[100];
    int completed;
};

struct Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("The to-do list is full. Cannot add more tasks.\n");
        return;
    }

    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[numTasks].description);
    tasks[numTasks].completed = 0;
    numTasks++;

    printf("Task added successfully!\n");
}

void markTaskAsComplete() {
    int taskIndex;

    printf("Enter the index of the task to mark as complete: ");
    scanf("%d", &taskIndex);

    if (taskIndex >= 0 && taskIndex < numTasks) {
        tasks[taskIndex].completed = 1;
        printf("Task marked as complete!\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void removeTask() {
    int taskIndex, i;

    printf("Enter the index of the task to remove: ");
    scanf("%d", &taskIndex);

    if (taskIndex >= 0 && taskIndex < numTasks) {
        for (i = taskIndex; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;
        printf("Task removed successfully!\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void displayTasks() {
    if (numTasks == 0) {
        printf("No tasks found.\n");
        return;
    }

    printf("Tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. [%s] %s\n", i, tasks[i].completed ? "X" : " ", tasks[i].description);
    }
}

int main() {
    int choice;

    do {
        printf("\n---- To-Do List ----\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Complete\n");
        printf("3. Remove Task\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markTaskAsComplete();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

