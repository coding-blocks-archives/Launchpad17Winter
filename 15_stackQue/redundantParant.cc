// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int cntRedundantParant(string& exp){
    int cnt = 0; 
    stack<char> stk;

    for(int i = 0; i < exp.size(); ++i){
        // if opening bracket or operator do this...
        if (exp[i] == '(' || isOperator(exp[i])){
            stk.push(exp[i]);
        }
        // else if a closing bracket is found
        else if (exp[i] == ')'){
            bool opFound = false;
            // pop until the opening bracket is found
            while(stk.top() != '('){
                if (stk.top() != '(') opFound = true;
                stk.pop();
            }
            stk.pop();
            if (opFound == false) ++cnt;
        }
    }
    return cnt;
}

int main(){
    string exp;
    cin >> exp;
    int ans = cntRedundantParant(exp);
    cout << ans;   
}