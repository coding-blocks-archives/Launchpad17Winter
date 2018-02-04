// Deepak Aggarwal, deepak@codingblocks.com
// https://github.com/aggarwaldeepak/
#include <iostream>
using namespace std;

void printCodes(char str[], int be, char ans[], int i)
{
    if (str[be] == '\0'){
        ans[i] = '\0';
        cout << ans;
        cout << endl;
        return;
    }

    char curDig = str[be];
    int num = curDig - '0'; // '1'-'0'
    char curChar = 'a' + num - 1;
    ans[i] = curChar;
    printCodes(str, be + 1, ans, i + 1);

    if (str[be + 1] == '\0') return;    // no more chars to process

    num = num * 10; // 1-->10
    char nextDig = str[be + 1];
    int nextNum = nextDig - '0';
    num += nextNum; // 10 + 2 --> 12
    if (num <= 26){
        ans[i] = 'a' + num - 1;
        printCodes(str, be + 2, ans, i + 1);    
    }    
}

int main()
{
    char str[100] = "";
    char ans[100] = "";
    cin >> str;
    printCodes(str, 0, ans, 0);

    return 0;
}