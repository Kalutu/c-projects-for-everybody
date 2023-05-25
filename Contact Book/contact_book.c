#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

void addContact(struct Contact *contacts, int *contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Contact book is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact contact;

    printf("Enter the name: ");
    scanf(" %[^\n]", contact.name);

    printf("Enter the phone number: ");
    scanf(" %[^\n]", contact.phone);

    printf("Enter the email address: ");
    scanf(" %[^\n]", contact.email);

    contacts[*contactCount] = contact;
    (*contactCount)++;

    printf("Contact added successfully.\n");
}

void searchContact(const struct Contact *contacts, int contactCount, const char *searchName) {
    int found = 0;
    int i;

    printf("----- Search Results -----\n");

    for (i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found for the specified name.\n");
    }
}

void updateContact(struct Contact *contacts, int contactCount, const char *searchName) {
    int found = 0;
    int i;

    for (i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Enter the new phone number: ");
            scanf(" %[^\n]", contacts[i].phone);

            printf("Enter the new email address: ");
            scanf(" %[^\n]", contacts[i].email);

            printf("Contact updated successfully.\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found for the specified name.\n");
    }
}

void deleteContact(struct Contact *contacts, int *contactCount, const char *searchName) {
    int found = 0;
    int i;

    for (i = 0; i < *contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            // Shift contacts to remove the deleted contact
            for (int j = i; j < *contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }

            (*contactCount)--;
            printf("Contact deleted successfully.\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found for the specified name.\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount = 0;

    int choice;

    do {
        printf("----- Menu -----\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2: {
                char searchName[MAX_NAME_LENGTH];
                printf("Enter the name to search: ");
                scanf(" %[^\n]", searchName);
                searchContact(contacts, contactCount, searchName);
                break;
            }
            case 3: {
                char searchName[MAX_NAME_LENGTH];
                printf("Enter the name to update: ");
                scanf(" %[^\n]", searchName);
                updateContact(contacts, contactCount, searchName);
                break;
            }
            case 4: {
                char searchName[MAX_NAME_LENGTH];
                printf("Enter the name to delete: ");
                scanf(" %[^\n]", searchName);
                deleteContact(contacts, &contactCount, searchName);
                break;
            }
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

