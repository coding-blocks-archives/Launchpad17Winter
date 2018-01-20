// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cctype>
#include <climits>
#include <cstring>
using namespace std;

int length(char str[]) {    //O(N)
    int i = 0;
    while (str[i] != '\0') ++i;
    return i;
}

bool isPalindrome(char str[]) { // O(N)
    int len = length(str);
    int en  = len - 1;
    int be = 0;

    while (be < en) {
        if (str[be] != str[en]) return false;
        ++be;
        --en;
    }
    return true;
}

void strReverse(char str[]) {   // O(N)
    int en = length(str) - 1;
    int be = 0;
    while (be < en) {
        swap(str[be], str[en]);
        ++be;
        --en;
    }
}

void strRotate(char str[]) {    // O(N)
    int en = length(str) - 1;
    char c = str[0];
    int be = 0;

    while (be < en) {
        str[be] = str[be + 1];
        ++be;
    }
    str[en] = c;
}

void strRotatek(char str[], int k) { // O(KN)
    for (int i = 0; i < k; ++i) {
        strRotate(str);
    }
}

void strRotatek_2(char str[], int k) {
    int len = length(str);
    k = k % len;

    char tmp[100];

    for (int i = 0; i < k; ++i) tmp[i] = str[i];

    for (int i = k; i < len; ++i) {
        str[i - k] = str[i];
    }

    // copy the tmp-->str
    for (int i = 0; i < k; ++i) {
        str[len - k + i] = tmp[i];
    }
}

void strcompress(char str[]) {
    int len = length(str);
    int cur = 0;
    int setPos = 0;
    while(cur < len){
        int cnt = 1;
        ++cur;
        while(cur < len && str[cur - 1] == str[cur]) {
            ++cnt;
            ++cur;
        }

        if (cnt > 1){
            char cntEqu = '0' + cnt;
            str[++setPos] = cntEqu;
        }
        str[++setPos] = str[cur];
    }
}

int strToInt(char str[]){
    // ignore spaces
    int cur = 0;
    int len = strlen(str);

    while(cur < len && str[cur] == ' ') ++cur;

    //either string is exhausted or first lettter is not zero
    if (isdigit(str[cur]) == false && str[cur] != '-') return 0;

    int ans = 0;
    bool isNeg = (str[cur] == '-');
    if (isNeg) ++cur;
    
    while(cur < len && isdigit(str[cur])){
        ans *= 10;
        ans += str[cur] - '0';
        ++cur;
    }

    if (isNeg) return -ans;
    return ans;
}


int main() {
    char str[20];
    // cin >> str;
    // cout << str;

    // int len = length(str);
    // cout << len << endl;

    // bool ans = isPalindrome(str);
    // cout << boolalpha << ans;           // sticky

    // strReverse(s);
    // cout << str;

    // strRotate(str);
    // cout << str;

    // int k; cin >> k;
    // strRotatek_2(str, k);
    // cout << str;

    // strcompress(str);
    // cout << str;

    // cin.getline(str, 20);
    // cout << "X" << str << "X" << endl;
    // int ans = strToInt(str);
    // cout << ans;

    // int ans = 2e9 + 2e9;
    // int ans = INT_MAX +1; 
    // cout << ans;

}