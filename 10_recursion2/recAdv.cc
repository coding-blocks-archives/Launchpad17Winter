// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

void charOnButton(char digit, char code[]){
    char keyComb[][5] = {
        "0", 
        "#?*", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    strcpy(code, keyComb[digit - '0']);
}


void printCodes(char numCode[]){

}

int main(){
    char numCode[100];
    cin >> numCode;

    printCodes(numCode);   
}