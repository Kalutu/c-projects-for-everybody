#include <stdio.h>

float convertToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float convertToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    float temperature;
    int choice;

    printf("Temperature Converter\n");

    do {
        printf("\n---- Menu ----\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("Temperature in Fahrenheit: %.2f\n", convertToFahrenheit(temperature));
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("Temperature in Celsius: %.2f\n", convertToCelsius(temperature));
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

