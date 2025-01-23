#include "main_header.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function prototypes
static void PolygonCalculator();
static void mainTitle();
static void displayMenu();
static void areaCircle();
static void areaSquare();
static void areaRectangle();
static void areaTriangle();

void mod2_polygon_area() {

    PolygonCalculator();
}


static void PolygonCalculator() {
    mainTitle();

    int choice;
    char response;

    do {
        displayMenu();
        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            while (getchar() != '\n');
            printf("Invalid Input. Please enter a number between 1 and 4: ");
        }


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
            case 4:
                areaTriangle();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    printf("\nDo you want another Conversion? y/n: ");
    scanf(" %c", &response);

    } while (response == 'y');
}

static void areaCircle() {
    const double PI = 3.14159;
    double radius, result;

    printf("Enter radius of a Circle: ");
    while (scanf("%lf", &radius) != 1) {
        while (getchar() != '\n');
        printf("Invalid Input, Enter a valid Radius of a Circle: ");
    }
    result = PI * radius * radius;
    printf("The area of a circle with radius %.2lf is %.2lf\n", radius, result);
}

static void areaSquare() {
    double side, result;

    printf("Enter side length of a Square: ");
    while (scanf("%lf", &side) != 1) {
        while (getchar() != '\n');
        printf("Invalid Input, Enter a valid Length of a Square: ");
    }
    result = side * side;
    printf("The area of a square with side of %.2lf is %.2lf\n", side, result);
}

static void areaRectangle() {
    double length, width, result;

    printf("Enter length of a Rectangle: ");
    while (scanf("%lf", &length) != 1) {
        while (getchar() != '\n');
        printf("Invalid Input, Enter a valid Length of a Rectangle: ");
    }
    printf("Enter width of a Rectangle: ");
    while (scanf("%lf", &width) != 1) {
        while (getchar() != '\n');
        printf("Invalid Input, Enter a valid Width of a Rectangle: ");
    }
    result = length * width;
    printf("The area of a rectangle with length of %.2lf and width of %.2lf is %.2lf\n", length, width, result);
}


static void areaTriangle() {
    double base, height, result;

    printf("Enter the Base: ");
    while (scanf("%lf", &base) != 1 || base <= 0) {
        while (getchar() != '\n');
        printf("Invalid Input, Enter a Valid Base (greater than 0): ");
    }

    printf("Enter the Height: ");
    while (scanf("%lf", &height) != 1 || height <= 0) {
        while (getchar() != '\n');
        printf("Invalid Input, Enter a Valid Height (greater than 0): ");
    }

    result = 0.5 * base * height;
    printf("The area of a triangle with base of %.2lf and height of %.2lf is %.2lf\n", base, height, result);
}

static void displayMenu() {
    printf("Choose an option:\n");
    printf("[1] Calculate area of Circle.\n");
    printf("[2] Calculate area of Square.\n");
    printf("[3] Calculate area of Rectangle.\n");
    printf("[4] Calculate area of Triangle.\n");
}

static void mainTitle() {
    printf("\033[0;31mPo\033[0m");
    printf("\033[0;33mlyg\033[0m");
    printf("\033[0;33mon\033[0m");
    printf(" ");
    printf("\033[0;32mCal\033[0m");
    printf("\033[0;34mcu\033[0m");
    printf("\033[0;34mlat\033[0m");
    printf("\033[0;31mor\n\n\033[0m");
}

