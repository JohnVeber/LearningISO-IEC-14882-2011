#include <iostream>
using namespace std;


class Selfcounter {
    private:
        static int counter; // Counter shared by all objects.
        int mynumber;
    public:
        Selfcounter() : mynumber(++counter) {} // Increment the counter on object creation and use it to initialize this object's number.

        void printNumber() const {
            cout << "My sequence number is: " << mynumber << endl;
        }

};

int Selfcounter::counter = 0; // Definition of the static counter outside the class.

int main(){
    Selfcounter c1, c2, c3;

    c1.printNumber();
    c2.printNumber();
    c3.printNumber();
    return 0;
}

// TODO:
// 1) Add parameterized constructor.