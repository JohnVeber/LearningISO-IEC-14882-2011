#include <iostream>
#include <iomanip>  // for setw() and setfill()
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time t1; // 1st value

    cout << "Enter the first value (hours, minutes and seconds).";
    cout << "\nEnter hours (0-23): ";
    if (!(cin >> t1.hours) || t1.hours < 0 || t1.hours > 23) {
        cout << "Error: Hours must be between 0 and 23." << endl;
        return 1;
    }

    cout << "Enter minutes (0-59): ";
    if (!(cin >> t1.minutes) || t1.minutes < 0 || t1.minutes > 59) {
        cout << "Error: Minutes must be between 0 and 59." << endl;
        return 2;
    }

    cout << "Enter seconds (0-59): ";
    if (!(cin >> t1.seconds) || t1.seconds < 0 || t1.seconds > 59) {
        cout << "Error: Seconds must be between 0 and 59." << endl;
        return 3;
    }

    // Convert first time to seconds
    long t1_secs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;

    Time t2; // 2nd value

    cout << "Enter the second value (hours, minutes and seconds).";
    cout << "\nEnter hours (0-23): ";
    if (!(cin >> t2.hours) || t2.hours < 0 || t2.hours > 23) {
        cout << "Error: Hours must be between 0 and 23." << endl;
        return 4;
    }

    cout << "Enter minutes (0-59): ";
    if (!(cin >> t2.minutes) || t2.minutes < 0 || t2.minutes > 59) {
        cout << "Error: Minutes must be between 0 and 59." << endl;
        return 5;
    }

    cout << "Enter seconds (0-59): ";
    if (!(cin >> t2.seconds) || t2.seconds < 0 || t2.seconds > 59) {
        cout << "Error: Seconds must be between 0 and 59." << endl;
        return 6;
    }

    // Convert second time to seconds
    long t2_secs = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Total seconds
    long total_secs = t1_secs + t2_secs;

    // Convert total seconds back to hours, minutes, and seconds
    // 1 hour = 3600 seconds, 1 minute = 60 seconds
    Time t3;
    t3.hours = static_cast<int>(total_secs / 3600);     // Extract hours
    int remainder = total_secs % 3600;                  // Remaining seconds after extracting hours
    t3.minutes = static_cast<int>(remainder / 60);      // Extract minutes from remaining seconds
    t3.seconds = remainder % 60;                        // Remaining seconds after extracting minutes

    // Handle overflow: if hours exceed 23, wrap around (24-hour clock)
    if (t3.hours >= 24) {
        t3.hours = t3.hours % 24;  // Reset to 0 after 24 hours
    }

    // Output with leading zeros
    cout << "The sum of entered time values is: "
         << setw(2) << setfill('0') << t3.hours << ":"
         << setw(2) << setfill('0') << t3.minutes << ":"
         << setw(2) << setfill('0') << t3.seconds << endl;

    return 0;
}

// TODO:
// 1) Add input validation to reject values with leading zeros (e.g., "034" instead of "34").
// 2) Ensure that each field contains exactly an expected number of digits.