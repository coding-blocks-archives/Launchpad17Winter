// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node {
public:
    string key;
    string val;
    Node* next;
    Node() {
        next = NULL;
    }
};

class Hashmap {
private:
    Node** table;
    int capacity;
    int nElements;

    void clearTable() {
        for (int i = 0; i < capacity; ++i) {
            table[i] = NULL;
        }
    }

    int hashCode(string s) {
        int mul = 1;
        const int M = 31;
        int code = 0;

        for (int i = 0; i < s.size(); ++i) {
            int tmp = ((s[i] % capacity) * (mul % capacity)) % capacity;
            code = code + tmp;
            code = code % capacity;
            mul = ((mul % capacity) * (M % capacity)) % capacity;
        }
        return code;
    }

    double load_factor(){
        return (double)nElements / capacity;
    }

    void rehash(){
        int oldCapacity = capacity;
        capacity =  2 * oldCapacity;
        Node** oldTable = table;

        table = new Node*[capacity];
        clearTable(); 
        nElements = 0;

        for(int i = 0; i < oldCapacity; ++i){
            Node* head = oldTable[i];
            while(head){
                Node* ahead = head->next;
                head->next = NULL;
                insertIntoTable(head);
                head = ahead;
            }
        }
        delete [] oldTable;
    }

    void insertIntoTable(Node* curNode) {
        int idx = hashCode(curNode->key);
        Node* &head = table[idx];

        curNode->next = head;
        head = curNode;
        ++nElements;
        if (load_factor() > 0.7){
            rehash();
        }
    }

public:
    Hashmap() {
        capacity = 7;    // Research
        nElements = 0;
        table = new Node*[capacity];
        clearTable();
    }

    void insert(string s, string val) {
        Node* keyValPair = new Node;
        keyValPair->key = s;
        keyValPair->val = val;
        insertIntoTable(keyValPair);
    }

    string search(string key){
        int idx = hashCode(key);
        Node* head = table[idx];
        while(head){
            if (head->key == key){
                return head->val;
            }
            head = head->next;
        }
        return "Error: Not Found";
    }

    string remove(string key){

    }

    ~Hashmap(){
        for(int i = 0; i < capacity; ++i){
            Node* head = table[i];
            while(head){
                Node* ahead = head->next;
                delete head;
                head = ahead;
            }
        }
        delete [] table;
    }
};


int main() {
    Hashmap h;
    h.insert("ishaan", "123");
    h.insert("sid", "456");
    cout << h.search("sid") << endl;
    cout << h.search("chehak") << endl;
}