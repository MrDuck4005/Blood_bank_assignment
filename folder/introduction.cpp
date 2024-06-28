#include "header.h"
using namespace std;

// Global maps definition
map<string, Donor> donors;
map<string, Recipient> recipients;
map<string, Request> requests;
map<string, Booking> bookings;
map<string, string> admins;

vector<string> StringSeparator(string raw_msg, char separator = ';') {
    vector<string> baked_msg;
    string word;

    // Read and Split the characters with the separator.
    for (char c : raw_msg) {
        if (c == separator || c == '\0') {
            baked_msg.push_back(word);
            word = "";
            continue;
        }
        word += c;
    }

    if (word != "") {
        baked_msg.push_back(word);
    }

    return baked_msg;
}

vector<Donor> loadDonorDatabase(const string& filename) {
    vector<Donor> donorDatabase;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "error 002! Unable to open file " << filename << endl;
        return donorDatabase;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string firstName, bloodGroup, location, contactNo;
        ss >> firstName >> bloodGroup >> location >> contactNo;
        donorDatabase.emplace_back(firstName, bloodGroup, location, contactNo);
    }

    inFile.close();
    return donorDatabase;
}


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
        string firstName, lastName, contactNo, bloodGroup, username, password;
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, contactNo, ',');
        getline(ss, bloodGroup, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');

        Donor donor;
        donor.firstName = firstName;
        donor.lastName = lastName;
        donor.bloodGroup = bloodGroup;
        donor.contactNo = contactNo;
        donor.username = username;
        donor.password = password;
        donor.availability = true;  // Assuming availability should be set to true
        donors[firstName + " " + lastName] = donor;
    }
    donorFile.close();

    // Load recipient data
    ifstream recipientFile("recipients.txt");
    while (getline(recipientFile, line)) {
        stringstream ss(line);
        string name, contactNo, username, password, address, email;
        getline(ss, name, ',');
        getline(ss, contactNo, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, address, ',');
        getline(ss, email, ',');

        Recipient recipient;
        recipient.name = name;
        recipient.contactNo = contactNo;
        recipient.username = username;
        recipient.password = password;
        recipient.address = address;
        recipient.email = email;
        

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

    system("CLS");

    header();

    registermenu:

    string intialregisterChoice;
    cout << "\nRegister as:" << endl;
    cout << "1. Donor" << endl;
    cout << "2. Recipient" << endl;
    cout << "3. Back" << endl;
    cout << "Enter your choice: ";
    cin >> intialregisterChoice;

    if ((intialregisterChoice == "1") || (intialregisterChoice == "2") || (intialregisterChoice == "3")) {

        int registerChoice = stoi(intialregisterChoice);

        switch (registerChoice) {
        case 1:
            registerDonor(); // Register as donor
            break;
        case 2:
            registerRecipient(); // Register as recipient
            break;

        case 3:
            main();
            break;
        }
    }

    else {
        cout << "Invalid choice. Please try again." << endl;
        goto registermenu;
    }

}

// Function to handle login process
void loginMenu() {

    system("CLS");
    header();

            login_window:

    string strloginChoice;
    cout << "\nLogin as:" << endl;
    cout << "1. Donor" << endl;
    cout << "2. Recipient" << endl;
    cout << "3. Back" << endl;
    cout << "Enter your choice: ";
    cin >> strloginChoice;

    if ((strloginChoice == "1") || (strloginChoice == "2")|| (strloginChoice == "3")) {
        int loginChoice = stoi(strloginChoice);


        switch (loginChoice) {
        case 1:
            donorLogin();
            break;
        case 2:
            recipientLogin();
            break;

        case 3:
            main();
            break;
        }
    }

    else {
        cout << "Invalid choice. Please try again." << endl;
        goto  login_window;
    }
}

// Function to handle admin login and functionality
void adminLogin() {
    system("CLS");
    header();
    string adminUsername, adminPassword;

    for (int i = 0; i < 3; i++) { //3 attempt lock for loop 

        cout << "\nEnter admin username: ";
        cin >> adminUsername;
        cout << "Enter admin password: ";
        cin >> adminPassword;

        // Check admin credentials (assuming hardcoded for simplicity)
        if (adminUsername == "admin" && adminPassword == "admin") {
            cout << "Admin login successful!" << endl;
            adminMenu();
        }

        else {
            cout << "Admin login failed. Invalid credentials. Please try again" << endl;
        }

        if (i >= 2) {       // if attmpet has reached limit 
            system("CLS");
            header();
            cout << "\n\nattempt limit reached, please try again later" << endl;

            exit(0);
        }
    }
}

void adminMenu() {

    system("CLS");
    header();

            admin_menu:
    string stradminchoice;
     
        // Display menu
        cout << "\nBlood Bank Administration System\n";
        cout << "1. Update Donor's Testing Report\n";
        cout << "2. Generate Donor Report\n";
        cout << "3. Generate Report by Blood Group\n";
        cout << "4. Generate Report by Location\n";
        cout << "5. Generate Recipient Report\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> stradminchoice;
        cin.ignore(); // Clear the input buffer

        if ((stradminchoice == "1") || (stradminchoice == "2") || (stradminchoice == "3") || (stradminchoice == "4") || (stradminchoice == "5") || (stradminchoice == "6")) {

            string bloodGroup;
            string location;
            int adminchoice = stoi(stradminchoice);

            // Process user choice
            switch (adminchoice) {
            
            case 1:
                updateTestingReport();
                break;

            case 2:
                generateDonorReport();
                break;

            case 3:
                
                cout << "Enter blood group: ";
                getline(cin, bloodGroup);
                generateReportByBloodGroup(bloodGroup);
                break;

            case 4:
                
                cout << "Enter location: ";
                getline(cin, location);
                generateReportByLocation(location);
                break;

            case 5:
                generateRecipientReport();
                break;

            case 6:
                cout << "Exiting program...\n";
                exit(0);
            }
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            goto  admin_menu;
        }
    

}


// Function to register a new donor
void registerDonor() {
    system("CLS");
    header();

    Donor donor; // Directly using a Donor object instead of unique_ptr

    cin.ignore(1, '\n');

    cout << "Enter First Name: ";
    getline(cin, donor.firstName);

    cout << "Enter Last Name: ";
    getline(cin, donor.lastName);

    cout << "Enter Date of Birth (dd/mm/yyyy): ";
    getline(cin, donor.dob);

    cout << "Enter Nationality: ";
    getline(cin, donor.nationality);

    cout << "Enter Ethnicity: ";
    getline(cin, donor.ethnicity);

    cout << "Enter Gender: ";
    getline(cin, donor.gender);

    cout << "Enter known Health conditions: ";
    getline(cin, donor.conditions);

    cout << "Select Blood Group:\n";
    cout << "1. A\n";
    cout << "2. B\n";
    cout << "3. AB\n";
    cout << "4. O\n";
    cout << "5. Unknown\n";
bloodgroup_menu:
    string strbloodchoice;
    
        cout << "Enter your choice: ";
        cin >> strbloodchoice;
        cin.ignore();

        if ((strbloodchoice == "1") || (strbloodchoice == "2") || (strbloodchoice == "3") || (strbloodchoice == "4") || (strbloodchoice == "5")) {
            int bloodchoice = stoi(strbloodchoice);

        

            switch (bloodchoice) {
            case 1:
                donor.bloodGroup = "A";
                break;
            case 2:
                donor.bloodGroup = "B";
                break;
            case 3:
                donor.bloodGroup = "AB";
                break;
            case 4:
                donor.bloodGroup = "O";
                break;
            case 5:
                donor.bloodGroup = "Unknown";
                break;
            }
        }

        else {
            cout << "Invalid choice. Please try again." << endl;
            goto  bloodgroup_menu;
        }

    cout << "Enter contact number: ";
    getline(cin, donor.contactNo);

    cout << "Enter Email: ";
    getline(cin, donor.email);

    cout << "Enter Address: ";
    getline(cin, donor.address);

    cout << "Enter last date of donation (*optional, leave it blank if none): ";
    getline(cin, donor.lastDonationDate);

    cout << "Enter Username: ";
    getline(cin, donor.username);

    cout << "Enter Password: ";
    getline(cin, donor.password);

    // Write donor information to file
    ofstream outFile("donors.txt", ios::app);
    if (outFile.is_open()) {
        outFile << donor.username << " " << donor.password << " " << donor.firstName << " " << donor.lastName << " " << donor.dob << " " << donor.nationality << " " << donor.ethnicity << " " << donor.gender << " " << donor.conditions << " " << donor.bloodGroup << " " << donor.contactNo << " " << donor.email << " " << donor.address << " " << donor.lastDonationDate << endl;
        cout << "Donor information saved to donors.txt" << endl;
    }
    else {
        cout << "Error 003 Unable to open file." << endl;
    }

    cout << "Donor registered successfully!" << endl;
}

// Function to register a new recipient
void registerRecipient() {

    Recipient recipient;

    cin.ignore(1, '\n');

    cout << "Enter Full Name or Name of hospital or BloodBank : ";
    getline(cin, recipient.name);

    cout << "Enter Physical Address : ";
    getline(cin, recipient.address);

    cout << "Enter Email Address : ";
    getline(cin, recipient.email);

    cout << "Enter Contact No : ";
    getline(cin, recipient.contactNo);

    cout << "Enter Username : ";
    getline(cin, recipient.username);

    cout << "Enter Password : ";
    getline(cin, recipient.password);

    recipient.validationStatus = true;

    // Write recipient information to file
    ofstream outFile("recipients.txt", ios::app);
    if (outFile.is_open()) {
        outFile << recipient.username << " " << recipient.password << " " << recipient.name << " " << recipient.address << " " << recipient.email << " " << recipient.contactNo << endl;
        outFile.close();
        cout << "Recipient registered successfully!" << endl;
    }
    else {
        cout << "Error 004! Unable to open file." << endl;
    }
}


// Function to log in as a donor
void donorLogin() {
    ifstream pull("donors.txt", ios::in);
    string username, password;
    cin.ignore(1, '\n');

    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);

    if (pull.is_open()) {
        string line;
        bool found = false;

        while (getline(pull, line)) {
            vector<string> bline;
            bline = StringSeparator(line, ' ');
            if (bline[0] == username && bline[1] == password) { // Ensure both username and password match
                found = true;
                break;
            }
        }
        pull.close();

        if (found) {
            cout << "Login successful!";
            donorMenu();
        }
        else {
            cout << "Invalid username or password." << endl;
        }
    }
    else {
        cout << "Error 002! Unable to open file." << endl;
    }
}

void recipientLogin() {
    ifstream pull("recipients.txt", ios::in);
    string username, password;
    cin.ignore(1, '\n');

    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);

    if (pull.is_open()) {
        string line;
        bool found = false;

        while (getline(pull, line)) {
            stringstream ss(line);
            string fileUsername, filePassword;
            ss >> fileUsername >> filePassword;
            if (fileUsername == username && filePassword == password) {
                found = true;
                break;
            }
        }
        pull.close();

        if (found) {
            cout << "Login successful!" << endl;
            recipientMenu(username);
        }
        else {
            cout << "Invalid username or password." << endl;
        }
    }
    else {
        cout << "Error 004! Unable to open file." << endl;
    }
}


// Implement donor and recipient menus if needed


void recipientMenu(const string& name) {
recipientMenu:

    system("CLS");
    header();

    vector<Donor> donorDatabase = loadDonorDatabase("recipients.txt");

    string str_recipient_menu;
    
       

        cout << "\nMenu : \n";
        cout << "1. Access donor's Information by blood group \n";
        cout << "2. Access donors by blood group and location \n";
        cout << "3. Potential donors contact details find by giving full name \n";
        cout << "4. Back to main menu\n";
        cout << "5. Exit \n";
        cout << "Enter your choice : ";
        cin >> str_recipient_menu;

        if ((str_recipient_menu == "1") || (str_recipient_menu == "2") || (str_recipient_menu == "3") || (str_recipient_menu == "4") || (str_recipient_menu == "5")) {

            int recipient_menu = stoi(str_recipient_menu);

            switch (recipient_menu) {
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
                main();
            case 5:
                break;
                    cout << "Exiting Program. \n";
                    return;
                break;
            }
        }

        else {
            cout << "Invalid choice. Please try again." << endl;
            goto  recipientMenu;
        }

}

void donorMenu() {
    donormenu:
    system("CLS");
    header();


    string inital_donor_choice;
    
        cout << "\nDonor Menu : \n";
        cout << "1. Procedure to donate blood\n";
        cout << "2. Benefits of blood donation\n";
        cout << "3. Manage Information\n";
        cout << "4. Back to main menu\n";
        cout << "Enter your choice : ";
        cin >> inital_donor_choice;

        if ((inital_donor_choice == "1") || (inital_donor_choice == "2") || (inital_donor_choice == "3") || (inital_donor_choice == "4") || (inital_donor_choice == "5")) {

            int choice = stoi(inital_donor_choice);

            switch (choice) {
            case 1:

                cout << "Procedure to donate blood.\n";
                break;
            case 2:

                cout << "Benefits of blood donation.\n";
                break;
            case 3:

                cout << "Manage information.\n";
                break;
            case 4:
                main();
                break;
            case 5:
                cout << "Exiting Program. \n";
                return;
                break;
            }
        }

        else {
            cout << "Invalid choice. Please try again." << endl;
            goto  donormenu;
        }
    
}

void BookingSystem::bookDonationSlot() {
    DonationBooking newBooking;

    cout << "Enter Full Name: ";
    getline(cin, newBooking.fullName);

    cout << "Enter Date of Birth (DOB) (dd/mm/yyyy): ";
    getline(cin, newBooking.dob);
    while (!isValidDateFormat(newBooking.dob)) {
        cout << "Invalid date format. Please enter date in dd/mm/yyyy format: ";
        getline(cin, newBooking.dob);
    }

    cout << "Enter Recent Health Condition: ";
    getline(cin, newBooking.recentHealthCondition);

    cout << "Enter Date (dd/mm/yyyy): ";
    getline(cin, newBooking.date);
    while (!isValidDateFormat(newBooking.date)) {
        cout << "Invalid date format. Please enter date in dd/mm/yyyy format: ";
        getline(cin, newBooking.date);
    }

    cout << "Enter Preferred Time (hh:mm): ";
    getline(cin, newBooking.time);

    while (!isValidTime(newBooking.time)) {
        cout << "Invalid time. Please enter a time between 09:00 and 16:00: ";
        getline(cin, newBooking.time);
    }

    if (isSlotAvailable(newBooking.date, newBooking.time)) {
        bookings.push_back(newBooking);
        cout << "Booking successful!\n";

        // Display the details of the newly booked slot
        cout << "\nNew Booking Details:\n";
        cout << "Full Name: " << newBooking.fullName << endl;
        cout << "Date of Birth (DOB): " << formatWithSlashes(newBooking.dob) << endl;
        cout << "Recent Health Condition: " << newBooking.recentHealthCondition << endl;
        cout << "Date: " << formatWithSlashes(newBooking.date) << endl;
        cout << "Preferred Time: " << newBooking.time << endl;
    }
    else {
        cout << "Sorry, the slot is already taken. Please choose another time.\n";
    }
}

bool BookingSystem::isSlotAvailable(const string& date, const string& time) {
    for (const auto& booking : bookings) {
        if (booking.date == date && booking.time == time) {
            return false;
        }
    }
    return true;
}

bool BookingSystem::isValidTime(const string& time) {
    // Check if time is in hh:mm format
    regex timePattern(R"((0[9]|1[0-6]):[0-5][0-9])");
    return regex_match(time, timePattern);
}

bool BookingSystem::isValidDateFormat(const string& date) {
    regex datePattern(R"(\d{2}[/-]\d{2}[/-]\d{4})");
    return regex_match(date, datePattern);
}

string BookingSystem::formatWithSlashes(const string& date) {
    if (date.size() == 8) {
        return date.substr(0, 2) + "/" + date.substr(2, 2) + "/" + date.substr(4);
    }
    return date;
}

void BookingSystem::viewAllBookings() {
    cout << "\nAll Bookings:\n";
    for (const auto& booking : bookings) {
        cout << "Full Name: " << booking.fullName << ", DOB: " << booking.dob
            << ", Health Condition: " << booking.recentHealthCondition << ", Date: "
            << booking.date << ", Time: " << booking.time << "\n";
    }
}

// Function to view all donors
void viewAllDonors() {
    cout << "\nAll Donors:\n";
    for (const auto& donor : donors) {
        cout << "Name: " << donor.second.firstName << " " << donor.second.lastName << "\n";
        cout << "Date of Birth: " << donor.second.dob << "\n";
        cout << "Nationality: " << donor.second.nationality << "\n";
        cout << "Ethnicity: " << donor.second.ethnicity << "\n";
        cout << "Gender: " << donor.second.gender << "\n";
        cout << "Health Conditions: " << donor.second.conditions << "\n";
        cout << "Blood Group: " << donor.second.bloodGroup << "\n";
        cout << "Contact Number: " << donor.second.contactNo << "\n";
        cout << "Email: " << donor.second.email << "\n";
        cout << "Address: " << donor.second.address << "\n";
        cout << "Last Donation Date: " << donor.second.lastDonationDate << "\n";
        cout << "Username: " << donor.second.username << "\n";
        cout << "Password: " << donor.second.password << "\n";
        cout << "Testing Report: " << donor.second.testingReport << "\n";
        cout << "--------------------------------------\n";
    }
}

// Function to generate a report by location
void generateReportByLocation(const std::string& location) {
    cout << "\nReport for Location " << location << ":\n";
    bool found = false;

    for (const auto& recipient : recipients) {
        if (recipient.second.address == location) {
            found = true;
            cout << "Recipient Name: " << recipient.first << ", Blood Group: " <<  "\n";
        }
    }

    if (!found) {
        cout << "No recipients found for Location " << location << ".\n";
    }
}


void updateTestingReport() {
    string username;
    cout << "\nEnter Donor's Username to Update Testing Report: ";
    getline(cin, username);

    auto it = find_if(donors.begin(), donors.end(), [&username](const pair<string, Donor>& d) {
        return d.second.username == username;
        });

    if (it != donors.end()) {
        cout << "Enter new Testing Report: ";
        getline(cin, it->second.testingReport);
        cout << "Testing Report updated successfully.\n";
    }
    else {
        cout << "Donor not found.\n";
    }
}

void generateDonorReport() {
    cout << "\nDonor Report:\n";
    for (const auto& donor : donors) {
        cout << "Name: " << donor.second.firstName << " " << donor.second.lastName
            << ", Blood Group: " << donor.second.bloodGroup
            << ", Testing Report: " << donor.second.testingReport << "\n";
    }
}

void generateReportByBloodGroup(const string& bloodGroup) {
    cout << "\nReport for Blood Group " << bloodGroup << ":\n";
    for (const auto& donor : donors) {
        if (donor.second.bloodGroup == bloodGroup) {
            cout << "Name: " << donor.second.firstName << " " << donor.second.lastName
                << ", Testing Report: " << donor.second.testingReport << "\n";
        }
    }
}

void generateRecipientReport() {
    cout << "\nRecipient Report:\n";
    for (const auto& recipient : recipients) {
        cout << "Name: " << recipient.second.name << ", Blood Group: "
            << ", Location: " << recipient.second.address << "\n";
    }
}


void displayRecipient(const Recipient& recipient) {
    cout << "Recipient's Name: " << recipient.name << endl;
    cout << "Recipient's Address: " << recipient.address << endl;
    cout << "Recipient's Email: " << recipient.email << endl;
    cout << "Recipient's Contact Number: " << recipient.contactNo << endl;
    cout << "Recipient's Validation Status: " << (recipient.validationStatus ? "Valid" : "Not Valid") << endl;
}

string toLower(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Convert uppercase to lowercase
        }
    }
    return str;
}

string capitalize(string str) {
    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
    return str;
}

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
        string storedBloodGroup = toLower(donor.bloodGroup);
        if (storedBloodGroup == lowerBloodGroup) {
            cout << "Name: " << donor.firstName << " " << donor.lastName << ", Location: " << donor.city << ", Contact: " << donor.contactNo << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No donors found with blood group " << bloodGroup << endl;
    }
}

void accessByBloodGroupAndLocation(const vector<Donor>& donorList) {
    string bloodGroup, location;
    cout << "Enter blood group: ";
    cin >> bloodGroup;

    // Convert input to lowercase and capitalize if necessary
    string lowerBloodGroup = toLower(bloodGroup);
    bloodGroup = capitalize(bloodGroup);

    bool found = false;
    cout << "Donors with blood group " << bloodGroup << ":" << endl;
    for (const auto& donor : donorList) {
        // Convert stored blood group to lowercase for comparison
        string storedBloodGroup = toLower(donor.bloodGroup);

        if (storedBloodGroup == lowerBloodGroup) {
            cout << "Name: " << donor.firstName << ", Contact: " << donor.contactNo << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No donors found with blood group " << bloodGroup << endl;
    }
}



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
        if (donor.firstName + " " + donor.lastName == fullname) {
            cout << "Potential donor found : " << fullname << endl;
            cout << "Blood Group : " << donor.bloodGroup << ", Location : " << donor.city << ", Contact : " << donor.contactNo << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No potential donor found " << fullname << endl;
    }
}


void  donateBlood() {
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
        donor.setContactNo(newContact);
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
        donor.setConditions(newHealthStatus);
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
    cout << "Name : " << donor.getFirstName() << endl;
    cout << "Contact Details : " << donor.getContactNo() << endl;
    cout << "Address : " << donor.getAddress() << endl;
    cout << "Health Status : " << donor.getConditions() << endl;
}
