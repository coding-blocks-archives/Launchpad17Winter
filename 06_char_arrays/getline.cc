// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    char s1[100], s2[100];
    int x; cin >> x;
    cin.ignore();   // to consume the enter
    cin.getline(s1, 10);
    cin.getline(s2, 100); 

    cout << "X" << s1 << "X";
    cout << "X" << s2 << "X";
}