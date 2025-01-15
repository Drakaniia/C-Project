#include "main_header.h"
#include <stdio.h>
#include <stdlib.h>

// TEMPERATURE CONVERSION MODULE

// Temperature conversion menu display
static void tempConMenuDisplay(int* choice);

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
} 
  
  
}

// Temperature conversion menu display
static void tempConMenuDisplay(int* choice) {
  printf("Temperature Conversion Program\n");
  printf("Choose the unit you want to convert: \n");
  printf("[1] Kelvin\n");
  printf("[2] Celsius\n");
  printf("[3] Fahrenhiet");
  printf("\nChoose an option (1, 2, or 3): ");
  scanf("%d", choice);
  getchar();
  // return choice;
}

// Kelvin to Celsius and Fahrenheit conversion
static void tempKelvin() {
  float Kelvin, Celsius, Fahrenheit;
  printf("Enter the temperature in kelvin: ");
  scanf("%f", &Kelvin);
  getchar();

  Celsius = (Kelvin - 273.15);
  Fahrenheit = 1.8 * (Kelvin - 273.15) + 32.0;
  printf("In Celsius the value is: %.2f\n", Celsius);
  printf("In Fahrenheit the value is: %.2f\n", Fahrenheit);
}

// Celsius to Kelvin and Fahrenheit conversion
static void tempCelsius() {
  float Celsius, Kelvin, Fahrenhiet;
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &Celsius);
  getchar();
  
  Kelvin = (Celsius + 273.15);
  Fahrenhiet = (Celsius * 1.8) + 32.0;
  printf("In kelvin the value is: %.2f\n", Kelvin);
  printf("In Fahrenhiet the value is: %.2f\n", Fahrenhiet);
}

// Fahrenhiet to Celsius and Kelvin conversion
static void tempFahrenhiet() {
  float Celsius, Kelvin, Fahrenhiet;
  printf("Enter the temperature in fahrenhite: ");
  scanf("%f",&Fahrenhiet);
  getchar();

  Kelvin = (Fahrenhiet - 32.0) * 5/9 +273.15;
  Celsius = (Fahrenhiet - 32.0) * 5/9;
  printf("In Celsius the value is : %.2f\n", Celsius);
  printf("In Kevlin the value is : %.2f\n", Kelvin);
}