// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void dnf(int a[], int n){
    int zeroEnd = 0;
    int twoStart = n - 1;

    int cur = 0;
    while(cur < twoStart){
        switch(a[cur]){
            case 0 : swap(a[cur], a[zeroEnd]); ++zeroEnd; ++cur;break;
            case 2 : swap(a[cur], a[twoStart]); ++cur;--twoStart; break;
            default: ++cur; 
        }
    }
}

int main(){
    int arr[10];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    dnf(arr, n);

    for(int i = 0; i < n; ++i) cout << arr[i];

}