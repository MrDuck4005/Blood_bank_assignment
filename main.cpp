#include "header.h"
#include <iostream>

using namespace std;

int main() {
    loadInitialData(); // Load initial data from files

    cout << "Welcome to Blood Donation Management System" << endl;

    bool exitProgram = false;
    while (!exitProgram) {
        displayMainMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline left in buffer

        switch (choice) {
        case 1:
            registerMenu();
            break;
        case 2:
            loginMenu();
            break;
        case 3:
            adminMenu();
            break;
        case 4:
            exitProgram = true;
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void displayMainMenu() {
    cout << "\nMain Menu:" << endl;
    cout << "1. Register as Donor" << endl;
    cout << "2. Register as Recipient" << endl;
    cout << "3. Login" << endl;
    cout << "4. Exit" << endl;
}
