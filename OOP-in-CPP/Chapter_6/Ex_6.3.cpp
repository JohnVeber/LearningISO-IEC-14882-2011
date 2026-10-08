#include <iostream>
#include <iomanip>
using namespace std;

class Time { // Named 'Time' (capitalized) to avoid a name clash with the standard C function 'time()' from <ctime>.
             // The lowercase name 'time' would be ambiguous because <iostream> and <iomanip> bring that function into scope.
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) { } // Default constructor: initializes all fields to zero.

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) { } // Parameterized constructor.

    // Constant method: prints Time in HH:MM:SS format.
    void display() const {
        const char SEP = ':';
        cout << setfill('0')
             << setw(2) << hours << SEP
             << setw(2) << minutes << SEP
             << setw(2) << seconds
             << setfill(' ') << endl;
    }

    // Constant method: adds two Time objects, returns a new Time object.
    // Handles overflow past 24 hours (wraps around).
    Time add(const Time& t1, const Time& t2) const {
        int total = (t1.hours   * 3600 + t1.minutes   * 60 + t1.seconds)
                  + (t2.hours   * 3600 + t2.minutes   * 60 + t2.seconds);
        total %= 24 * 3600; // Wrap around after 24 hours.
        return Time(total / 3600, (total % 3600) / 60, total % 60);
    }
};

int main() {
    const Time t1(11, 59, 59);
    const Time t2(12, 30, 45);
    Time t3;

    t3 = t3.add(t1, t2);

    cout << "t1 = "; t1.display();
    cout << "t2 = "; t2.display();
    cout << "t3 = "; t3.display();

    return 0;
}