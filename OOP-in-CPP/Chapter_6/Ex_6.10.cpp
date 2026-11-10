#include <iostream>
using namespace std;

class Angle {
private:
    char direction;
    int degrees;
    float minutes;
    static constexpr const char* DEGREE_SIGN = "\xC2\xB0"; // UTF-8 degree sign.
    static constexpr char MINUTES_SIGN = '\'';

public:
    Angle() : direction('N'), degrees(0), minutes(0.0f) { } // Default constructor added: initializes to 0°0' N.

    Angle(char dr, int dg, float m) : direction(dr), degrees(dg), minutes(m) { // Parameterized constructor with validation (as before).
        // 1. Validate direction.
        if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W') {
            cerr << "Error: direction must be one of 'N', 'S', 'E', 'W'." << endl;
            exit(1); // TODO: exit() in a constructor is bad practice. Rewrite without exit(), e.g. using exceptions.
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

    void setCoords() { // Input and validate coordinates from the user.
        // Some temporary variables to avoid inconsistent state between step 1 and 2.
        char newDirection;
        int newDegrees;
        float newMinutes;

        // 1. Input and validate direction into a temporary variable.
        while (true) {
            cout << "Enter direction: ";
            cin >> newDirection;
            if (!cin || (newDirection != 'N' && newDirection != 'S' &&
                         newDirection != 'E' && newDirection != 'W')) {
                cin.clear();             // Reset the error flag on cin.
                cin.ignore(10000, '\n'); // Discard the invalid input.
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
            if (!cin || newDegrees < 0 || newDegrees > maxDegrees) {
                cin.clear();             // Reset the error flag on cin.
                cin.ignore(10000, '\n'); // Discard the invalid input.
                cerr << "Error: degrees must be between 0 and " << maxDegrees
                     << " for direction " << newDirection << "." << endl;
                continue;
            }
            break;
        }

        // 4. Input minutes into a temporary variable and validate its range.
        while (true) {
            cout << "Enter minutes: ";
            cin >> newMinutes;
            if (!cin || newMinutes < 0.0f || newMinutes >= 60.0f) {
                cin.clear();             // Reset the error flag on cin.
                cin.ignore(10000, '\n'); // Discard the invalid input.
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

    void printCoords() const { // Print coordinates in the appropriate format.
        cout << degrees << DEGREE_SIGN << minutes << MINUTES_SIGN << ' ' << direction << endl;
    }
};

class Ship {
private:
    static int shipCounter; // Counter shared by all objects.
    int shipNumber;
    Angle shipLatitude;
    Angle shipLongitude;

public:
    Ship() : shipNumber(++shipCounter) {} // Default constructor: assigns the next ship number; coordinates default to 0°0' N.

    void setShipData() { // Input ship data (number is auto-assigned; coordinates are entered by the user).
        cout << "Enter latitude:" << endl;
        shipLatitude.setCoords();
        cout << "Enter longitude:" << endl;
        shipLongitude.setCoords();
    }

    void printShipData() const { // Print ship data (number and both coordinates).
        cout << "Ship number: " << shipNumber << endl;
        cout << "Latitude: ";
        shipLatitude.printCoords();
        cout << "Longitude: ";
        shipLongitude.printCoords();
    }
};

int Ship::shipCounter = 0; // Definition of the static counter outside the class.

int main() {
    Ship s1, s2, s3;

    // Input data for each ship.
    cout << "\nShip 1 data:" << endl;
    s1.setShipData();

    cout << "\nShip 2 data:" << endl;
    s2.setShipData();

    cout << "\nShip 3 data:" << endl;
    s3.setShipData();

    // Print data for each ship.
    cout << "\n--- Ship information ---" << endl;

    cout << "\nShip 1:" << endl;
    s1.printShipData();

    cout << "\nShip 2:" << endl;
    s2.printShipData();

    cout << "\nShip 3:" << endl;
    s3.printShipData();

    return 0;
}
