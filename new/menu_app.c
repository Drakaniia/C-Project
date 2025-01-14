#include "temperature_bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MENU FOR THE APPLICATION MODULE

static void menuDisplay();


// Main function call to main.c
void mod5_menuPrompts() {
  menuDisplay();
}

// Four application displays
static void menuDisplay() {

  printf("[BASIC APPLICATION]\n");
  printf("\033[1;31m[1] Calculator\033[0m\n");
  printf("\033[1;36m[2] Polygon Area Calculator\033[0m\n"); 
  printf("\033[1;34m[3] Temperature Conversion\033[0m\n");      // Blue
  printf("\033[1;33m[4] Bank Management System\033[0m\n");    // Yellow
  
}

// Application choice validation
int valid1_appChoice() {
  int appChoice;

  while (1) {
    printf("Enter your choice (3 or 4): ");
    if (scanf("%d", &appChoice) == 1 && (appChoice == 3 || appChoice == 4)) {
      while (getchar() != '\n'); // Clear input buffer
      break;
    }
    printf("Invalid input! Please enter 3 or 4.\n");
    while (getchar() != '\n'); // Clear invalid input
  }

  return appChoice;
}

// Another app choice validation
char* valid2_againChoice(char* againChoice, int valid_size) {
  while (1) {
    printf("\nDo you want to exit? (Yes/No): ");
    if (fgets(againChoice, valid_size, stdin)) {
      againChoice[strcspn(againChoice, "\n")] = '\0'; // Remove newline
      if (strcasecmp(againChoice, "Yes") == 0 || strcasecmp(againChoice, "No") == 0) {
        return againChoice;
      }
      printf("Invalid input! Please enter 'Yes' or 'No'.\n");
    } else {
      // Clear buffer if fgets fails (e.g., if size limit is exceeded)
      while (getchar() != '\n');
    }
  }
}






















