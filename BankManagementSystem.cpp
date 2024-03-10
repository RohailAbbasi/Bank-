// BankManagementSystem.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Account {
    int acno;
    std::string name;
    int deposit;
    char type;
};

void createAccount(Account accounts[], int& count);
void deleteAccount(Account accounts[], int& count, int accountNumber);
void listAllAccounts(const Account accounts[], int count);
void listIndividualAccount(const Account accounts[], int count, int accountNumber);
void modifyAccount(Account accounts[], int count, int accountNumber);
void showAccount(const Account& account);

int main() {
    const int MAX_ACCOUNTS = 100;
    Account accounts[MAX_ACCOUNTS];
    int count = 0;
    char ch;
    int num;

    do {
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t1. NEW ACCOUNT";
        cout << "\n\n\t2. DELETE ACCOUNT";
        cout << "\n\n\t3. LIST ALL ACCOUNTS";
        cout << "\n\n\t4. LIST INDIVIDUAL ACCOUNT";
        cout << "\n\n\t5. MODIFY ACCOUNT";
        cout << "\n\n\t6. EXIT";
        cout << "\n\n\tSelect Your Option (1-6) ";
        cin >> ch;

        switch (ch) {
            case '1':
                createAccount(accounts, count);
                break;
            case '2':
                cout << "\n\n\tEnter The account No. : ";
                cin >> num;
                deleteAccount(accounts, count, num);
                break;
            case '3':
                listAllAccounts(accounts, count);
                break;
            case '4':
                cout << "\n\n\tEnter The account No. : ";
                cin >> num;
                listIndividualAccount(accounts, count, num);
                break;
            case '5':
                cout << "\n\n\tEnter The account No. : ";
                cin >> num;
                modifyAccount(accounts, count, num);
                break;
            case '6':
                cout << "\n\n\tThanks for using bank management system";
                break;
            default:
                cout << "\a";
        }

        cin.ignore();
        cin.get();

    } while (ch != '6');

	system("pause");
    return 0;
}

void createAccount(Account accounts[], int& count) {
    if (count < 100) {
        cout << "\nEnter The account No. : ";
        cin >> accounts[count].acno;
        cout << "\nEnter The Name of The account Holder : ";
        cin.ignore();
        getline(cin, accounts[count].name);
        cout << "\nEnter Type of The account (C/S) : ";
        cin >> accounts[count].type;
        cout << "\nEnter The Initial amount (>=500 for Saving and >=1000 for current): ";
        cin >> accounts[count].deposit;
        cout << "\n\n\nAccount Created..";
        count++;
    } else {
        cout << "\nCannot create more accounts. The system is full.";
    }
}

void deleteAccount(Account accounts[], int& count, int accountNumber) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (accounts[i].acno == accountNumber) {
            found = true;
            for (int j = i; j < count - 1; ++j) {
                accounts[j] = accounts[j + 1];
            }
            count--;
            cout << "\nAccount deleted.";
            break;
        }
    }

    if (!found) {
        cout << "\nAccount not found.";
    }
}

void listAllAccounts(const Account accounts[], int count) {
    if (count > 0) {
        cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
        cout << "====================================================\n";
        cout << "A/c no.      NAME           Type  Balance\n";
        cout << "====================================================\n";
        for (int i = 0; i < count; ++i) {
            showAccount(accounts[i]);
        }
    } else {
        cout << "\nNo accounts available.";
    }
}

void listIndividualAccount(const Account accounts[], int count, int accountNumber) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (accounts[i].acno == accountNumber) {
            found = true;
            showAccount(accounts[i]);
            break;
        }
    }

    if (!found) {
        cout << "\nAccount not found.";
    }
}

void modifyAccount(Account accounts[], int count, int accountNumber) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (accounts[i].acno == accountNumber) {
            found = true;
            cout << "\n\nEnter The New Details of account" << std::endl;
            cout << "\nEnter The Name of The account Holder : ";
            cin.ignore();
            getline(std::cin, accounts[i].name);
            cout << "\nEnter Type of The account (C/S) : ";
            cin >> accounts[i].type;
            cout << "\nEnter The Initial amount (>=500 for Saving and >=1000 for current): ";
            cin >> accounts[i].deposit;
            cout << "\n\n\t Record Updated";
            break;
        }
    }

    if (!found) {
        std::cout << "\nAccount not found.";
    }
}

void showAccount(const Account& account) {
    cout << account.acno << setw(10) << " " << account.name << setw(10) << " "
              << account.type <<setw(6) << account.deposit << endl;
}
