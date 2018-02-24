// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void specialPush(deque<int>& q, vector<int>& v, int i){
    // weaker element cannot withstand me
    while(q.empty() == false && q.back() < v[i]){
        q.pop_back();
    }
    q.push_back(i);
}


vector<int> windowMax(vector<int>& v, int w){
    deque<int> q;
    vector<int> ans;

    // create a window
    for(int i = 0; i < w - 1; ++i){
        specialPush(q, v, i);
    }

    int start = 0;
    int endWindow = w - 1;
    while(endWindow < v.size()){
        specialPush(q, v, endWindow);
        ans.push_back(v[q.front()]);
        ++start;
        ++endWindow;
        if (q.front() < start) q.pop_front();
    }
    return ans;
}

int main(){
    int w;
    cin >> w;

    vector<int> v;
    while(true){
        int x; cin >> x;
        if (x == -1) break;
        v.push_back(x);
    }   

    vector<int> ans = windowMax(v, w);
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
}