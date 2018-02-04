// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int cnt = 0;
void bubbleSort(int arr[], int be, int en) {
    cnt++;
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

int myPartition(int arr[], int be, int en) {
    int pivot = arr[en];
    int cur = be;
    int noToBeSwapped = be; // its an index
    while (cur < en) {
        if (arr[cur] < pivot) {
            swap(arr[noToBeSwapped], arr[cur]);
            ++cur;
            ++noToBeSwapped;
        } else {
            ++cur;
        }
    }
    swap(arr[noToBeSwapped], arr[en]);
    return noToBeSwapped;
}

void quickSort(int arr[], int be, int en) {
    if (be > en) {
        return;     // emptiness
    }

    int idx = myPartition(arr, be, en);
    quickSort(arr, be, idx - 1);
    quickSort(arr, idx + 1, en);
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

void copyArr(int x[], int arr[], int be, int en) {
    while (be <= en) {
        x[be] = arr[be];
        ++be;
    }
}

int mergeInvCnt(int arr[], int be, int en, int mid) {
    int x[100];
    int y[100];
    copyArr(x, arr, be, mid);
    copyArr(y, arr, mid + 1, en);

    int i = be;
    int j = mid + 1;
    int k = be;
    int ans = 0;
    while (i <= mid && j <= en) {
        if (x[i] <= y[j]) {
            arr[k] = x[i];
            ++k;
            ++i;
        } else {
            ans += (mid - i) + 1;
            arr[k] = y[j];
            ++j;
            ++k;
        }
    }

    while (i <= mid) {
        arr[k] = x[i];
        ++i;
        ++k;
    }

    while (j <= en) {
        arr[k++] = y[j++];      // ignore
    }
    return ans;
}

int inversionCount(int arr[], int be, int en) {
    if (be >= en) {
        return 0;
    }

    int mid = (be + en) / 2;
    int lt = inversionCount(arr, be, mid);
    int rt = inversionCount(arr, mid + 1, en);
    int ans = mergeInvCnt(arr, be, en, mid);
    return lt + ans + rt;
}


int main() {
    int arr[100];
    int n;
    cin >> n;
    inputArr(arr, n);

    bubbleSort(arr, 0, n - 1);
    cout << cnt;

    // cout << isSorted(arr, 0, n - 1);

    // cout << sumArr(arr, 0, n - 1);

    // printNum(n);

    // int x; cin >> x;
    // int ans = binarySearch(arr, 0, n - 1, x);
    // cout << ans;

    // towerOfHanoi(n, 'A', 'B', 'C');

    // int idx =  myPartition(arr, 0, n - 1);
    // cout << "Partiton at idx " << idx << endl;
    // outputArr(arr, n);

    // quickSort(arr, 0, n - 1);
    // outputArr(arr, n);

//     int ans = inversionCount(arr, 0, n - 1);
//     cout << ans << endl;
//     outputArr(arr, n);

}