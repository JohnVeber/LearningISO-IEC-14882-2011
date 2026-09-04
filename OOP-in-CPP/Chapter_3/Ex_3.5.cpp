#include <iostream>
using namespace std;
int main(){
    const char LETTER = 'X';
    const int lines = 20;
    const int total_width = 2 * lines;

    for(int i=1;i<=lines;i++){
        for(int j=1;j<=total_width;j++){
            if(j<=(total_width-(2*i-1)))
                cout << ' ';
            else
                cout << LETTER;
        }
        cout << endl;
    }
    return 0;
}