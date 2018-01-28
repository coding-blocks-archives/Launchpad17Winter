// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int be, int en) {
    if (be >= en) {
        return; // empty array
    }

    bubbleSort(arr, be + 1, en);
    if (arr[be] > arr[be + 1]) { // atleast 2 elements
        swap(arr[be], arr[be + 1]);
        bubbleSort(arr, be + 1, en);
    }
}

bool isSorted(int arr[], int be, int en) {
    if (be >= en) {
        return true;
    }

    if (arr[be] > arr[be + 1]) {
        return false;
    }

    return isSorted(arr, be + 1, en);
}

int sumArr(int arr[], int be, int en) {
    if (be > en) {
        return 0;
    }
    int smallAns = sumArr(arr, be + 1, en);
    return smallAns + arr[be];
}


void printDig(int dig) {
    switch (dig) {
    case 0 :
        cout << "zero";
        break;
    case 1 :
        cout << "one";
        break;
    case 2 :
        cout << "two";
        break;
    default :
        cout << "default";
        break;
    }
    cout << " ";
}

void printNum(int n) {
    if (n == 0) {
        return ;
    }

    printNum(n / 10);
    printDig(n % 10);
}

int binarySearch(int arr[], int be, int en, int x) {
    if (be > en) {
        return -1;
    }

    int mid = (be + en) / 2;
    if (arr[mid] == x) {
        return mid;
    }

    if (arr[mid] > x) {
        return binarySearch(arr, be, mid - 1, x);
    }

    int ans =  binarySearch(arr, mid + 1, en, x);
    return ans;
}

void towerOfHanoi(int n, char src, char dest, char helper) {
    if (n == 0) {
        return;
    }

    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Disc " << n << " : " << src << "-->" << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}

void outputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[100];
    int n;
    cin >> n;
    // inputArr(arr, n);

    // bubbleSort(arr, 0, n - 1);

    // cout << isSorted(arr, 0, n - 1);

    // cout << sumArr(arr, 0, n - 1);

    // printNum(n);

    // int x; cin >> x;
    // int ans = binarySearch(arr, 0, n - 1, x);
    // cout << ans;

    towerOfHanoi(n, 'A', 'B', 'C');

    // outputArr(arr, n);

}