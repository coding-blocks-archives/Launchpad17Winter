// Deepak Aggarwal, deepak@codingblocks.com
// https://github.com/aggarwaldeepak/
#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int topIdx;
public:
    Stack(){
        arr = new int[100];
        topIdx = 0;
    }

    ~Stack(){
        delete [] arr;
    }

    int top(){
        if (empty()) return -1;
        return arr[topIdx - 1];

    }
    void push(int x){
        if (topIdx == 100) return;
        arr[topIdx] = x;
        topIdx++;
    }
    void pop(){
        if (empty()) return;
        topIdx--;
    }
    bool empty(){
        return topIdx == 0;
    }
};


int main(){
    Stack s;
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    
    return 0;
}