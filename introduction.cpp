#include "header.h"

// Global maps definition
map<string, Donor> donors;
map<string, Recipient> recipients;
map<string, Request> requests;
map<string, Booking> bookings;
map<string, string> admins;

// Function to load initial data from files
void loadInitialData() {
    loadFiles();  // Load initial data from files
}

// Function to load data from text files into maps
void loadFiles() {
    // Load donor data
    ifstream donorFile("donors.txt");
    string line;
    while (getline(donorFile, line)) {
        stringstream ss(line);
        string firstName, lastName, contactNo, bloodGroup, password;
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, contactNo, ',');
        getline(ss, bloodGroup, ',');
        getline(ss, password, ',');

        Donor donor;
        donor.firstName = firstName;
        donor.lastName = lastName;
        donor.bloodGroup = bloodGroup;
        donor.contactNo = contactNo;
        donor.password = password;
        donor.availability = true;  // Assuming availability should be set to true
        donors[firstName + " " + lastName] = donor;
    }
    donorFile.close();

    // Load recipient data
    ifstream recipientFile("recipients.txt");
    while (getline(recipientFile, line)) {
        stringstream ss(line);
        string firstName, lastName, contactNo, password;
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, contactNo, ',');
        getline(ss, password, ',');

        Recipient recipient;
        recipient.fullName = firstName + " " + lastName;
        recipient.contactNo = contactNo;
        recipient.password = password;
        recipient.isAdmin = false;  // Assuming isAdmin should be set to false
        recipients[firstName + " " + lastName] = recipient;
    }
    recipientFile.close();

    // Load requests data
    ifstream requestFile("requests.txt");
    while (getline(requestFile, line)) {
        stringstream ss(line);
        string recipientName, donorName, bloodGroup;
        getline(ss, recipientName, ',');
        getline(ss, donorName, ',');
        getline(ss, bloodGroup, ',');

        Request request(recipientName, donorName, bloodGroup);
        requests[recipientName + " " + donorName] = request;
    }
    requestFile.close();

    // Load booking data (assuming Booking structure is defined)
    ifstream bookingFile("bookings.txt");
    while (getline(bookingFile, line)) {
        stringstream ss(line);
        string donorName, recipientName, date, time;
        getline(ss, donorName, ',');
        getline(ss, recipientName, ',');
        getline(ss, date, ',');
        getline(ss, time, ',');

        Booking booking = { donorName, recipientName, date, time }; // Assuming Booking structure has appropriate fields
        bookings[donorName + " " + date + " " + time] = booking;
    }
    bookingFile.close();

    // Load admin data (hardcoded for simplicity)
    admins["admin"] = "admin";
}

// Function to handle registration process
void registerMenu() {
    int registerChoice;
    cout << "\nRegister as:" << endl;
    cout << "1. Donor" << endl;
    cout << "2. Recipient" << endl;
    cout << "Enter your choice: ";
    cin >> registerChoice;

    switch (registerChoice) {
    case 1:
        registerDonor(); // Register as donor
        break;
    case 2:
        registerRecipient(); // Register as recipient
        break;
    default:
        cout << "Invalid choice. Returning to main menu." << endl;
        break;
    }
}

// Function to handle login process
void loginMenu() {
    int loginChoice;
    cout << "\nLogin as:" << endl;
    cout << "1. Donor" << endl;
    cout << "2. Recipient" << endl;
    cout << "Enter your choice: ";
    cin >> loginChoice;

    switch (loginChoice) {
    case 1:
        loginDonor();
        break;
    case 2:
        // Implement loginRecipient() function
        // loginRecipient();
        break;
    default:
        cout << "Invalid choice. Returning to main menu." << endl;
        break;
    }
}

// Function to handle admin login and functionality
void adminMenu() {
    string adminUsername, adminPassword;
    cout << "\nEnter admin username: ";
    cin >> adminUsername;
    cout << "Enter admin password: ";
    cin >> adminPassword;

    // Check admin credentials (assuming hardcoded for simplicity)
    if (adminUsername == "admin" && adminPassword == "admin") {
        cout << "Admin login successful!" << endl;
        // Proceed with admin menu functionality
        // adminFunctionality(); // Implement admin functionality
    }
    else {
        cout << "Admin login failed. Invalid credentials." << endl;
    }
}

// Function to register a new donor
void registerDonor() {
    string firstName, lastName, contactNo, bloodGroup, password;
    cout << "\nEnter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter contact number: ";
    cin >> contactNo;
    cout << "Enter blood group: ";
    cin >> bloodGroup;
    cout << "Enter password: ";
    cin >> password;

    // Create Donor object using initializer list
    Donor donor;
    donor.firstName = firstName;
    donor.lastName = lastName;
    donor.contactNo = contactNo;
    donor.bloodGroup = bloodGroup;
    donor.password = password;
    donor.availability = true;

    // Write to donors.txt file
    ofstream donorFile("donors.txt", ios::app);
    donorFile << firstName << "," << lastName << "," << contactNo << "," << bloodGroup << "," << password << endl;
    donorFile.close();

    // Add to donors map
    donors[firstName + " " + lastName] = donor;

    cout << "Registered successfully!" << endl;
}

// Function to register a new recipient
void registerRecipient() {
    string firstName, lastName, contactNo, password;
    cout << "\nEnter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter contact number: ";
    cin >> contactNo;
    cout << "Enter password: ";
    cin >> password;

    // Create Recipient object
    Recipient recipient;
    recipient.fullName = firstName + " " + lastName;
    recipient.contactNo = contactNo;
    recipient.password = password;
    recipient.isAdmin = false;

    // Write to recipients.txt file
    ofstream recipientFile("recipients.txt", ios::app);
    recipientFile << firstName << "," << lastName << "," << contactNo << "," << password << endl;
    recipientFile.close();

    // Add to recipients map
    recipients[firstName + " " + lastName] = recipient;

    cout << "Registered successfully!" << endl;
}

// Function to log in as a donor
void loginDonor() {
    string username, password;
    cout << "\nEnter donor username: ";
    cin >> username;
    cout << "Enter donor password: ";
    cin >> password;

    // Check if the donor exists in the map and if the password matches
    if (donors.find(username) != donors.end() && donors[username].password == password) {
        cout << "Logged in as Donor: " << username << endl;
        // Call donor menu function with username
        donorMenu(username);
    }
    else {
        cout << "Login failed. Invalid username or password." << endl;
    }
}

// Implement donor and recipient menus if needed
void donorMenu(const string& name) {
    // Implement donor menu functionality here
}

void recipientMenu(const string& name) {
    // Implement recipient menu functionality here
}
