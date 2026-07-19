#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    const float OFFSET = 32.0f;
    const float CONVERSION_FACTOR = 9.0f / 5.0f;
    float celsius = 0.0f;
    float result = 0.0f;
    cout << "Enter amount in Celsius degrees :" << endl;
    cin >> celsius;
    // Format currency output to 5 decimal places for better readability:
    result = celsius*CONVERSION_FACTOR + OFFSET;
    cout << fixed << setprecision(2);
    cout << "The equivalent amount in Fahrenheit degrees is: " << result << endl;
    return 0;
}