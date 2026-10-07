#include <iostream>
#include <iomanip> // For setprecision().
using namespace std;

class tollBooth {
private:
    unsigned int carsPassed;
    double totalIncome;

public:
    tollBooth() : carsPassed(0), totalIncome(0) { } // Default constructor: initializes both values to zero.

    // Method for incrementing cars amount and total income.
    void payingCar() {
        carsPassed++;
        totalIncome += 0.50;
    }

    // Method for incrementing just cars amount.
    void nopayCar() {
        carsPassed++;
    }

    // Method displays both fields (constant method).
    void display() const {
        cout << "The value of the fields are:\n"
             << " carsPassed  : " << carsPassed
             << "\n totalIncome : " << fixed << "$" << setprecision(2)
             << totalIncome << endl;
    }
};

int main() {
    const char ESC = '\x1B'; // ASCII code of the Escape key.

    tollBooth t1;
    char button = 0;

    cout << "Press 'Y'/'y' to imitate a paid car, "
         << "'N'/'n' to imitate a non-paid car "
         << "(Esc to print results and exit)." << endl;

    do {
        cout << "Your choice: ";
        cin >> button;

        if (button == 'Y' || button == 'y') {
            t1.payingCar();
        }
        else if (button == 'N' || button == 'n') {
            t1.nopayCar();
        }
        // Any other character is ignored.
    }
    while (button != ESC);

    t1.display();

    return 0;
}

// TODO:
// 1) Replace buffered 'cin >> button' with unbuffered per-character input (no Enter required; Esc handled immediately).
// Possible approaches (Debian Linux), from most to least preferable:
//  1. ncurses (<curses.h>): include this header file because it declares all the functions needed for unbuffered per-character input.
//  These functions are called in the following order:
//         initscr() — initializes the ncurses library and switches the terminal into screen mode. Mandatory first call.
//                     Usually clears the screen.
//         cbreak()  — disables terminal-level input buffering, which is exactly what this task requires: each character
//                     becomes available to the program immediately, without waiting for Enter.
//                     Equivalent to raw mode in termios, but implemented as a single call.
//         noecho()  — disables automatic echoing of pressed keys to the screen.
//                     If this function is not called, every key press is displayed on the screen, which is not required in this program.
//         getch()   — reads a single character from the keyboard immediately.
//                     This is the function used in place of 'cin >> button'.
//         endwin()  — shuts down ncurses and restores the terminal to its original state. Mandatory last call; otherwise,
//                     after the program exits, the terminal settings aren't restored (no echo, some key combinations stop working).
//     Requires the 'libncurses-dev' package and the '-lncurses' linker flag.
//  2. termios (<termios.h>, <unistd.h>): switch the terminal to raw mode, read one character, restore the original settings.
//  No external libraries are required (POSIX standard API).
//  3. A helper function (wrapper): instead of calling ncurses or termios directly from main(),
//  put all platform-specific code inside a single function, e.g. 'char getch_unbuffered()'.
//  The function returns one character as soon as a key is pressed. In main(), replace 'cin >> button' with 'button = getch_unbuffered();'.
//  This keeps the rest of the program independent of the chosen input mechanism.