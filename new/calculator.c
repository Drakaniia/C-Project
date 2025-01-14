#include "temperature_bank.h"
#include <stdio.h>

void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

void mod1_calc() {
    float num1, num2, result;
    int choice;

  printf("Simple Calculator\n\n");

  do {
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    displayMenu();
    printf("Choose an operation (1-4): ");
    scanf("%d", &choice);

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
      default:
        printf("Invalid choice. Please select a valid operation.\n");
    }

  } while (choice >= 1 && choice <= 4);

  return 0;
}

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
