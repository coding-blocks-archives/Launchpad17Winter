// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class comparator{
public:
    bool operator()(int a, int b){
        // shall a appear before b
        return a > b;
    }
};


int main(){
    vector<int> v;
    v.push_back(4);    
    v.push_back(3);    
    v.push_back(2);    
    v.push_back(1);   
    // comparator c;
    // sort(v.begin(), v.end(), c);
    sort(v.begin(), v.end(), comparator());
    cout << v[0] << " ";
    cout << v[1] << " ";
    cout << v[2] << " ";

}