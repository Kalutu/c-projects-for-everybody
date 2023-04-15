#include <stdio.h>

int main() {
    char operator;
    double num1, num2;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operator) {
        case '+':
            printf("Result: %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Result: %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Result: %.2lf\n", num1 * num2);
            break;
        case '/':
            if(num2 == 0)
            {
                printf("Error: division by zero");
            }
            else
                printf("Result: %.2lf\n", num1 / num2);
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}
