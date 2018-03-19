// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>
using namespace std;
struct Node {
    bool isTerminal;
    map<char, Node*> m;
    Node(){
        isTerminal = false;
    }

};

class Trie {
    Node* masterRoot;
public:
    Trie() {
        masterRoot = new Node();
        masterRoot->isTerminal = false;
    }

    void addWord(string s) {   // apple
        Node* root = masterRoot;
        for (int i = 0; i < s.size(); ++i) {
            char curChar = s[i];
            if (root->m.find(curChar) == root->m.end()) {
                root->m[curChar] = new Node;
            }
            root = root->m[curChar];
        }
        root->isTerminal = true;
    }

    bool search(string s) {
        Node* root = masterRoot;
        for (int i = 0; i < s.size(); ++i) {
            char curChar = s[i];
            if (root->m.find(curChar) == root->m.end()){
                return false;
            }
            root = root->m[curChar];
        }
        return root->isTerminal == true;
    }
};

int main() {
    Trie t;
    string s;
    t.addWord("apple");
    // t.addWord("ap");
    cout << t.search("app") << endl;
    cout << t.search("apple");
}