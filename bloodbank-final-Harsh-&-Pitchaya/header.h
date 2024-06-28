#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <memory>
#include <cstdlib>
#include <regex>

using namespace std;

// Forward declarations
class Donor;
class Recipient;
class Request;
class Request;
struct Booking;

// Global maps
extern map<string, Donor> donors;
extern map<string, Recipient> recipients;
extern map<string, Request> requests;
extern map<string, Booking> bookings;
extern map<string, string> admins;

// Class definitions
class Donor {

public:
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
    string city;
    string lastDonationDate;
    string username;
    string password;
    string testingReport;
    bool availability;

    Donor() : availability(true) {}

    Donor(string n, string c, string a, string h)
        : firstName(n), contactNo(c), address(a), conditions(h), availability(true) {}

    string getFirstName() const{ return firstName; } 
    string getContactNo() const{ return contactNo; } 
    string getAddress() const{ return address; }
    string getConditions() const {return conditions; } 

    void setContactNo(string c) { contactNo = c; } 
    void setAddress(string a) { address = a; }
    void setConditions(string h) { conditions = h; } 
};

class Recipient {
public:
    string name;
    string address;
    string email;
    string contactNo;
    string username;
    string password;
    bool validationStatus;

    Recipient(const string& name = "", const string& address = "", const string& email = "",
        const string& contactNo = "", const string& username = "", const string& password = "",
        bool validationStatus = false)
        : name(name), address(address), email(email), contactNo(contactNo),
        username(username), password(password), validationStatus(validationStatus) {}

};

class Request {
public:
    std::string recipientName;
    std::string donorName;
    std::string bloodGroup;

    // Default constructor
    Request()
        : recipientName(""), donorName(""), bloodGroup("") {}

    // Parameterized constructor
    Request(const std::string& recipient, const std::string& donor, const std::string& blood)
        : recipientName(recipient), donorName(donor), bloodGroup(blood) {}
};

// Define Booking structure with members
struct Booking {
    string donorName;
    string recipientName;
    string date;
    string time;
};

struct DonationBooking {
    string fullName;
    string dob;
    string recentHealthCondition;
    string date;
    string time;
};

class BookingSystem {
public:
    void bookDonationSlot();
    void viewAllBookings(); // Function to view all bookings

private:
    std::vector<DonationBooking> bookings;

    bool isSlotAvailable(const std::string& date, const std::string& time);
    bool isValidTime(const std::string& time);
    bool isValidDateFormat(const std::string& date);
    std::string formatWithSlashes(const std::string& date);
};

// Function prototypes
int main();
void loadFiles();
void registerDonor();
void registerRecipient();
void donorLogin();
void recipientLogin();
void donorMenu();
void recipientMenu(const string& name);
void adminMenu();
void adminLogin();
void donateBlood();
void showBenefits();
void manageInfo(Donor& donor);
void registerMenu();     // Added function prototype
void loginMenu();        // Added function prototype
void displayMainMenu();  // Added function prototype
void loadInitialData();

void viewAllDonors();
void generateReportByLocation(const std::string& location);

void updateTestingReport();
void generateDonorReport();
void generateReportByBloodGroup(const string& bloodGroup);
void generateRecipientReport();
void displayRecipient(const Recipient& recipient);

string toLower(string str);
string capitalize(string str);
void accessBloodGroup(const vector<Donor>& donorList);
void accessByBloodGroupAndLocation(const vector<Donor>& donorList);
void findPotentialDonors(const vector<Donor>& donorList);


//header and footers
int header();


#endif // HEADER_H



