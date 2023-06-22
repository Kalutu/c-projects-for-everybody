#include <stdio.h>

int main() {
    int rows, columns, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    printf("\nMultiplication Table:\n");

    // Print column headers
    printf("  ");
    for (j = 1; j <= columns; j++) {
        printf("%4d", j);
    }
    printf("\n");

    // Print table rows
    for (i = 1; i <= rows; i++) {
        printf("%2d", i);
        for (j = 1; j <= columns; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}

