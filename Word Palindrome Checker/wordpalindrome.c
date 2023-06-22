#include <stdio.h>
#include <string.h>

int isPalindrome(const char *word) {
    int left = 0;
    int right = strlen(word) - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }

    return 1; // Palindrome
}

int main() {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    if (isPalindrome(word)) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}

