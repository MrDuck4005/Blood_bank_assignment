#include <iostream>
#include <string>

using namespace std;

struct Recipient {
	string name;
	string address;
	string email;
	string contactno;
	bool validationstatus;
};

void registerRecipient(Recipient& recipient) {
	
	cout << "Enter recipient's name : ";
	getline(cin, recipient.name);

	cout << "Enter recipient's address : ";
	getline(cin, recipient.address);

	cout << "Enter recipient's email :";
	getline(cin, recipient.email);

	cout << "Enter recipient's contact number : ";
	getline(cin, recipient.contactno);

	recipient.validationstatus = false;
}

void displayRecipient(const Recipient& recipient) {
	cout << "Recipient's Name : " << recipient.name << endl;
	cout << "Recipient's Address : " << recipient.address << endl;
	cout << "Recipient's Email : " << recipient.email << endl;
	cout << "Recipient's Contact Number : " << recipient.contactno << endl;
	cout << "Recipient's Validation Status : " << (recipient.validationstatus ? "Valid" : "Not Valid") << endl;

}

int main() {
	Recipient recipient;

	cout << "Recipient Registration" << endl;
	registerRecipient(recipient);

	cout << "\nRecipient Details : " << endl;
	displayRecipient(recipient);

	return 0;
}
