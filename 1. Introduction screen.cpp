#include <iostream>
#include <string>

using namespace std;

//Function to display the introduction screen

void displayintro() {
	cout << "Welcome to the NZ Blood Bank \n";
	cout << "------------------------------\n";
	cout << "Contact Information : \n";
	cout << "Phone : 012-345-6789 \n";
	cout << "Email : info@nzbloodbank.co.nz \n\n";

	cout << "Please select an option : \n";
	cout << "D. Login as donor \n";
	cout << "R. Login as Recipient\n";
	cout << "2. Register\n";
	cout << "3. Exit\n";
}


//Function to handle user login

void loginDonor() {
	string username, password;

	cout << "Enter your username : ";
	cin >> username;

	cout << "Enter your password : ";
	cin >> password;

	cout << "logging in..... \n";
}


void loginRecipient() {
	string username, password;

	cout << "Enter your username : ";
	cin >> username;
	cout << "Enter your password : ";
	cin >> password;

	cout << "Logging in as recipient....\n";
}




//Function to handle user registration 

void registerUser() {

	string username, password, category;

	cout << "Enter your username : ";
	cin >> username;

	cout << "Enter your password : ";
	cin >> password;

	cout << "Are you a donor or recipient ? (d/r)";
	cin >> category;

	if (category == "d" || category == "D") {
		cout << "Registering as donor....\n";
	}
	else if (category == "r" || category == "R") {
		cout << "Registering as recipient....\n";
	}
	else {
		cout << "Invalid category.\n";
	}

	
}


int main() {
	char choice;

	displayintro();

	do {
		cout << "\nEnter your choice : ";
		cin >> choice;
		switch (choice) {
		case 'd':
		case 'D':
			loginDonor();
			break;
		case 'r':
		case 'R':
			loginRecipient();
			break;
		case '2':
			registerUser();
			break;
		case '3':
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. PLease try again. \n";
		}
		} while (choice != 3);
		return 0;
	}
