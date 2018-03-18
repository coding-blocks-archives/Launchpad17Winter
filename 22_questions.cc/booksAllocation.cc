#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
const int D = 100;
void inputVec(vi&v)     {for (auto&i : v)cin >> i;}
void printVec(vi&v)     {for (auto&i : v)cout << i << " "; cout << endl;}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         { return 2 * i;}
int right(int i)        { return 2 * i + 1; }
int mid(int a, int b)   { return (a + b) / 2;}
/********************************/

bool allocateBooks(vi& books, int numStudents, int maxPagesForAllocation){

}


int minPages(vi& v, int numStudents){
    int sum = accumulate(v.begin(), v.end(), 0); // sum of all pages

    int be = 0;
    int end = sum;
    int ans = sum;

    while(be <= end){
        int guess = (be + end) / 2;
        bool success = allocateBooks(v, numStudents, guess);
        if (success){
            ans = guess;
            end = guess - 1;
        }
        else{
            be = guess + 1;
        }
    }
    return ans;
}


int main() {
    int n,s;
    cin >> n >> s;
    vi v(n);
    inputVec(v);

    int ans = minPages(v,s);
    cout << ans;
}