// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int largestInArr(int arr[], int n) {
    const int inf = 1e8;    // 10^8 -> double to int; implicit
    int ans = -inf;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > ans) {
            ans = arr[i];
        }
    }

    return ans;

}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void outputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for (int cur = 0; cur < n; ++cur) {
        int rem = n - cur - 1;  // dil ka dard
        for (int i = 0; i < rem; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int largestPos(int arr[], int be, int en){
    // returns the index of the largest element
    int pos = be;
    while(be <= en){
        if (arr[be] > arr[pos]){
            pos = be;
        }
        ++be;
    }
    return pos;
}

void selectionSort(int arr[], int n){

    for(int en = n - 1; en >= 0; --en){
        int pos = largestPos(arr, 0, en);
        swap(arr[pos], arr[en]);
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; ++i){
        int j = i - 1;
        int cur = arr[i];

        while( j >= 0 && arr[j] > cur){
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = cur;
    }
}

int pos(int arr[], int n, int x){
    for(int i = 0; i < n; ++i){
        if (arr[i] == x) return i;
    }
}

int binarySearch(int arr[], int n, int x){
    int be = 0;
    int en = n -1;
    while(be <= en){
        int mid = (be + en) / 2;
        if (arr[mid] == x){
            return mid;
        }
        else if (x < arr[mid]){
            // search in the left
            en = mid - 1;
        }
        else {
            be = mid + 1;
        }
    }
    return -1;
}

void printSumToX(int arr[], int n, int x){
    for(int i = 0; i < n; ++i){
        int num1 = arr[i];
        int posOfNum2 = binarySearch(arr + i + 1, n - i - 1, x - arr[i]);
        if (posOfNum2 != -1){
            cout << num1 << " " << arr[posOfNum2 + i + 1] << endl;
        }
    }
}


void printSumToX(int arr[], int be, int en, int x){
    while(be < en){
        int sum = arr[be] + arr[en];
        if (sum == x){
            cout << arr[be] << " " << arr[en] << endl;
            ++be;
            --en;
        }
        else if (sum > x){
            --en;
        }
        else {
            ++be;
        }
    }
}


int main() {
    int arr[100] = {};  // initialisation --> 0
    // int arr[100];    // declaration --> garbage
    int n;
    cin >> n;

    // int ans = largestInArr(arr, n);
    // cout << ans << endl;

    // inputArr(arr, n);
    // // bubbleSort(arr, n);
    // // selectionSort(arr, n);
    // insertionSort(arr, n);
    // outputArr(arr, n);

    // inputArr(arr, n);
    // int elementToSearch; cin >> elementToSearch;
    // int ans = binarySearch(arr, n, elementToSearch);
    // cout << ans;

    inputArr(arr, n);
    int x; cin >> x;
    printSumToX(arr, 0, n-1, x);

}