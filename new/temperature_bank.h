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

//
void calc();

#endif // TEMPERATURE_BANK_H
