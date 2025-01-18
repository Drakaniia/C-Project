#include "main_header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MAIN METHOD FOR EXECUTION

/*
  // Compile the program with the following command:
    gcc -I./headers sources\main.c sources\calculator.c sources\menu_app.c sources\bank_system.c sources\temp_conversion.c -o allapp -Wall -g

  // run the program with the following command:
    .\allapp

  // Exit terminal with the following command:
    exit
*/

int main() {
  int appChoice;
  char againChoice[10];

  do {
    // Menu display
    mod5_menuPrompts();

    // Application choice with validation
    appChoice = valid1_appChoice();

    switch (appChoice) {
      case 1:
        mod1_calc();
        break;
      /*
      case 2:
        anotherFile();
        break;
      */
      case 3:
        mod3_tempConversion();
        break;
      case 4:
        mod4_bankSystem();
        getchar();
        break;
      case 5:
        printf("\033[1;35mExiting the program...\033[0m\n\n");                       // Purple
        exit(0);
      default:
        printf("Invalid Choice! Please try again.\n");
        break;
    }

    // Another app choice with validation
    valid2_againChoice(againChoice);

  } while (strcasecmp(againChoice, "Yes") != 0);

  // Successful executions, hhaha.
  return 0;
}














