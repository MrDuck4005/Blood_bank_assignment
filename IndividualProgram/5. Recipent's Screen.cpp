#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a structure for donor information
struct Donor {
    string name;
    string bloodgroup;
    string location;
    string contactdetails;
};

// Function to convert string to lowercase
string toLower(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Convert uppercase to lowercase
        }
    }
    return str;
}

// Function to capitalize the first letter of a string
string capitalize(string str) {
    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
    return str;
}

// Function to search donors by blood group
void accessBloodGroup(const vector<Donor>& donorList) {
    string bloodGroup;
    cout << "Enter blood group: ";
    cin >> bloodGroup;

    // Convert input to lowercase and capitalize if necessary
    string lowerBloodGroup = toLower(bloodGroup);
    bloodGroup = capitalize(bloodGroup);

    bool found = false;
    cout << "Donors with blood group " << bloodGroup << ":" << endl;
    for (const auto& donor : donorList) {
        // Convert stored blood group to lowercase for comparison
        string storedBloodGroup = toLower(donor.bloodgroup);
        if (storedBloodGroup == lowerBloodGroup) {
            cout << "Name: " << donor.name << ", Location: " << donor.location << ", Contact: " << donor.contactdetails << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No donors found with blood group " << bloodGroup << endl;
    }
}



// Function to search donors by blood group and location
void accessByBloodGroupAndLocation(const vector<Donor>& donorList) {
    string bloodGroup, location;
    cout << "Enter blood group: ";
    cin >> bloodGroup;
    cout << "Enter location: ";
    cin >> location;

    // Convert inputs to lowercase and capitalize if necessary
    bloodGroup = toLower(bloodGroup);
    location = toLower(location);
    bloodGroup = capitalize(bloodGroup);
    location = capitalize(location);

    bool found = false;
    cout << "Donors with blood group " << bloodGroup << " in " << location << ":" << endl;
    for (const auto& donor : donorList) {
        // Convert stored blood group and location to lowercase for comparison
        string storedBloodGroup = toLower(donor.bloodgroup);
        string storedLocation = toLower(donor.location);

        if (storedBloodGroup == bloodGroup && storedLocation == location) {
            cout << "Name: " << donor.name << ", Contact: " << donor.contactdetails << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No donors found with blood group " << bloodGroup << " in " << location << endl;
    }
}




// Function to find potential donors by full name
void findPotentialDonors(const vector<Donor>& donorList) {
    string fullname;
    cout << "Enter full name : ";
    cin.ignore();
    getline(cin, fullname);

    // Capitalize the first letter of each word in the full name
    bool capNext = true;
    for (int i = 0; i < fullname.length(); ++i) {
        if (capNext && islower(fullname[i])) {
            fullname[i] = toupper(fullname[i]);
            capNext = false;
        }
        else if (isspace(fullname[i])) {
            capNext = true;
        }
    }

    bool found = false;
    for (const auto& donor : donorList) {
        if (donor.name == fullname) {
            cout << "Potential donor found : " << fullname << endl;
            cout << "Blood Group : " << donor.bloodgroup << ", Location : " << donor.location << ", Contact : " << donor.contactdetails << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No potential donor found " << fullname << endl;
    }
}

int main() {

    // Database to store donors
    vector<Donor> donorDatabase = {
        {"John Doe", "A", "Auckland" , "022-222-3333"},
        {"Steve Albert", "B+", "Wellington", "027-444-2345"},
        {"Dylan Johnson", "O-", "Christchurch", "021-987-6543"}
    };

    int choice;
    do {
        cout << "\nMenu : \n";
        cout << "1. Access donor's Information by blood group \n";
        cout << "2. Access donors by blood group and location \n";
        cout << "3. Potential donors contact details find by giving full name \n";
        cout << "4. Exit \n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            accessBloodGroup(donorDatabase);
            break;
        case 2:
            accessByBloodGroupAndLocation(donorDatabase);
            break;
        case 3:
            findPotentialDonors(donorDatabase);
            break;
        case 4:
            cout << "Exiting Program. \n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4. \n";
        }
    } while (choice != 4);

    return 0;
}
