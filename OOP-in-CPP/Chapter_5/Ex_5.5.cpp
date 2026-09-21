#include <iostream>
using namespace std;

long hms_to_secs(int hours, int minutes, int seconds);

int main(){
    int h, m, s;
    char yesNo;

    do {
        cout << "\nEnter hours: ";   cin >> h;
        cout << "Enter minutes: ";   cin >> m;
        cout << "Enter seconds: ";   cin >> s;

        long total = hms_to_secs(h, m, s);
        cout << "Total seconds: " << total << endl;

        cout << "\nDo you want to continue? (y/n): ";
        cin >> yesNo;
    } while (yesNo == 'y' || yesNo == 'Y');

    return 0;
}

//--------------------------------------------------------
// Converts hours, minutes, seconds to total seconds.
long hms_to_secs(int hours, int minutes, int seconds){
    return hours * 3600L + minutes * 60L + seconds;    // Use suffix to avoid integer overflow.
}

// TODO:
// 1) Validate h, m and s values (positive integers are expected only).