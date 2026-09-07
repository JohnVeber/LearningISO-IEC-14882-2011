#include <iostream>
using namespace std;

// Structure from englstrc.cpp
struct Distance {
    int feet;
    float inches;
};

struct Volume {
    Distance length;
    Distance width;
    Distance height;
};

int main() {
    Volume room = {
        {15, 6.5},   // length: 15 feet 6.5 inches
        {12, 3.25},  // width:  12 feet 3.25 inches
        {10, 0.0}    // height: 10 feet 0.0 inches
    };

    // Conversion into feet (1 feet is 12 inches)
    float length_ft = room.length.feet + room.length.inches / 12.0;
    float width_ft  = room.width.feet  + room.width.inches  / 12.0;
    float height_ft = room.height.feet + room.height.inches / 12.0;

    float room_volume = length_ft * width_ft * height_ft;

    cout << "Room dimensions:" << endl;
    cout << "Length: " << room.length.feet << "'-" << room.length.inches << "\"" << endl;
    cout << "Width:  " << room.width.feet  << "'-" << room.width.inches  << "\"" << endl;
    cout << "Height: " << room.height.feet << "'-" << room.height.inches << "\"" << endl;
    cout << "Volume of this room is: " << room_volume << " cubic feet." << endl;

    return 0;
}