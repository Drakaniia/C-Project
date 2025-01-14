#include "main_header.h"
#include <stdio.h>
#include <stdlib.h>

// TEMPERATURE CONVERSION MODULE


// Main function call to main.c
void mod3_tempConversion() {
  float Celsius, Kelvin, Fahrenhiet;
  int choice;


  printf("Temperature Conversion Program\n");
  printf("Choose the unit you want to convert: \n");
  printf("[1] Kelvin\n");
  printf("[2] Celsius\n");
  printf("[3] Fahrenhiet");
  printf("\nChoose an option (1, 2, or 3): ");
  scanf("%d", &choice);
  getchar();

  switch (choice) {
  case 1:
    printf("Enter the temperature in kelvin: ");
    scanf("%f", &Kelvin);
    getchar();

    Celsius = (Kelvin - 273.15);
    Fahrenhiet = 1.8 *(Kelvin -273.15) + 32.0;
    printf("In Celsius the value is: %.2f\n", Celsius);
    printf("In Fahrenhiet the value is: %.2f\n", Fahrenhiet);
    break;

  case 2:
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &Celsius);
    getchar();
    
    Kelvin = (Celsius + 273.15);
    Fahrenhiet = (Celsius * 1.8) + 32.0;
    printf("In kelvin the value is: %.2f\n", Kelvin);
    printf("In Fahrenhiet the value is: %.2f\n", Fahrenhiet);
    break;

  case 3:
    printf("Enter the temperature in fahrenhite: ");
    scanf("%f",&Fahrenhiet);
    getchar();

    Kelvin = (Fahrenhiet - 32.0) * 5/9 +273.15;
    Celsius = (Fahrenhiet - 32.0) * 5/9;
    printf("In Celsius the value is : %.2f\n", Celsius);
    printf("In Kevlin the value is : %.2f\n", Kelvin);
    break;

  default:
    printf("Please! enter a valid value\n");
    break;
  } 
  
  
}














