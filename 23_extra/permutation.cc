// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

void printPerm(string s, int be){
    // prints permuation in lexicographical order of a SORTED string
    if (be == s.size()){
        cout << s << endl;
        return;
    }

    for(int i = be; i < s.size(); ++i){
        swap(s[i], s[be]);       // abcd-->bacd-->cabd-->dabc
        printPerm(s, be + 1);   // earlier I mistakenly wrote i + 1
    }
}


int main(){
    string s = "abcd";
    sort(s.begin(), s.end());
    printPerm(s, 0);
}