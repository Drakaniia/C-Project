#include "main_header.h"
#include <stdio.h>
#include <stdio.h>
#include <math.h>

// Function prototypes
float calculateCircleArea(float radius);
float calculateRectangleArea(float length, float width);
void displayMenu(void);
int validateInput(float *value); // Function for input validation

void mod2_calculate() {
    int choice;
    float radius, length, width;
    do {
        displayMenu();
        printf("Enter your choice: ");
        while(scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number: ");
            while(getchar() != '\n'); // Clear invalid input
        }

        switch (choice) {
            case 1: {
                do {
                    printf("Enter the radius of the circle: ");
                } while (!validateInput(&radius)); // Validate radius input
                float circleArea = calculateCircleArea(radius);
                printf("The area of the circle is: %.2f\n", circleArea);
                break;
            }
            case 2: {
                do {
                    printf("Enter the length of the rectangle: ");
                } while (!validateInput(&length)); // Validate length input
                do {
                    printf("Enter the width of the rectangle: ");
                } while (!validateInput(&width)); // Validate width input
                float rectangleArea = calculateRectangleArea(length, width);
                printf("The area of the rectangle is: %.2f\n", rectangleArea);
                break;
            }
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function definitions
float calculateCircleArea(float radius) {
    const float PI = 3.14159;
    return PI * radius * radius;
}

float calculateRectangleArea(float length, float width) {
    return length * width;
}

void displayMenu(void) {
    printf("\n------------------------ Menu ------------------------\n");
    printf("1. Calculate the area of a Circle\n");
    printf("2. Calculate the area of a Rectangle\n");
    printf("3. Exit\n");
    printf("-------------------------------------------------------\n");
}

int validateInput(float *value) {
    if (scanf("%f", value) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        while(getchar() != '\n'); // Clear invalid input
        return 0; // Input validation failed
    }
    if (*value < 0) {
        printf("Please enter a positive number.\n");
        return 0; // Input validation failed
    }
    return 1; // Input validation succeeded
}
