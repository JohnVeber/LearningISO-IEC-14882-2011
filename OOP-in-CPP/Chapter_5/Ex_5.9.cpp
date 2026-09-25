#include <iostream>
#include <iomanip>  // for setw() and setfill()
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void swap(Time& a, Time& b);

//--------------------------------------------------------
int main() {
    Time t1, t2;

    // --- input t1 ---
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

    // --- input t2 ---
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

    // --- output before swap ---
    cout << "\nBefore swap: t1 = "
         << setw(2) << setfill('0') << t1.hours << ":"
         << setw(2) << setfill('0') << t1.minutes << ":"
         << setw(2) << setfill('0') << t1.seconds << endl;

    cout << "             t2 = "
         << setw(2) << setfill('0') << t2.hours << ":"
         << setw(2) << setfill('0') << t2.minutes << ":"
         << setw(2) << setfill('0') << t2.seconds << endl;

    // --- swap ---
    swap(t1, t2);

    // --- output after swap ---
    cout << "After  swap: t1 = "
         << setw(2) << setfill('0') << t1.hours << ":"
         << setw(2) << setfill('0') << t1.minutes << ":"
         << setw(2) << setfill('0') << t1.seconds << endl;

    cout << "             t2 = "
         << setw(2) << setfill('0') << t2.hours << ":"
         << setw(2) << setfill('0') << t2.minutes << ":"
         << setw(2) << setfill('0') << t2.seconds << endl;

    return 0;
}

//--------------------------------------------------------
// Swaps two Time values. Parameters are references, so the original structs are modified.
void swap(Time& a, Time& b) {
    Time temp = a;
    a = b;
    b = temp;
}