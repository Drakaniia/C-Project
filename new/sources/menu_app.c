#include "main_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// MENU FOR THE APPLICATION MODULE

static void menuDisplay();


// Main function call to main.c
void mod5_menuPrompts() {
  menuDisplay();
}

// Four application displays
static void menuDisplay() {

  printf("\n[BASIC APPLICATION]\n");
  printf("\033[1;31m[1] Calculator\033[0m\n");
  printf("\033[1;36m[2] Hello!\033[0m\n"); 
  printf("\033[1;34m[3] Temperature Conversion\033[0m\n");      // Blue
  printf("\033[1;33m[4] Bank Management System\033[0m\n");    // Yellow
  printf("\033[1;35m[5] Exit\033[0m\n");                       // Purple
}

// Application choice validation
int valid1_appChoice() {
  int appChoice;

  /*
  while (true) {
    printf("Enter your choice (1, 2, 3, 4 or 5 to exit): ");
    if (scanf("%d", &appChoice) == 1 && (appChoice >= 1 && appChoice <= 5)) {
      while (getchar() != '\n'); 
      return appChoice;
    }
    printf("Invalid input! Please enter a valid choice (1, 2, 3, 4 or 5 to exit).\n");
    while (getchar() != '\n');
  }
  */

 while (true) {
    char buffer[50];

    printf("Enter app choice: ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
      if (buffer[0] == '\n') {
        printf("Invalid choice. Enter another choice.\n");
      } else if (sscanf(buffer, "%d", &appChoice) == 1) {
        if (appChoice >= 1 && appChoice <= 6) {
          break;
        } else {
          printf("Choice out of range!\n");
        }
      } else {
        printf("Invalid choice! Enter another app choice.\n");
      }
    }
  }

  return appChoice;
}

// Another app choice validation
char* valid2_againChoice(char* againChoice, int valid_size) {
  while (true) {
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






















