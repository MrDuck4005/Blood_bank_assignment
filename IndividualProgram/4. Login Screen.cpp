#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool validatelogin(string username, string password, string usertype) {
	ifstream file("donor_registration.txt");
	string storedUsername, storedPassword;

	if (file.is_open()) {
		while (file >> storedUsername >> storedPassword) {
			if (username == storedUsername && password == storedPassword) {
				file.close();
				return true;
			}
		}
		file.close();
	}
	return false;
}

int main() {
	int loginattempts = 0;
	string username, password, usertype;

	while (loginattempts < 3) {
		cout << "Enter Username : ";
		cin >> username;
		cout << "Enter Password : ";
		cin >> password;
		

		do {
			cout << "Enter user type (d for Donor OR 'r' for Recipient) : ";
			cin >> usertype;
			usertype = tolower(usertype[0]);
		} while (usertype != "d" && usertype != "r");

		if (validatelogin(username, password, usertype)) {
			cout << "Login successful ! " << username << "\n";
			break;
		}
		else {
			cout << "Login failed Please try again. \n";
			loginattempts++;
		}
	}

	if (loginattempts == 3) {
		cout << "Maximum login attempts reached. Please try again later. \n";
	}

	return 0;
}
