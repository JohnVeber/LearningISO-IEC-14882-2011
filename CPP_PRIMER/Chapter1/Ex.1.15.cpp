#include <iostream>
// 1. An example of syntax error:
// int main(({
    // int sum = 0;
    // for (int val = 50; val <= 100; ++val){
        // sum += val;
    // }
    // std::cout << "Sum of 50 to 100 included is: " << sum << std::endl;
    // return 0;
// }

// 2. An example of type mismatch error:
// int main(){
//     int sum = 0;
//     for (int val = 50; val <= "I'm a bug"; ++val){
//         sum += val;
//     }
//     std::cout << "Sum of 50 to 100 included is: " << sum << std::endl;
//     return 0;
// }

// 3. An example of variable announcement error:
// int main(){
//     int sum = 0;
//     for (int val = 50; val <= 100; ++val){
//         sum1 += val;
//     }
//     std::cout << "Sum of 50 to 100 included is: " << sum << std::endl;
//     return 0;
// }
