#include "main_header.h"
#include <stdio.h>

void title();
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
        
        title();

        // Get numbers from user
        printf("Enter 1st number/s: ");
        while (scanf("%f", &num1) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while(getchar() != '\n'); // clear invalid input
            continue; // continue
        }

        printf("Enter 2nd number/s: ");
        while (scanf("%f", &num2) != 1) {
            printf("Invalid input. Please enter a valid number.");
            while(getchar() != '\n'); // clear invalid input
            continue; // continue
        }
        
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number from 1-5.");
            while(getchar() != '\n'); // clear invalid input
            continue;
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
                return; // Exit the function immediately
            default:
                printf("Invalid choice. Please select a valid operation.\n");
        }

        // Ask user if they want to continue
        if (choice != 5) {
            printf("\nDo you want to continue? (y/n): ");
            while (scanf(" %c", &response) != 1) {
            printf("Invalid input. Please enter a number from 1-5.");
            while(getchar() != '\n'); // clear invalid input
            continue;
            }   
        } else {
            response = 'n';
        }
    } while (response == 'y' || response == 'Y');
}


void title() {
    printf("\nSimple Calculator \n");
}
void displayMenu() {
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n\n\n");
    printf("Choose an Operator: "); // Added exit option to the menu
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
