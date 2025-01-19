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
  // printf("\033[1;36m[2] Hello!\033[0m\n"); 
  printf("\033[1;34m[3] Temperature Conversion\033[0m\n");      // Blue
  printf("\033[1;33m[4] Bank Management System\033[0m\n");    // Yellow
  printf("\033[1;35m[5] Exit\033[0m\n");                       // Purple
}

// Application choice validation
int valid1_appChoice() {
  int appChoice;

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
        printf("\nInvalid choice! Enter another app choice.\n");
      }
    }
  }

  return appChoice;
}

char* valid2_againChoice(char *againChoice) {

  while (true) {
    printf("\nDo you want to exit? yes or no: ");
    if (fgets(againChoice, 100, stdin)) {  // Assuming buffer size of 100
      againChoice[strcspn(againChoice, "\n")] = '\0';  // Remove newline
      if (againChoice[0] == '\0') {
        printf("Invalid choice!!\n");
      } else if (strcmp(againChoice, "Yes") == 0 ||
                 strcmp(againChoice, "yes") == 0 ||
                 strcmp(againChoice, "No") == 0 ||
                 strcmp(againChoice, "no") == 0) {
        break;
      } else {
        printf("Invalid choice. Choose again.\n");
      }
    }
  }

  return againChoice;
}





















