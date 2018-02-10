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

Node* midPoint(Node* head){
    Node* slow = head;
    Node* fast = head;  // set

    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseLL(Node* head){
    if(!head || !head->next){
        return head;
    }

    // A-->B
    Node* nextNode = head->next;
    Node* reveresedList = reverseLL(head->next);
    nextNode->next = head;
    head->next = NULL;
    return reveresedList;
}

int main(){
    Node* head = createLL();
    printLL(head);

    // Node* mid = midPoint(head);
    // if (mid) cout << mid << " " <<  mid->data;

    Node * reversedList = reverseLL(head);
    printLL(reversedList);

    return 0;
}