// Program use a function which counts its own calls using a global variable.
#include <iostream>
using namespace std;

// Global variable: lives for the whole program, visible to every function.
int callCount = 0;

// Prototype
void showCallCount();

//--------------------------------------------------------
int main() {
    // Call the function at least 10 times.
    for (int i = 0; i < 10; ++i) {
        showCallCount();
    }

    return 0;
}

//--------------------------------------------------------
// Increments the global counter and prints how many times the function has been called so far.
void showCallCount() {
    ++callCount; // increment the counter
    cout << "Function called " << callCount << " time(s)." << endl;
}