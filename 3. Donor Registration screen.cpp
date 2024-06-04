#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Donor {

	string firstName;
	string lastName;
	string dob;
	string nationality;
	string ethnicity;
	string gender;
	string conditions;
	string bloodGroup;
	string contactNo;
	string email;
	string address;
	string lastDonationDate;
	string username;
	string password;

};

vector<unique_ptr<Donor>> donors;


void registerDonor() {
	auto donor = make_unique<Donor>();


	cout << "Enter First Name : " << endl;
	getline(cin, donor->firstName);

	cout << "Enter Last Name : " << endl;
	getline(cin, donor->lastName);


	cout << "Enter Date of Birth (dd/mm/yyyy) : " << endl;
	string dob;
	getline(cin, dob);

	if (dob.size() == 2) {
		dob += '/';
	}
	else if (dob.size() == 5) {
		dob.insert(2, "/");
		dob += '/';
	}
	else if (dob.size() == 8) {
		dob.insert(2, "/");
		dob.insert(5, "/");
	}

	donor->dob = dob;

	cout << "Enter Nationality : " << endl;
	getline(cin, donor->nationality);

	cout << "Enter Ethnicity : " << endl;
	getline(cin, donor->ethnicity);

	cout << "Enter Gender : " << endl;
	getline(cin, donor->gender);

	cout << "Enter known Health conditions : " << endl;
	getline(cin, donor->conditions);


	cout << "Select Blood Group : " << endl;
	cout << "1. A " << endl;
	cout << "2. B " << endl;
	cout << "3. AB " << endl;
	cout << "4. O " << endl;
	cout << "5. Unknown " << endl;

	int bloodchoice;
	do {
		cout << "Enter your blood group : " << endl;
		cin >> bloodchoice;
		cin.ignore();

		switch (bloodchoice) {
		case 1:
			donor->bloodGroup = "A";
			break;
		case 2:
			donor->bloodGroup = "B";
			break;
		case 3:
			donor->bloodGroup = "AB";
			break;
		case 4:
			donor->bloodGroup = "O";
			break;
		case 5:
			donor->bloodGroup = "Unknown";
			break;
		default:
			cout << "Invalid choice. Please Try Again " << endl;
			donor->bloodGroup = "Invalid";
		}
	} while (bloodchoice < 1 || bloodchoice > 5);


	cout << "Enter contact number : " << endl;
	getline(cin, donor->contactNo);

	cout << "Enter Email : " << endl;
	getline(cin, donor->email);

	cout << "Enter Address : " << endl;
	getline(cin, donor->address);

	cout << "Enter last date of donation (*optional, leave it blank if none) : " << endl;
	getline(cin, donor->lastDonationDate);

	cout << "Enter Username : " << endl;
	getline(cin, donor->username);

	cout << "Enter Password : " << endl;
	getline(cin, donor->password);

	donors.push_back(move(donor));
	cout << "Donor registered successfully!" << endl;
}

void displayDonors() {

	for (const auto& donor : donors) {

		cout << "First Name : " << donor->firstName << endl;
		cout << "Last Name : " << donor->lastName << endl;
		cout << "Date of Birth : " << donor->dob << endl;
		cout << "Nationality : " << donor->nationality << endl;
		cout << "Ethnicity : " << donor->ethnicity << endl;
		cout << "Gender : " << donor->gender << endl;
		cout << "Known Health Conditions : " << donor->conditions << endl;
		cout << "Blood Group : " << donor->bloodGroup << endl;
		cout << "Contact Number : " << donor->contactNo << endl;
		cout << "Email : " << donor->email << endl;
		cout << "Address : " << donor->address << endl;
		cout << "Last Date of Donation : " << donor->lastDonationDate << endl;
		cout << "Username : " << donor->username << endl;
		cout << "Password : " << donor->password << endl;
		cout << "--------------------------------------" << endl;
	}
}

int main() {
	int choice;
	do {
		cout << "Donor Registration System " << endl;
		cout << "1. Register Donor " << endl;
		cout << "2. Display Donors " << endl;
		cout << "3. Exit" << endl;

		cout << "\nEnter your choice" << endl;
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			registerDonor();
			break;
		case 2:
			displayDonors();
			break;
		case 3:
			cout << "Exiting the program " << endl;
			break;
		default:
			cout << "Invalid choice. Please try again. " << endl;
		}
	} while (choice != 3);

	return 0;
}