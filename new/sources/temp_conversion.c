#include "main_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// TEMPERATURE CONVERSION MODULE

// Temperature conversion menu display
static void tempConMenuDisplay();

// Kelvin to Celsius and Fahrenheit conversion
static void tempKelvin();

// Celsius to Kelvin and Fahrenheit conversion
static void tempCelsius();

// Fahrenhiet to Celsius and Kelvin conversion
static void tempFahrenhiet();


// Main function call to main.c
void mod3_tempConversion() {
  // float Celsius, Kelvin, Fahrenhiet;
  int choice;

  tempConMenuDisplay();
  choice = valid1_appChoice();

  // tempConMenuDisplay(&choice);

  switch (choice) {
  case 1:
    tempKelvin();
    getchar();
    break;
  case 2:
    tempCelsius();
    getchar();
    break;
  case 3:
    tempFahrenhiet();
    getchar();
    break;
  default:
    printf("Invalid Choice! Please try again.\n");
    break;
  }  
}

// Temperature conversion menu display
static void tempConMenuDisplay() {
  printf("\n\033[1;34mTemperature Conversion Program\033[0m\n");
  printf("Choose the unit you want to convert:\n");
  printf("[1] Kelvin\n");
  printf("[2] Celsius\n");
  printf("[3] Fahrenhiet\n");
}

// Kelvin to Celsius and Fahrenheit conversion
static void tempKelvin() {
  float Kelvin, Celsius, Fahrenheit; 
  
  printf("Enter the temperature in kelvin: ");
  while ((scanf("%f", &Kelvin)) != 1 || Kelvin == 0) {
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
  float Celsius, Kelvin, Fahrenhiet;

  printf("Enter the temperature in Celsius: ");
  while ((scanf("%f", &Celsius)) != 1 || Celsius == 0) {
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
  float Celsius, Kelvin, Fahrenhiet;

  printf("Enter the temperature in fahrenhite: ");
  while ((scanf("%f", &Fahrenhiet)) != 1 || Fahrenhiet == 0) {
    while (getchar() != '\n');
    printf("Invalid input. Enter a valid temperature in Fahrenheit: ");
  }

  Kelvin = (Fahrenhiet - 32.0) * 5 / 9 + 273.15;
  Celsius = (Fahrenhiet - 32.0) * 5 / 9;
  printf("In Celsius the value is : %.2f\n", Celsius);
  printf("In Kevlin the value is : %.2f\n", Kelvin);
}