// Deepak Aggarwal, deepak@codingblocks.com
// https://github.com/aggarwaldeepak/
#include <iostream>
using namespace std;

void x[] = "abc";

void printPermutations(char str[], int be, char ans[], int i){
    if (str[be] == '\0'){
        cout << ans;
        cout << endl;
        return;
    }

    for(int j = be; str[j] != '\0'; ++j){
        swap(str[be], str[j]);
        ans[i] = str[be];
        printPermutations(str, be + 1, ans, i + 1);
        swap(str[be], str[j]);
    }
}


int main(){
   char str[100] = "";
   char ans[100] = "";
   cin >> str;
   printPermutations(str, 0, ans, 0);
}