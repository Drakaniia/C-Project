#include "main_header.h"
#include <stdio.h>

void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

void mod1_calc() {
    float num1, num2, result;
    int choice;
    char response;
do {
    // Display menu and get user choice
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get numbers from user
    if (choice >= 1 && choice <= 4) {
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
    }

    // Perform the chosen operation
    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                result = divide(num1, num2);
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please select a valid operation.\n");
    }

    // Ask user if they want to continue
    if (choice != 5) {
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &response);
    } else {
        response = 'n';
    }
} while (response == 'y' || response == 'Y');

void displayMenu() {
    printf("\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}
