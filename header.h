#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

// Forward declarations
class Donor;
class Recipient;
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
    string contactNo;
    string bloodGroup;
    string password;
    bool availability;

    Donor() : availability(true) {}
};

class Recipient {
public:
    std::string fullName;
    std::string username;  // New field
    std::string contactNo;
    std::string password;  // New field
    bool isAdmin;

    Recipient()
        : fullName(""), username(""), contactNo(""), password(""), isAdmin(false) {}

    Recipient(const std::string& name, const std::string& user, const std::string& contact, const std::string& pass, bool admin = false)
        : fullName(name), username(user), contactNo(contact), password(pass), isAdmin(admin) {}
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

// Function prototypes
void loadFiles();
void registerDonor();
void registerRecipient();
void loginDonor();
void donorMenu(const string& name);
void recipientMenu(const string& name);
void adminMenu();
void viewDonorInfo();
void viewRecipientInfo();
void updateDonorReport();
void donorReport();
void reportByBloodGroup();
void reportByLocation();
void registerMenu();     // Added function prototype
void loginMenu();        // Added function prototype
void displayMainMenu();  // Added function prototype
void loadInitialData();

#endif // HEADER_H
