// Deepak Aggarwal, deepak@codingblocks.com
// https://github.com/aggarwaldeepak/
#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *insertAtEnd(Node *head, int x, Node *&tail)
{
    if (head == NULL)
    {
        head = new Node(x);
        tail = head;
        return head;
    }

    tail->next = new Node(x);
    tail = tail->next;
    return head;
}

Node *createLL()
{
    int x;
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        head = insertAtEnd(head, x, tail);
    }
    return head;
}

void printLL(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << "-->";
        cur = cur->next;
    }
    cout << endl;
}

Node *midPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head; // set

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseLL(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    // A-->B
    Node *nextNode = head->next;
    Node *reveresedList = reverseLL(head->next);
    nextNode->next = head;
    head->next = NULL;
    return reveresedList;
}

Node *mergeList(Node *a, Node *b)
{
    if (!a) return b;
    if (b == NULL) return a;

    if (a->data < b->data){
        a->next = mergeList(a->next, b);
        return a;
    }
    else {
        b->next = mergeList(a, b->next);
        return b;
    }
}

Node *mergeSort(Node *head)
{
    if (!head or !head->next)
    {
        return head;
    }

    Node *midPt = midPoint(head);
    Node *a = head;
    Node *b = midPt->next;
    midPt->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);
    head = mergeList(a, b);
    return head;
}

Node* reverse2(Node* head);

Node* addNum(Node* a, Node* b){
    Node* revA = reverse2(a);
    Node* revB = reverse2(b);

    Node* curA = revA;
    Node* curB = revB;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;

    while(curA || curB || carry){
        int digA = curA ? curA->data : 0;
        int digB = curB ? curB->data : 0;
        int num = digA + digB + carry;
        int unitDig = num % 10;
        carry = num / 10;
        if (ansHead == NULL){
            ansHead = new Node(unitDig);
            ansTail = ansHead;
        } else {
            ansTail->next = new Node(unitDig);
            ansTail = ansTail->next;
        }
        if (curA) curA = curA->next;
        if (curB) curB = curB->next;        
    }
    revA = reverse2(revA);
    revB = reverse2(revB);
    ansHead = reverse2(ansHead);
    return ansHead;
}

Node* detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return slow;
        }
    }

    return NULL;
}


Node* reverse2(Node* head){
    Node* prevNode = NULL;
    Node* cur = head;
    while(cur){
        Node* nextNode = cur->next;
        cur->next = prevNode;
        prevNode = cur;
        cur = nextNode;
    }
    return prevNode;
}

void removeCycle(Node * head){
    Node* ans = detectCycle(head);
    if (!ans) return;

    Node* start = head;
    Node* meetingPoint = ans;
    while(start->next != meetingPoint->next){
        start = start->next;
        meetingPoint = meetingPoint->next;
    }

    meetingPoint->next = NULL;
}

int main()
{
    Node *head = createLL();
    printLL(head);

    // Node* mid = midPoint(head);
    // if (mid) cout << mid << " " <<  mid->data;

    // Node *reversedList = reverse2(head);
    // printLL(reversedList);

    // head = mergeSort(head);
    // printLL(head);

    // Node* a = createLL();
    // Node* b = createLL();
    // Node* ans = addNum(a, b);
    // printLL(a);
    // printLL(b);
    // cout << "-------------" << endl;
    // printLL(ans);

    head->next->next->next->next->next = head->next->next;
    Node* ans = detectCycle(head);
    if (ans) cout << ans << " " << ans->data << endl;
    // removeCycle(head);
    // printLL(head);

    return 0;
}