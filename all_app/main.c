#include "temperature_bank.h"
#include <stdio.h>
#include <string.h>

// MAIN METHOD FOR EXECUTION

int main() {
  int appChoice;
  char againChoice[10];

  do {
    // Menu display
    mod5_menuPrompts();

    // Application choice with validation
    appChoice = valid1_appChoice();

    switch (appChoice) {
      case 3:
        mod3_tempConversion();
        break;
      case 4:
        mod4_bankSystem();
        break;
      default:
        printf("Invalid Choice! Please try again.\n");
        break;
    }

    // Another app choice with validation
    valid2_againChoice(againChoice, sizeof(againChoice));

  } while (strcasecmp(againChoice, "Yes") != 0);

  return 0;
}



// Comment
// Hello World!!










