// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool isAlpha(char c){
    // if ((c >= 'A' && c <= 'Z') or (c >= 'a' && c <= 'z')){
    //     return true;
    // }

    // return false;

    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isDigit(char c){
    return c >= '0' && c <= '9';
}

bool isWhitespace(char c){
    return c == ' ' || c == '\n' || c == '\t';
}

bool isSpace(char c){
    return c == ' ';
}

void printCnt(){
    int digit   = 0;
    int letters = 0;
    int spaces  = 0;
    int words   = 0;
    int others   = 0;
    int whitespaces = 0;
    int alphabets   = 0;

    char c;
    bool insideWord = false;

    while(true){
        c = cin.get();
        if (c == '$') break;

        ++letters;

        if (isDigit(c)){
            insideWord = true;
            ++digit;
        } else if (isAlpha(c)){
            insideWord = true;
            ++alphabets;
        } else if (isWhitespace(c)){
            ++whitespaces;
            if (insideWord == true){
                ++words;
                insideWord = false;
            }

            if (isSpace(c)) ++spaces;
        } else {
            insideWord = true;
            ++others;
        }
    }

    cout << "letters    :" << letters << endl;
    cout << "digit      :" << digit << endl;
    cout << "spaces     :" << spaces << endl;
    cout << "others     :" << others << endl;
    cout << "words      :" << words << endl;
    cout << "alphabets    :" << alphabets << endl;
    cout << "whitespaces  :" << whitespaces << endl;
}

int main(){
    printCnt();   
}