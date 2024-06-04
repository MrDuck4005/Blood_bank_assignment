#include <iostream>
#include <string>

using namespace std;

void donateBlood();
void showBenefits();
void manageInfo();

class Donor {
private:
	string name;
	string contactDetails;
	string address;
	string healthStatus;

public:
	Donor(string n, string c, string a, string h) : name(n), contactDetails(c), address(a), healthStatus(h) {}

	string getName() { return name; }
	string getContactDetails() { return contactDetails; }
	string getAddress() { return address; }
	string getHealthStatus() { return healthStatus; }

	void setContactDetails(string c) { contactDetails = c; }
	void setAddress(string a) { address = a; }
	void setHealthStatus(string h) { healthStatus = h; }
};

void donateBlood() {
	cout << "Thank you for choosing to donate blood. \n" << endl;
	cout << "Procedure to donate blood are : \n\n";

	cout << "1. Check Eligibility: Ensure you meet age, weight, health, and travel criteria. " << endl;
	cout << "2. Register: Provide basic information at the donation center. " << endl;
	cout << "3. Medical Questionaire: Answer questions about your health and lifestyle. " << endl;
	cout << "4. Mini-Physical: Quick check of vital signs and hemoglobin levels. " << endl;
	cout << "5. Donation: A trained professional collects blood via a sterile needle. " << endl;
	cout << "6. Rest and Refreshments: Rest briefly and have refreshments post-donation. " << endl;
	cout << "7. Post-Donation Care: Avoid strenuous activity, keep the bandage on, and hydrate. " << endl;
	cout << "8. Follow-up: Some centers may check on you afterward. " << endl;

}

void showBenefits() {
	cout << "Benefits of Blood Donation : " << endl;

	cout << "Help save lives " << endl;
	cout << "Reduce risk of heart disease " << endl;
	cout << "Burn Calories " << endl;
	cout << "Health Check-Up " << endl;
	cout << "Stimulates Blood Cell Production " << endl;
	cout << "Sense of Fulfillment " << endl;
}

void manageInfo(Donor& donor) {
	cout << "Manage Information : " << endl;
	cout << "1. Update Contact Details. " << endl;
	cout << "2. Update Address. " << endl;
	cout << "3. Update Health Status. " << endl;
	cout << "4. Book Donation Appointment. " << endl;

	int choice;
	cout << "Enter your choice : " << endl;
	cin >> choice;

	switch (choice) {
	case 1: {
		string newContact;
		cout << "Enter new contact details : ";
		cin.ignore();
		getline(cin, newContact);
		donor.setContactDetails(newContact);
		cout << "Contact details updated.." << endl;
		break;
	}
	case 2: {
		string newAddress;
		cout << "Enter new address : ";
		cin.ignore();
		getline(cin, newAddress);
		donor.setAddress(newAddress);
		cout << "Address details updated.." << endl;
		break;
	}
	case 3: {
		string newHealthStatus;
		cout << "Enter new health status details : ";
		cin.ignore();
		getline(cin, newHealthStatus);
		donor.setHealthStatus(newHealthStatus);
		cout << "Health status details updated.." << endl;
		break;
	}
	case 4: {
		cout << "Booking appointment for donation." << endl;
		break;
	}
	default:
		cout << "Invalid input" << endl;
	}

	cout << "\nUpdated Information : " << endl;
	cout << "Name : " << donor.getName() << endl;
	cout << "Contact Details : " << donor.getContactDetails() << endl;
	cout << "Address : " << donor.getAddress() << endl;
	cout << "Health Status : " << donor.getHealthStatus() << endl;

}


int main() {

	// Example of a Patient
	Donor donor("John Adams", "0800-111-2222", "city road", "Healthy");

	int choice;
	do {
		//Main Display Menu 
		cout << "\nMenu : \n";
		cout << "1. Procedure to donate blood\n";
		cout << "2. Benefits of blood donation\n";
		cout << "3. Manage Information\n";
		cout << "4. Exit Program\n";

		cout << "Enter your choice : \n\n";
		cin >> choice;

		switch (choice) {
		case 1:
			donateBlood();
			break;
		case 2:
			showBenefits();
			break;
		case 3:
			manageInfo(donor);
			break;
		case 4:
			cout << "Exiting Program. " << endl;
			break;
		default:
			cout << "Invalid input, Try again" << endl;
		}

	} while (choice != 4);

	return 0;
}