#include "main_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// BANK MANAGEMENT SYSTEM MODULE
// static void anotherFunction();
typedef struct {
  int account_number;
  char name[100];
  double balance;
} Account;

typedef struct {
  Account accounts[MAX_ACCOUNTS];
  int account_count;
} Bank;

// Function prototypes
void init_bank(Bank *bank);

int create_account(Bank *bank, 
                  int account_number, 
                  const char *name, 
                  double initial_deposit);

int deposit(Bank *bank, 
            int account_number, 
            double amount);

int withdraw(Bank *bank, 
            int account_number, 
            double amount);

double check_balance(Bank *bank, 
                    int account_number);

int close_account(Bank *bank, 
                  int account_number);

// Function to manage the bank system
void mod4_bankSystem() {
    Bank bank;
  init_bank(&bank);
  int account_number, choice;
  double amount;
  char name[100];

  while (1) {
    printf("\nBanking System Menu:\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Close Account\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        printf("Enter your name: ");
        getchar(); // to consume newline character left by scanf
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        printf("Enter initial deposit: ");
        scanf("%lf", &amount);
        create_account(&bank, account_number, name, amount);
        printf("Account created successfully!\n");
        break;

      case 2:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        printf("Enter deposit amount: ");
        scanf("%lf", &amount);
        if (deposit(&bank, account_number, amount)) {
          printf("Deposit successful!\n");
        } else {
          printf("Deposit failed!\n");
        }
        break;

      case 3:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        printf("Enter withdrawal amount: ");
        scanf("%lf", &amount);
        if (withdraw(&bank, account_number, amount)) {
          printf("Withdrawal successful!\n");
        } else {
          printf("Withdrawal failed!\n");
        }
        break;

      case 4:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        amount = check_balance(&bank, account_number);
        if (amount >= 0) {
          printf("Balance: %.2f\n", amount);
        } else {
          printf("Account not found.\n");
        }
        break;

      case 5:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        if (close_account(&bank, account_number)) {
          printf("Account closed successfully!\n");
        } else {
          printf("Account not found!\n");
        }
        break;

      case 6:
        printf("Exiting...\n");
        exit(0);

      default:
        printf("Invalid choice. Try again.\n");
    }
  }

  // anotherFunction();
}


// Function definitions
void init_bank(Bank *bank) {
  bank->account_count = 0;
}

int create_account(Bank *bank, 
                  int account_number, 
                  const char *name, 
                  double initial_deposit) {
  if (bank->account_count >= MAX_ACCOUNTS) return 0;

  for (int i = 0; i < bank->account_count; i++) {
    if (bank->accounts[i].account_number == account_number) return 0;
  }

  Account new_account;
  new_account.account_number = account_number;
  strncpy(new_account.name, name, sizeof(new_account.name) - 1);
  new_account.name[sizeof(new_account.name) - 1] = '\0';
  new_account.balance = initial_deposit;

  bank->accounts[bank->account_count++] = new_account;
  return 1;
}

int deposit(Bank *bank, 
            int account_number, 
            double amount) {
  for (int i = 0; i < bank->account_count; i++) {
    if (bank->accounts[i].account_number == account_number) {
      if (amount > 0) {
        bank->accounts[i].balance += amount;
        return 1;
      }
      return 0;
    }
  }
  return 0;
}

int withdraw(Bank *bank, 
            int account_number, 
            double amount) {
  for (int i = 0; i < bank->account_count; i++) {
    if (bank->accounts[i].account_number == account_number) {
      if (amount > 0 && amount <= bank->accounts[i].balance) {
        bank->accounts[i].balance -= amount;
        return 1;
      }
      return 0;
    }
  }
  return 0;
}

double check_balance(Bank *bank, 
                    int account_number) {
  for (int i = 0; i < bank->account_count; i++) {
    if (bank->accounts[i].account_number == account_number) {
      return bank->accounts[i].balance;
    }
  }
  return -1;
}

int close_account(Bank *bank, 
                  int account_number) {
  for (int i = 0; i < bank->account_count; i++) {
    if (bank->accounts[i].account_number == account_number) {
      for (int j = i; j < bank->account_count - 1; j++) {
        bank->accounts[j] = bank->accounts[j + 1];
      }
      bank->account_count--;
      return 1;
    }
  }
  return 0;
}












/*
static void anotherFunction() { 
  printf("This is a bank system app!!\n");
}
*/

















