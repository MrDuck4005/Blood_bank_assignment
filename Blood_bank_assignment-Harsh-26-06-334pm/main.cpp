#include "header.h"



int main() {
        system("CLS");
        header();

        loadInitialData(); // Load initial data from file

        bool exitProgram = false;
        while (!exitProgram) {

            displayMainMenu();
            string str;
            cout << "Enter your choice: ";
            cin >> str;

            if ((str == "1") || (str == "2") || (str == "3") || (str == "4")) {
                int choice = stoi(str);

                cin.ignore(); // Ignore newline left in buffer

                switch (choice) {
                case 1:
                    registerMenu();
                    break;
                case 2:
                    loginMenu();
                    break;
                case 3:
                    adminLogin();
                    break;
                case 4:
                    exitProgram = true;
                    cout << "Exiting program..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            }

            else {
                cout << "Invalid choice. Please try again." << endl;
            }

        }

        return 0;
}

void displayMainMenu() {
    cout << "\nMain Menu:" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Admin Login" << endl;
    cout << "4. Exit" << endl;
}
