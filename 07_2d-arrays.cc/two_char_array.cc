// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputArr(char mat[][100], int n) {
    for (int i = 0; i < n; ++i) {
        // cin >> mat[i];
        cin.getline(mat[i], 99);
        // mat[i] --> array
        // mat[i][j] --> char
    }
}

void outputArr(char mat[][100], int n) {
    for (int i = 0; i < n; ++i) {
        cout << mat[i] << endl;
    }
}

bool strcmp(char a[], char b[]) {
    // is a > b ??
    int i = 0;
    int j = 0;
    while (a[i] != '\0' && b[j] != '\0') {
        if (a[i] != b[j]) {
            break;
        }
        ++i;
        ++j;
    }
    return a[i] > b[j];
}

void swapStr(char a[], char b[]) {
    int i, j;
    i = 0;
    j = 0;

    while(a[i] != '\0' || b[j] != '\0'){
        swap(a[i], b[j]);
        ++i;
        ++j;
    }
}

void sortStrings(char mat[][100], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {

            if (strcmp(mat[j], mat[j + 1])) {
                swapStr(mat[j], mat[j + 1]);
            }
        }
    }
}



int main() {
    char mat[100][100];

    int nWords;
    cin >> nWords;
    cin.ignore();   // to ignore the enter or whatever

    inputArr(mat, nWords);
    sortStrings(mat, nWords);
    outputArr(mat, nWords);
}