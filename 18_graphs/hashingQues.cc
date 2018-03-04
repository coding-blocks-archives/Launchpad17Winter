// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void printVec(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
}



vector<int> removeDuplicates(vector<int> v) {
    map<int, bool> m;
    // set<Node*>
    // map<Node*, bool>
    vector<int> ans;

    for (int x : v) {
        // if x is present in the map, avoid it, duplicate
        // if (m["ishaan"] == false)
        if (m.find(x) == m.end()) {
            ans.push_back(x);
            m[x] = true;
        }
    }
    return ans;
}


// heapsort
int parent(int i) { return (i - 1) / 2;}
int left(int i)   { return (2 * i + 1);}
int right(int i)  { return (2 * i + 2);}

void heapify(vector<int>& v, int i, const int endIndex){
    int pos = i;
    if (left(i) <= endIndex && v[left(i)] > v[i]){
        pos = left(i);
    }

    if (right(i) <= endIndex && v[right(i)] > v[pos]){
        pos = right(i);
    }

    if (pos != i){
        swap(v[pos], v[i]);
        heapify(v, pos, endIndex);
    }
}

void heapsort(vector<int>& v){
    // (NlogN) O(1) space
    int endIndex = v.size() - 1;

    for(int i = parent(endIndex); i >= 0; --i){
        heapify(v, i, endIndex);
    }

    for(int i = endIndex; i > 0; --i){
        swap(v[i], v[0]);
        heapify(v, 0, i - 1);
    }
}

int main() {
    vector<int> v;
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }

    // vector<int> ans = removeDuplicates(v);
    // printVec(ans);

    heapsort(v);
    printVec(v);



}