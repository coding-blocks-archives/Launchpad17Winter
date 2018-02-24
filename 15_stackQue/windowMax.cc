// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

vector<int> windowMax(vector<int>& v, int w){

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