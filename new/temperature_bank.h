#ifndef TEMPERATURE_BANK_H
#define TEMPERATURE_BANK_H

// TEMPERATURE CONVERSION MODULE
void mod3_tempConversion();

// BANK MANAGEMENT SYSTEM MODULE
void mod4_bankSystem();

// MENU DISPLAY AND VALIDATION MODULE
void mod5_menuPrompts();

// Input validation prototypes
int valid1_appChoice();
char* valid2_againChoice(char* againChoice, int valid_size);

// gcc main.c menu_app.c temp_conversion.c bank_system.c -o main -Wall -g
// ./main
#endif // TEMPERATURE_BANK_H
