// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class Heap{
private:
    vector<int> v;
    int nelements;

    int parent(int i) { return i >> 1; }
    int right(int i)  { return (i << 1) + 1; /* 2i + 1 */}
    int left(int i)   { return (i << 1); }

    void heapify(int i){
        int pos = i;
        if (left(i) <= nelements && v[left(i)] > v[i]){
            pos = left(i);
        }

        if (right(i) <= nelements && v[right(i)] > v[pos]){
            pos = right(i);
        }
        if (i != pos){
            swap(v[i], v[pos]);
            heapify(pos);
        }
    }

public:
    Heap(){
        v.push_back(-1);
        nelements = 0;
    }

    void push(int x){
        v.push_back(x);
        ++nelements;

        int idx = nelements;
        while(parent(idx) >= 1 && v[idx] > v[parent(idx)]){
            swap(v[parent(idx)], v[idx]);
            idx = parent(idx);
        }
    }

    void pop(){
        if (empty()) return;

        swap(v[1], v[nelements]);
        v.pop_back();
        --nelements;
        heapify(1);
    }

    int top(){
        if (empty()) return -1;
        return v[1];
    }   

    int empty(){
        return nelements == 0;
    }
};

int main(){
  Heap h; 
  h.push(1);
  h.push(2);
  cout << h.top();     
}