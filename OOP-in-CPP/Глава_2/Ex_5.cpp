#include <iostream>
#include <cctype>
using namespace std;
int main(){
    char symbol;
    int result;
    cout << "Enter any ASCII letter please:" << endl;
    cin >> symbol;
    // This explicit cast is required to prevent UB:
    result = islower(static_cast<unsigned char>(symbol));
    cout << result << endl;
    return 0;
}
// NOTE about islower() function:
// It returns a non-zero value (implementation-defined, e.g., 512) only for lower-case ASCII letters, 0 otherwise;
// Cyrillic and other non-ASCII characters are NOT recognized.
