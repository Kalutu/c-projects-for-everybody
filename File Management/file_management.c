#include <stdio.h>

void createFile() {
    char fileName[100];
    printf("Enter the name of the file to create: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error creating the file.\n");
        return;
    }

    printf("File created successfully.\n");
    fclose(file);
}

void writeFile() {
    char fileName[100];
    printf("Enter the name of the file to write to: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char content[100];
    printf("Enter the content to write: ");
    scanf(" %[^\n]", content);

    fprintf(file, "%s\n", content);
    printf("Content written to the file successfully.\n");
    fclose(file);
}

void readFile() {
    char fileName[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char content[100];
    printf("File contents:\n");
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }

    fclose(file);
}

void deleteFile() {
    char fileName[100];
    printf("Enter the name of the file to delete: ");
    scanf("%s", fileName);

    if (remove(fileName) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting the file.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nFile Management Menu:\n");
        printf("1. Create a file\n");
        printf("2. Write to a file\n");
        printf("3. Read a file\n");
        printf("4. Delete a file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                deleteFile();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

