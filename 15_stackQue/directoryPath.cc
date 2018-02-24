// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string simplifyPath2(string path){
    stringstream pathStream(path);
    stack<string> stk;
    string curFolder;
    while(getline(pathStream, curFolder, '/')){
       
        if (curFolder == ".") continue;
        if (curFolder == ".."){
            stk.pop();
        }
        else if (curFolder.size() > 0){
            stk.push(curFolder);
        }
    }

    stack<string> revPath;
    while (stk.empty() == false) {
        revPath.push(stk.top());
        stk.pop();
    }

    string ans;
    while (revPath.empty() == false) {
        ans += "/" + revPath.top();
        revPath.pop();
    }
    if (ans == "") ans += "/";
    return ans;
}


string simplifyPath(string path) {
    stack<string> stk;

    int i = 0;
    while (i < path.size()) {
        // if . or / move ahead
        if (path[i] == '/') {
            ++i;
            continue;   // delimiter
        }

        // get the current folder
        string curFolder = "";
        int j = i;
        while (j < path.size() && path[j] != '/') {
            curFolder += path[j];
            ++j;
        }
        i = j + 1;

        // if .. pop
        if (curFolder == ".") continue;
        if (curFolder == "..") {
            stk.pop();
        }
        else {
            // push the folder into the stack
            stk.push(curFolder);
        }
    }

    stack<string> revPath;
    while (stk.empty() == false) {
        revPath.push(stk.top());
        stk.pop();
    }

    string ans;
    while (revPath.empty() == false) {
        ans += "/" + revPath.top();
        revPath.pop();
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s, '\n');  // cin.getline(arr, len, delimiter)

    string ans = simplifyPath2(s);
    cout << ans;

}