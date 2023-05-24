#include <stdio.h>
#include <stdlib.h>

void createFile() {
    char fileName[100];
    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Failed to create the file.\n");
        return;
    }

    printf("File created successfully.\n");
    fclose(file);
}

void openFile() {
    char fileName[100];
    printf("Enter the name of the file to open: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    printf("Contents of the file:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
}

void modifyFile() {
    char fileName[100];
    printf("Enter the name of the file to modify: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    printf("Enter the new text (Press Ctrl+D to save and exit):\n");

    char ch;
    while ((ch = getchar()) != EOF) {
        fputc(ch, file);
    }

    printf("File modified successfully.\n");
    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n---- Simple Text Editor ----\n");
        printf("1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Modify a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                openFile();
                break;
            case 3:
                modifyFile();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

