// Deepak Aggarwal, deepak@codingblocks.com
// https://github.com/aggarwaldeepak/
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* insertAtEnd(Node* head, int x, Node* &tail){
    if (head == NULL){
        head = new Node(x);
        tail = head;
        return head;
    }

    tail->next = new Node(x);
    tail = tail->next;
    return head;
}

Node* createLL(){
    int x;
    Node* head = NULL;
    Node* tail = NULL;

    while(true){
        cin >> x;
        if (x == -1) break;
        head = insertAtEnd(head, x, tail);
    }
    return head;
}

void printLL(Node* head){
    Node* cur = head;
    while(cur != NULL){
        cout << cur->data << "-->";
        cur = cur->next;
    }
    cout << endl;
}

Node* sortList(Node* head){
    Node* cur = head;
    Node* prevNode = NULL;

    while(cur){
        if (prevNode != NULL && cur->data < 0){
            prevNode->next = cur->next;
            cur->next = head;
            head = cur;
            cur = prevNode->next;
        }
        else {
            prevNode = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main(){
    Node* head = createLL();
    printLL(head);

    Node * updatedList = sortList(head);
    printLL(updatedList);

    return 0;
}