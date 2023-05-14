#include <stdio.h>

// Function to encrypt the message
void caesarEncrypt(char message[], int key) {
    int i = 0;
    char ch;

    while (message[i] != '\0') {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
        }

        message[i] = ch;
        i++;
    }
}

// Function to decrypt the message
void caesarDecrypt(char message[], int key) {
    int i = 0;
    char ch;

    while (message[i] != '\0') {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - key - 'a' + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - key - 'A' + 26) % 26 + 'A';
        }

        message[i] = ch;
        i++;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message
    caesarEncrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesarDecrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

