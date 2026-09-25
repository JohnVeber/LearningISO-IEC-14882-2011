// Program use a function which counts its own calls using a static local variable.
#include <iostream>
using namespace std;

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
// Uses a static local counter: it is initialized once, keeps its value between calls, and is visible only here.
void showCallCount() {
    static int callCount = 0;   // Initialized only on the first call.
    ++callCount;
    cout << "Function called " << callCount << " time(s)." << endl;
}