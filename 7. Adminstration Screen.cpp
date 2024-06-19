#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Donor {
    std::string name;
    std::string bloodGroup;
    std::string testingReport;
};

struct Recipient {
    std::string name;
    std::string bloodGroup;
    std::string location;
};

std::vector<Donor> donors;
std::vector<Recipient> recipients;

// Function prototypes
void updateTestingReport();
void generateDonorReport();
void generateReportByBloodGroup(const std::string& bloodGroup);
void generateReportByLocation(const std::string& location);
void generateRecipientReport();

int main() {
    int choice;
    do {
        // Display menu
        std::cout << "\nBlood Bank Administration System\n";
        std::cout << "1. Update Donor's Testing Report\n";
        std::cout << "2. Generate Donor Report\n";
        std::cout << "3. Generate Report by Blood Group\n";
        std::cout << "4. Generate Report by Location\n";
        std::cout << "5. Generate Recipient Report\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        // Process user choice
        switch(choice) {
            case 1:
                updateTestingReport();
                break;
            case 2:
                generateDonorReport();
                break;
            case 3: {
                std::string bloodGroup;
                std::cout << "Enter blood group: ";
                std::getline(std::cin, bloodGroup);
                generateReportByBloodGroup(bloodGroup);
                break;
            }
            case 4: {
                std::string location;
                std::cout << "Enter location: ";
                std::getline(std::cin, location);
                generateReportByLocation(location);
                break;
            }
            case 5:
                generateRecipientReport();
                break;
            case 6:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter again.\n";
        }
    } while(choice != 6);

    return 0;
}

void updateTestingReport() {
    std::string name;
    std::cout << "\nEnter Donor's Name to Update Testing Report: ";
    std::getline(std::cin, name);

    // Search for the donor by name
    auto it = std::find_if(donors.begin(), donors.end(), [&name](const Donor& d) {
        return d.name == name;
    });

    if (it != donors.end()) {
        std::cout << "Enter new Testing Report: ";
        std::getline(std::cin, it->testingReport);
        std::cout << "Testing Report updated successfully.\n";
    } else {
        std::cout << "Donor not found.\n";
    }
}

void generateDonorReport() {
    std::cout << "\nDonor Report:\n";
    for (const auto& donor : donors) {
        std::cout << "Name: " << donor.name << ", Blood Group: " << donor.bloodGroup
                  << ", Testing Report: " << donor.testingReport << "\n";
    }
}

void generateReportByBloodGroup(const std::string& bloodGroup) {
    std::cout << "\nReport for Blood Group " << bloodGroup << ":\n";
    for (const auto& donor : donors) {
        if (donor.bloodGroup == bloodGroup) {
            std::cout << "Name: " << donor.name << ", Testing Report: " << donor.testingReport << "\n";
        }
    }
}

void generateReportByLocation(const std::string& location) {
    std::cout << "\nReport for Location " << location << ":\n";
    for (const auto& recipient : recipients) {
        if (recipient.location == location) {
            std::cout << "Recipient Name: " << recipient.name << ", Blood Group: " << recipient.bloodGroup << "\n";
        }
    }
}

void generateRecipientReport() {
    std::cout << "\nRecipient Report:\n";
    for (const auto& recipient : recipients) {
        std::cout << "Name: " << recipient.name << ", Blood Group: " << recipient.bloodGroup
                  << ", Location: " << recipient.location << "\n";
    }
}

