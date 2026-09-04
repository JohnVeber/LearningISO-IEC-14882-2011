// Modified version of factor.cpp
#include <iostream>
using namespace std;
int main(){
    unsigned int numb;
    do{
        unsigned long fact = 1;
        cout << "Enter an integer number: ";
        cin >> numb;

        if(numb != 0){
            for(int j=numb; j>0; j--)
            fact *= j;
            cout << "The factor of the entered number is " << fact << endl;
            fact = 1;
        }
    }
    while(numb != 0);
    cout << "Entered 0. Program finished." << endl;
    return 0;
}

// TODO:
// 1) Handling of input data.