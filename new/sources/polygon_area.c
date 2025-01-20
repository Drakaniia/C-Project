#include "main_header.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function prototypes
void title();
void displayMenu();
void areaCircle();
void areaSquare();
void areaRectangle();

void mod2_polygon_area() {
    int choice;
    char anotherConversion[10]; // Buffer for "yes" or "no"

    do {
        title();
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                areaCircle();
                break;
            case 2:
                areaSquare();
                break;
            case 3:
                areaRectangle();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Ask if the user wants another conversion
        do {
            printf("\nDo you want another conversion? (yes/no): ");
            if (fgets(anotherConversion, sizeof(anotherConversion), stdin) != NULL) {
                anotherConversion[strcspn(anotherConversion, "\n")] = '\0'; // Remove newline
            }

            // Clear the input buffer if necessary (only once after fgets)
            while (getchar() != '\n' && getchar() != EOF);

            // Check if the input is valid
            if (strcasecmp(anotherConversion, "yes") != 0 &&
                strcasecmp(anotherConversion, "no") != 0) {
                printf("Invalid input. Please enter 'yes' or 'no'.");
            }
        } while (strcasecmp(anotherConversion, "yes") != 0 &&
                 strcasecmp(anotherConversion, "no") != 0);
    } while (strcasecmp(anotherConversion, "yes") == 0);

}

void title() {
    printf("Polygon Calculator.\n\n");
}

void displayMenu() {
    printf("Choose an option:\n");
    printf("1. Calculate area of Circle.\n");
    printf("2. Calculate area of Square.\n");
    printf("3. Calculate area of Rectangle.\n");
}

void areaCircle() {
    const double PI = 3.14159;
    double radius, result;

    printf("Enter radius of a Circle: ");
    while (scanf("%lf", &radius) != 1) {
        while (getchar() != '\n'); // Clear the invalid input
        printf("Invalid Input, Enter a valid Radius of a Circle: ");
    }
    result = PI * radius * radius;
    printf("The area of a circle with radius %.2lf is %.2lf\n", radius, result);
}

void areaSquare() {
    double side, result;

    printf("Enter side length of a Square: ");
    while (scanf("%lf", &side) != 1) {
        while (getchar() != '\n'); // Clear the invalid input
        printf("Invalid Input, Enter a valid Length of a Square: ");
    }
    result = side * side;
    printf("The area of a square with side %.2lf is %.2lf\n", side, result);
}

void areaRectangle() {
    double length, width, result;

    printf("Enter length of a Rectangle: ");
    while (scanf("%lf", &length) != 1) {
        while (getchar() != '\n'); // Clear the invalid input
        printf("Invalid Input, Enter a valid Length of a Rectangle: ");
    }
    printf("Enter width of a Rectangle: ");
    while (scanf("%lf", &width) != 1) {
        while (getchar() != '\n'); // Clear the invalid input
        printf("Invalid Input, Enter a valid Width of a Rectangle: ");
    }
    result = length * width;
    printf("The area of a rectangle with length %.2lf and width %.2lf is %.2lf\n", length, width, result);
}
