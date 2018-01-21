// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printMat(int a[][10], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << a[r][c] <<  " ";
        }
        cout << endl;
    }
}

void printDiag(int mat[][10], int m, int n) {
    for (int i = 0; i < m && i < n; ++i) {
        cout << mat[i][i] << " ";
    }
}

void printSpiral(int mat[][10], int m, int n) {
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    int elementsPrintedSoFar = 0;
    int elementsToPrint = m * n;

    while (elementsPrintedSoFar < elementsToPrint) {
        // print the top row
        for (int c = left; c <= right; ++c) {
            cout << mat[top][c] << " ";
            ++elementsPrintedSoFar;
        }
        ++top;

        // print the right col
        for (int r = top; r <= bottom; ++r) {
            cout << mat[r][right] << " ";
            ++elementsPrintedSoFar;
        }
        --right;

        // print the bottom
        for (int c = right; top <= bottom && c >= left; --c) {
            cout << mat[bottom][c] << " ";
            ++elementsPrintedSoFar;
        }
        --bottom;

        // print the left
        for (int r = bottom; left <= right && r >= top; --r) {
            cout << mat[r][left] << " ";
            ++elementsPrintedSoFar;
        }
        ++left;
    }
}


void rotate90(int arr[][10], int m, int n) {
    int ans[10][10];
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            ans[m - c - 1][r] = arr[r][c];
        }
    }
    printMat(ans, m, n);
}

void sqWavePrint(int mat[][10], int m, int n) {
    for (int c = 0; c < n; ++c) {
        if (c % 2 == 0) {
            // top to bottom
            for (int r = 0; r < m; ++r) {
                cout << mat[r][c] << " ";
            }
        }
        else {
            for (int r = m  - 1; r >= 0; --r) {
                cout << mat[r][c] << " ";
            }
        }
    }
}



int main() {
    // int mat[10][10];
    // int n, m;
    // cin >> m >> n;

    // for (int r = 0; r < m; ++r) {
    //     for (int c = 0; c < n; ++c) {
    //         cin >> mat[r][c];
    //     }
    // }

    // printMat(mat, m, n);
    // printDiag(mat, m, n);
    // printSpiral(mat, m, n);
    // sqWavePrint(mat, m, n);
    // rotate90(mat, m, n);

}