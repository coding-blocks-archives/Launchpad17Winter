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


void printCodes(char numCode[], int be, char ans[], int i){
    if (numCode[be] == '\0'){
        ans[i] = '\0';
        cout << ans << endl;
        return;
    }

    char code[5] = "";
    charOnButton(numCode[be], code);

    for(int x = 0; code[x] != '\0'; ++x){
        ans[i] = code[x];
        printCodes(numCode, be + 1, ans, i + 1);
    }
}

void printSubset(char str[], int be, char ans[], int i){
    if (str[be] == '\0'){
        ans[i] = '\0';
        cout << ans << endl;
        return;
    }

    printSubset(str, be + 1, ans, i);       // left
    ans[i] = str[be];
    printSubset(str, be + 1, ans, i + 1);   // selected
}

void printArr(int arr[], int k){
    for (int i = 0; i < k; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printFixedSizeSet(int n, int start, int k, int idx, int arr[]){
    if (n < k){
        return; // such arrangement is not possible
    }

    if (idx == k){
        printArr(arr, k);
        return;
    }

    for(int i = 0; i < n - k + 1 && start <= n; ++i){
        arr[idx] = start;
        printFixedSizeSet(n, start + 1, k, idx + 1, arr);
        ++start;
    }

}

int main(){
    char numCode[100];
    char ans[100] = "";

    // cin >> numCode;

    // printCodes(numCode, 0, ans, 0);  

    // char str[100]; cin >> str;
    // printSubset(str, 0, ans, 0);

    int arr[100];
    int n, k; cin >> n >> k;
    printFixedSizeSet(n, 1, k, 0, arr);  
}