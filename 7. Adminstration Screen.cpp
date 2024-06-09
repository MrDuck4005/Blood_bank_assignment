#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Data structures to represent donor and recipient information

struct Donor {
	string name;
	string bloodgroup;
	string location; 
	bool bloodTested;
};

struct Recipient {
	string name;
	string bloodgroup;
	string location;
};

//Function to update blood testing reports

void updateBloodTestReport(vector<Donor>& donors, const string& donorName, bool tested) {
	for (auto& donor : donors) {
		if (donor.name == donorName) {
			donor.bloodTested = tested;
			cout << "Blood testing report updated for donor : " << donorName << "\n\n" << endl;
			return;
		}
	}

	cout << "Donor not found " << endl;

}


//Function to generate report based on blood group

void generateBloodGroupReport(const vector<Donor>& donors, const string& bloodgroup) {
	cout << "Donors with blood group " << bloodgroup << " : " << endl;
	for (const auto& donor : donors) {
		if (donor.bloodgroup == bloodgroup) {
			cout << "Name : " << donor.name << ", Location : " << donor.location << "\n\n" << endl;
		}
	}
}


//Function to generate report based on location

void generateLocationReport(const vector<Donor>& donors, const string& location) {
	cout << "Donors in location " << location << " : " << endl;
	for (const auto& donor : donors) {
		if (donor.location == location) {
			cout << "Name : " << donor.name << ", Blood Group : " << donor.bloodgroup << "\n\n" << endl;
		}
	}
}


//Function to generate recipient report

void generateRecipientReport(const vector<Recipient>& recipients) {
	cout << "Recipient Report : " << "\n" <<  endl;
	for (const auto& recipient : recipients) {
		cout << "Name : " << recipient.name << ", Blood Group : " << recipient.bloodgroup << ", Location : " << recipient.location << "\n\n" << endl;

	}
}

int main() {

	vector<Donor> donors =
	{
		{"John Doe", "A+", "Auckland", false},
		{"Alice Johnson", "B-", "Wellington", true},
		{"Adam Edden", "O+", "Christchurch", true}
	};

	vector<Recipient> recipients =
	{
		{"Bill Brown", "AB+", "Queenstown"},
		{"Joyce Smith", "A+", "Rotorua"}
	};

	updateBloodTestReport(donors, "John Doe", true);
	generateBloodGroupReport(donors, "A+");
	generateLocationReport(donors, "Auckland");
	generateRecipientReport(recipients);

	return 0;
}