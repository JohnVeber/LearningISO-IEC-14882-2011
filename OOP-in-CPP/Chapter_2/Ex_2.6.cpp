#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    const float USD_PER_GBP$ = 1.487f;
    const float USD_PER_CHF$ = 0.172f;
    const float USD_PER_DEM$ = 0.584f;
    const float USD_PER_JPY$ = 0.00955f;
    float dollars = 0.0f;
    float amount = 0.0f;
    cout << "Enter amount in US Dollars:" << endl;
    cin >> dollars;
    // Format currency output to 5 decimal places for better readability:
    cout << fixed << setprecision(5);
    amount = dollars / USD_PER_GBP$;
    cout << "The equivalent amount in Pound sterlings is: " << amount << endl;
    amount = dollars / USD_PER_CHF$;
    cout << "The equivalent amount in Francs is: " << amount << endl;
    amount = dollars / USD_PER_DEM$;
    cout << "The equivalent amount in Deutsche Marks is: " << amount << endl;
    amount = dollars / USD_PER_JPY$;
    cout << "The equivalent amount in Japanese Yen is: " << amount << endl;
    return 0;
}