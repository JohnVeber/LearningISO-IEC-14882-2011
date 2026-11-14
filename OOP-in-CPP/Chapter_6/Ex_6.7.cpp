#include <iostream>
#include <cstdlib> // For exit() usage.
using namespace std;

class Angle {
    private:
        char direction;
        int degrees;
        float minutes;
    public:
        Angle(char dr, int dg, float m) : direction(dr), degrees(dg), minutes(m) { // Parameterized constructor with validation.
            // 1. Validate direction.
            if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W') {
                cerr << "Error: direction must be one of 'N', 'S', 'E', 'W'." << endl;
                exit(1);
            }
            // 2. Validate degrees range, which depends on the direction.
            int maxDegrees = (direction == 'E' || direction == 'W') ? 180 : 90; // New local variable inside constructor.
            if (degrees < 0 || degrees > maxDegrees) {
                cerr << "Error: degrees must be between 0 and " << maxDegrees << " for direction " << direction << "." << endl;
                exit(1);
            }
            // 3. Validate minutes range.
            if (minutes < 0.0f || minutes >= 60.0f) {
                cerr << "Error: minutes must be in the range [0, 60)." << endl; // [0, 60) is a half-open interval: 0 is included, 60 is excluded.
                exit(1);
            }
            // 4. At the maximum degrees, minutes must be exactly zero.
            if (degrees == maxDegrees && minutes > 0.0f) { // Use '>' instead of '!=' to avoid float comparison issues.
                cerr << "Error: at " << maxDegrees << " degrees, minutes must be 0 (no additional minutes are allowed)." << endl;
                exit(1);
            }
        }

        void setCoords(){
            // Some temporary variables to avoid inconsistent state between step 1 and 2.
            char newDirection;
            int newDegrees;
            float newMinutes;
            // 1. Input and validate direction into a temporary variable.
            while (true) {
                cout << "Enter direction: ";
                cin >> newDirection;
                if (newDirection != 'N' && newDirection != 'S' && newDirection != 'E' && newDirection != 'W') {
                    cerr << "Error: direction must be one of 'N', 'S', 'E', 'W'." << endl;
                    continue;
                }
                break;
            }
            // 2. Compute the maximum allowed degrees based on the validated direction.
            int maxDegrees = (newDirection == 'E' || newDirection == 'W') ? 180 : 90; // New local variable inside method.
            // 3. Input degrees into a temporary variable and validate its range.
            while (true) {
                cout << "Enter degrees: ";
                cin >> newDegrees;
                if (newDegrees < 0 || newDegrees > maxDegrees) {
                    cerr << "Error: degrees must be between 0 and " << maxDegrees << " for direction " << newDirection << "." << endl;
                    continue;
                }
                break;
            }
            // 4. Input minutes into a temporary variable and validate its range.
            while (true) {
                cout << "Enter minutes: ";
                cin >> newMinutes;
                if (newMinutes < 0.0f || newMinutes >= 60.0f) {
                    cerr << "Error: minutes must be in the range [0, 60)." << endl;
                    continue;
                }
                // At the maximum degrees, minutes must be exactly zero.
                if (newDegrees == maxDegrees && newMinutes > 0.0f) { // Use '>' instead of '!=' to avoid float comparison issues.
                    cerr << "Error: at " << maxDegrees << " degrees, minutes must be 0 (no additional minutes are allowed)." << endl;
                    continue;
                }
                break;
            }
            // 5. All three values are valid; assign them to the fields.
            direction = newDirection;
            degrees = newDegrees;
            minutes = newMinutes;

        }

        // Constant method: prints coordinates in required format.
        void printCoords() const {
            // Use static constexpr: one copy for the whole program (created on first call).
            static constexpr const char* DEGREE_SIGN = "\xC2\xB0"; // UTF-8 encoding of U+00B0 (degree sign) instead of CP1251-specific (Windows-1251) '\xF8'.
            // The degree sign in UTF-8 is a two-byte sequence (0xC2 0xB0), so it cannot fit into a single char.
            // A string literal and a const char* pointer are used instead: the pointer addresses the two bytes,
            // and output stream reads them as one character.
            static constexpr char MINUTES_SIGN = '\'';
            cout << degrees << DEGREE_SIGN << minutes << MINUTES_SIGN << ' ' << direction << endl;
        }
    };

    int main() {
        Angle coordinate1('E', 179, 59.9f);
        coordinate1.setCoords();
        coordinate1.printCoords();
        return 0;
    }

// TODO:
// 1) exit() in a constructor is bad practice (no stack unwinding, destructors are skipped). Rewrite without exit(), e.g. using exceptions.