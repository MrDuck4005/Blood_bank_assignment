#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct DonationBooking {
    string fullName;
    string dob;
    string recentHealthCondition;
    string date;
    string time;
};

class BookingSystem {
public:
    void bookDonationSlot() {
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

private:
    vector<DonationBooking> bookings;

    bool isSlotAvailable(const string& date, const string& time) {
        for (const auto& booking : bookings) {
            if (booking.date == date && booking.time == time) {
                return false;
            }
        }
        return true;
    }

    bool isValidTime(const string& time) {
        // Check if time is in hh:mm format
        regex timePattern(R"((0[9]|1[0-6]):[0-5][0-9])");
        if (!regex_match(time, timePattern))
            return false;

        return true;
    }

    bool isValidDateFormat(const string& date) {
        regex datePattern(R"(\d{2}[/-]\d{2}[/-]\d{4})");
        return regex_match(date, datePattern);
    }

    string formatWithSlashes(const string& date) {
        if (date.size() == 8) {
            return date.substr(0, 2) + "/" + date.substr(2, 2) + "/" + date.substr(4);
        }
        return date;
    }
};

int main() {
    BookingSystem bookingSystem;
    bookingSystem.bookDonationSlot();

    return 0;
}
