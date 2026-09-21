#include <iostream>
#include <iomanip>  // for setw() and setfill()
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(Time t);
Time secs_to_time(long seconds_amount);

int main() {
    Time t1;

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

    long t1_secs = time_to_secs(t1); // Convert first time to seconds with the 1st function.

    Time t2;

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

    long t2_secs = time_to_secs(t2); // Convert second time with the same function.

    long total_secs = t1_secs + t2_secs; // Calculate total seconds.

    Time t3 = secs_to_time(total_secs); // Convert total seconds to hours, minutes, and seconds with the 2nd function.

    // Output with leading zeros
    cout << "The sum of entered time values is: "
         << setw(2) << setfill('0') << t3.hours << ":"
         << setw(2) << setfill('0') << t3.minutes << ":"
         << setw(2) << setfill('0') << t3.seconds << endl;

    return 0;
}

//--------------------------------------------------------
// Converts a Time value to total seconds.
long time_to_secs(Time t) {
    return t.hours * 3600L + t.minutes * 60L + t.seconds;    // Use suffix to avoid integer overflow.
}

//--------------------------------------------------------
// Converts total seconds to a Time value with normalization.
Time secs_to_time(long seconds_amount) {
    Time t;
    t.hours   = static_cast<int>(seconds_amount / 3600);      // Extract hours
    long rem  = seconds_amount % 3600;                        // Remaining seconds after extracting hours
    t.minutes = static_cast<int>(rem / 60);                   // Extract minutes from remaining seconds
    t.seconds = static_cast<int>(rem % 60);                   // Remaining seconds after extracting minutes

    t.hours %= 24; // Handle overflow: if hours exceed 23, wrap around (24-hour clock)

    return t;
}

// TODO:
// 1) Add input validation to reject values with leading zeros (e.g., "034" instead of "34").