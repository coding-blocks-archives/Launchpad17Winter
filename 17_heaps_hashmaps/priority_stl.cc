// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

class comparator{
public:
    bool operator()(int a, int b){
        // shall a come before b
        return a > b;
    }
};


int main(){
    priority_queue<int, vector<int>, comparator> q;
    q.push(3);
    q.push(4);
    cout<< q.top();    
}