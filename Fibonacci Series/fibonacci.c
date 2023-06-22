#include <stdio.h>

void generateFibonacci(int n) {
    int first = 0, second = 1, next, i;

    printf("Fibonacci Series: ");

    for (i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
}

int main() {
    int terms;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &terms);

    generateFibonacci(terms);

    return 0;
}

