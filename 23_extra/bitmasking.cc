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

int countSet(int x){
    int cnt = 0;

    while(x != 0){
        if ((x & 1) == 1){
            ++cnt;
        }
        x = x >> 1;
    }
    return cnt;
}

int findUniq(vi& v){
    int xorAns = 0;
    for(int i = 0; i < v.size(); ++i){
        xorAns = xorAns ^ v[i];
    }
    return xorAns;
}

void print2Uniq(vi& v){
    int xorAns = accumulate(v.begin(), v.end(), 0, 
        [](int a, int b){       // bool opeartor()(int a, int b){}...lamba methods
            return a^b;
        });

    int setAxor = 0;
    int setAno = xorAns & (-xorAns);
    for(int x : v){
        if (setAno & x){
            setAxor ^= x;
        }
    }
    int no1 = setAxor ^ xorAns;
    int no2 = no1 ^ xorAns;
    cout << no1 << " " << no2 << endl;
}

void setArr(vi& cnt, int x){
    for(int i = 0; i < 32; ++i){
        int check = 1 << i;
        if (check & x){
            cnt[i]++;
        } 
    }
}

int numFromArr(vi& arr){
    int num = 0;
    for(int i = 0; i < 32; ++i){
        num += arr[i] * (1 << i);
    }
    return num;
}

int thriceUnique(vi& v){
    vi bits(32, 0);
    for(int x: v){
        setArr(bits, x);
    }

    for (int i = 0; i < 32; ++i)
    {
        bits[i] = bits[i] % 3;
    }

    return numFromArr(bits);
}

int main(){
    // int x;
    // cin >> x;

    // int cnt = countSet(x);
    // cout << cnt;   

    // int n;
    // cin >> n;
    // for(int i = 0; i < 4; ++i){
    //     bitset<2> b(n);
    //     cout << b << endl;
    //     n = n >> 1;
    // }

    /** find unique **/
    // int n; cin >>n;
    // vi v(n);
    // inputVec(v);
    // int uniq = findUniq(v);
    // cout << uniq;

    /** find 2 unique **/
    // int n; cin >>n;
    // vi v(n);
    // inputVec(v);
    // print2Uniq(v);

    /** thrice unique **/
    int n; cin >>n;
    vi v(n);
    inputVec(v);
    int uniq = thriceUnique(v);
    cout << uniq;

}