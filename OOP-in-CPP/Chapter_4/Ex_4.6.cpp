#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
    char first_letter;
    etype emp_type;

    cout << "Enter the first letter of the position" << endl;
    cout << "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> first_letter;

    // One switch for both mapping and output
    switch (first_letter) {
        case 'l':
            emp_type = laborer;
            cout << "Full position name: laborer" << endl;
            break;
        case 's':
            emp_type = secretary;
            cout << "Full position name: secretary" << endl;
            break;
        case 'm':
            emp_type = manager;
            cout << "Full position name: manager" << endl;
            break;
        case 'a':
            emp_type = accountant;
            cout << "Full position name: accountant" << endl;
            break;
        case 'e':
            emp_type = executive;
            cout << "Full position name: executive" << endl;
            break;
        case 'r':
            emp_type = researcher;
            cout << "Full position name: researcher" << endl;
            break;
        default:{
            cout << "Error: Invalid first letter." << endl;
            return 1;
        }
    }

    return 0;
}

// TODO:
// 1) Retry request in case of input errors.