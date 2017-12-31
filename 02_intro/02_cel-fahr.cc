// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int initial, final, step;

    cin >> initial >> final >> step;

    while(initial <= final){
        // conversion
        double cel = 5.0 / 9.0 * (initial - 32);
        cout << initial << "F = " << cel << "C \n"; 
        initial = initial + step;
    }   
}