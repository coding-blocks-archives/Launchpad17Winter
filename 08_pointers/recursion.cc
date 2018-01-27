// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fact(int n){
    // function that gives factorial of n

    if (n <= 0){
        return 1;
    }

    int nMinus1 = fact(n - 1);
    int ans = n * nMinus1;
    return ans;
}

void printInc(int n){
    if (n <= 0){
        return;
    }

    printInc(n - 1);
    cout << " " << n;
}


void printDec(int n){
    if (n <= 0) return;

    cout << n << " ";
    printDec(n - 1);
}

int power(int x, int n){
    if (n <= 0){
        return 1;
    }

    int smallAns = power(x, n - 1);
    int ans = x * smallAns;
    return ans;
}

int fib(int n){
    if (n <= 0) return -1;
    if (n == 1) return 0;
    if (n == 2) return 1;

    int prevNo = fib(n - 1);
    int superPrevNo = fib(n - 2);
    int ans = prevNo + superPrevNo;
    return ans;
}


void displayArr(int arr[], int n){
    if (n <= 0){
        return;
    }

    displayArr(arr, n - 1);
    cout << arr[n - 1] << " ";
}

void displayArrRev(int arr[], int n){
    if (n == 0){
        return;        
    }

    cout << arr[n - 1] << " ";
    displayArrRev(arr, n - 1);
}

int maxEle(int arr[], int n){
    if (n == 0){
        int inf = 1e6;
        return -inf;
    }

    int smallAns = maxEle(arr, n - 1);
    return max(smallAns, arr[n - 1]);

}

int findIndex(int arr[], int n, int x){
    if (n == 0){
        return -1;
    }

    if (arr[n - 1] == x){
        return n - 1;
    }

    return findIndex(arr, n - 1, x);
}

int findIndexBeg(int arr[], int be, int en, int x){
    if (be > en){
        return -1;
    }

    if (arr[be] == x){
        return be;
    }
    return findIndexBeg(arr, be + 1, en, x);
}



int main(){
    int n;

    // cin >> n;
    // int ans = fact(n);
    // cout << ans << endl; 

    // cin >> n; 
    // printInc(n); 

    // cin >> n;
    // printDec(n);

    // int x;
    // cin >> x >> n;
    // int ans = power(x, n);
    // cout << ans;

    // cin >> n;
    // cout << fib(n);

    // int arr[] = {1, 2, 3};
    // displayArrRev(arr, 3);

    // int arr[] = {1, -3, 4, 3};
    // cout << maxEle(arr, 0);

    int arr[] = {1, 3, 4, 3};
    cout << findIndexBeg(arr, 0, 3, 3);
}