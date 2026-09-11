#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time t1;

    cout << "Enter hours (0-23): ";
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

    long total_secs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;

    cout << "Total seconds in the entered time: " << total_secs << endl;

    return 0;
}