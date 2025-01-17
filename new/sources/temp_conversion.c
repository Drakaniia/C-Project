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
  char anotherConversion[10]; // Buffer for "yes" or "no"

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


// Temperature conversion menu display
static int tempConMenuDisplay(int *conversionChoice) {
  printf("\n\033[1;34mTemperature Conversion Program\033[0m\n");
  printf("Choose the unit you want to convert:\n");
  printf("[1] Kelvin\n");
  printf("[2] Celsius\n");
  printf("[3] Fahrenheit\n");

  // int conversionChoice;
  while (true) {
    printf("Enter your choice (1-3): ");
    if (scanf("%d", conversionChoice) == 1 && 
                        *conversionChoice >= 1 && 
                        *conversionChoice <= 3) {
      while (getchar() != '\n'); // Clear input buffer
      break;
    } else {
      printf("Invalid input. Please enter a number between 1 and 3.\n");
      while (getchar() != '\n'); // Clear input buffer
    }
  }

  return *conversionChoice;
}

// Kelvin to Celsius and Fahrenheit conversion
static void tempKelvin() {
  double Kelvin, Celsius, Fahrenheit; 
  
  printf("Enter the temperature in kelvin: ");
  while ((scanf("%lf", &Kelvin)) != 1 || Kelvin == 0) {
    while (getchar() != '\n');
    printf("Invalid input. Enter a valid temperature in kelvin: ");
  }

  Celsius = (Kelvin - 273.15);
  Fahrenheit = 1.8 * (Kelvin - 273.15) + 32.0;
  printf("In Celsius the value is: %.2f\n", Celsius);
  printf("In Fahrenheit the value is: %.2f\n", Fahrenheit);
}

// Celsius to Kelvin and Fahrenheit conversion
static void tempCelsius() {
  double Celsius, Kelvin, Fahrenhiet;

  printf("Enter the temperature in Celsius: ");
  while ((scanf("%lf", &Celsius)) != 1 || Celsius == 0) {
    while (getchar() != '\n');
    printf("Invalid input. Enter a valid temperature in Celsius: ");
  }
  
  Kelvin = (Celsius + 273.15);
  Fahrenhiet = (Celsius * 1.8) + 32.0;
  printf("In kelvin the value is: %.2f\n", Kelvin);
  printf("In Fahrenhiet the value is: %.2f\n", Fahrenhiet);
}

// Fahrenhiet to Celsius and Kelvin conversion
static void tempFahrenhiet() {
  double Celsius, Kelvin, Fahrenhiet;

  printf("Enter the temperature in fahrenhite: ");
  while ((scanf("%lf", &Fahrenhiet)) != 1 || Fahrenhiet == 0) {
    while (getchar() != '\n');
    printf("Invalid input. Enter a valid temperature in Fahrenheit: ");
  }

  Kelvin = (Fahrenhiet - 32.0) * 5 / 9 + 273.15;
  Celsius = (Fahrenhiet - 32.0) * 5 / 9;
  printf("In Celsius the value is : %.2f\n", Celsius);
  printf("In Kevlin the value is : %.2f\n", Kelvin);
}