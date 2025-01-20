#include "main_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// TEMPERATURE CONVERSION MODULE

// Temperature conversion menu display
static int tempConMenuDisplay(int *conversionChoice);

// Kelvin to Celsius and Fahrenheit conversion
static void tempKelvin();

// Celsius to Kelvin and Fahrenheit conversion
static void tempCelsius();

// Fahrenhiet to Celsius and Kelvin conversion
static void tempFahrenhiet();

// TEMP CONVERSION MODULE CALL TO MAIN  
void mod3_tempConversion() {
  int choice;
  char anotherConversion[10];

  do {
    // Display the temperature conversion menu
    tempConMenuDisplay(&choice);

    switch (choice) {
      case 1:
        tempKelvin();
        break;
      case 2:
        tempCelsius();
        break;
      case 3:
        tempFahrenhiet();
        break;
      default:
        printf("Invalid Choice! Please try again.\n");
        break;
    }

    // Ask if the user wants another conversion
    printf("\nDo you want another conversion? (yes/no): ");
    fgets(anotherConversion, sizeof(anotherConversion), stdin);
    anotherConversion[strlen(anotherConversion) - 1] = '\0';

    while (strlen(anotherConversion) == 0) {
        printf("\nYou did not enter any choice!\n");
        printf("Do you want another conversion? (yes/no): ");
        fgets(anotherConversion, sizeof(anotherConversion), stdin);
        anotherConversion[strlen(anotherConversion) - 1] = '\0';
    }

    while (strcasecmp(anotherConversion, "yes") != 0 &&
           strcasecmp(anotherConversion, "no") != 0) {
        printf("\nInvalid input or out of range!\n");
        printf("Do you want another conversion? (yes/no): ");
        fgets(anotherConversion, sizeof(anotherConversion), stdin);
        anotherConversion[strlen(anotherConversion) - 1] = '\0';
    }
    

  } while (strcasecmp(anotherConversion, "yes") == 0);
}


// Temperature conversion menu display
static int tempConMenuDisplay(int *conversionChoice) {
  printf("\n\033[1;34mTemperature Conversion Program\033[0m\n");
  printf("Choose the unit you want to convert:\n");
  printf("[1] Kelvin\n");
  printf("[2] Celsius\n");
  printf("[3] Fahrenheit\n");

  char input[10];

  // Get user inputs
    printf("Enter your choice: ");
    // Input Validation loop
    while (true) {
        if (fgets(input, sizeof(input), stdin)) {
            // input[strcspn(input, "\n")] = '\0';
            
            // Check for invalid input
            if (input[0] == '\n') {
                printf("\nInvalid choice! Enter another.\n");
                printf("Enter your choice: ");
                continue;
            }
            
            // Break for valid input
            if (sscanf(input, "%d", conversionChoice) == 1 &&
                       *conversionChoice >= 1 && *conversionChoice <= 3) {
                break; // Break for a valid input
            }
        }
        printf("\nInvalid choice or out of range! Choose again.\n");
        printf("Enter your choice: ");
    }

  return *conversionChoice;
}

// Kelvin to Celsius and Fahrenheit conversion
static void tempKelvin() {
  char input[20]; 
  double Kelvin, Celsius, Fahrenheit;
  
 // Get user inputs
  printf("Enter the temperature in kelvin: ");
  // Input Validation loop
  while (true) {
    if (fgets(input, sizeof(input), stdin)) {
      // input[strcspn(input, "\n")] = '\0';
      
      // Check for invalid input
      if (input[0] == '\n') {
        printf("\nEmpty entry is not valid! Enter another.\n");
        printf("Enter the temperature in Kelvin: ");
        continue;
      }
      
      // Break for valid input
      if (sscanf(input, "%lf", &Kelvin) == 1) {
        break; // Break for a valid input
      }
    }
    printf("\nInvalid input.\nEnter a valid temperature in Kelvin: ");
  }

  Celsius = (Kelvin - 273.15);
  Fahrenheit = 1.8 * (Kelvin - 273.15) + 32.0;
  printf("In Celsius the value is: %.2f\n", Celsius);
  printf("In Fahrenheit the value is: %.2f\n", Fahrenheit);
}

// Celsius to Kelvin and Fahrenheit conversion
static void tempCelsius() {
  char input[20];
  double Celsius, Kelvin, Fahrenhiet;
  
  // Get user inputs
  printf("Enter the temperature in Celsius: ");
  // Input Validation loop
  while (true) {
    if (fgets(input, sizeof(input), stdin)) {
      // Check for invalid input
      if (input[0] == '\n') {
        printf("\nEmpty entry is not valid! Enter another.\n");
        printf("Enter the temperature in Celsius: ");
        continue;
      }
      
      // Break for valid input
      if (sscanf(input, "%lf", &Celsius) == 1) {
        break; // Break for a valid input
      }
    }
    printf("\nInvalid input.\nEnter a valid temperature in Celsius: ");
  }

  Kelvin = (Celsius + 273.15);
  Fahrenhiet = (Celsius * 1.8) + 32.0;
  printf("In kelvin the value is: %.2f\n", Kelvin);
  printf("In Fahrenhiet the value is: %.2f\n", Fahrenhiet);
}

// Fahrenhiet to Celsius and Kelvin conversion
static void tempFahrenhiet() {
  char input[20];
  double Celsius, Kelvin, Fahrenhiet;

  // Get user inputs
  printf("Enter the temperature in Fahrenhiet: ");
  // Input Validation loop
  while (true) {
    if (fgets(input, sizeof(input), stdin)) {
      // input[strcspn(input, "\n")] = '\0';
      
      // Check for invalid input
      if (input[0] == '\n') {
        printf("\nEmpty entry is not valid! Enter another.\n");
        printf("Enter the temperature in Fahrenhiet: ");
        continue;
      }
      
      // Break for valid input
      if (sscanf(input, "%lf", &Fahrenhiet) == 1) {
        break; // Break for a valid input
      }
    }
    printf("\nInvalid input.\nEnter a valid temperature in Fahrenhiet: ");
  }

  Kelvin = (Fahrenhiet - 32.0) * 5 / 9 + 273.15;
  Celsius = (Fahrenhiet - 32.0) * 5 / 9;
  printf("In Celsius the value is : %.2f\n", Celsius);
  printf("In Kevlin the value is : %.2f\n", Kelvin);
}