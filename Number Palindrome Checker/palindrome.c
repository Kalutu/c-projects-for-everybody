#include <stdio.h>

int isPalindrome(int num) {
    int reversedNum = 0;
    int originalNum = num;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    if (originalNum == reversedNum) {
        return 1; // Palindrome
    } else {
        return 0; // Not a palindrome
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}

