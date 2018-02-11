#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
};

node* insertatend(node* head, node* tail, int i){
	node* new_node = new node;
	new_node -> data = i;
	new_node -> next = 0;
	// return new_node;
	tail -> next = new_node;
	tail = new_node;
	return tail;
}


node* create(void){
	node* head = new node;
	node* tail = head;
	int i ;
	cin >> i;
	while(i != -1){
		// cin >> i;
		tail = insertatend(head, tail, i);
		cin >> i;
	}
	return head;
}


int print(node* head){
	node* current = head -> next;
	int len = 0;
	while(current){
		len ++;
		cout << current -> data << " --> ";
		current = current -> next;
	}
	return len;
}

node* mid(node* head){
	node* fast = head;
	node* slow = head;
	while(fast and fast -> next){
		fast = (fast -> next) -> next;
		slow = slow -> next;
	}
	node* head2 = new node;
	head2 -> next = slow -> next;
	slow -> next = 0;
	return head2;
}

void merge(node* head, node* head2, node* tail){
	node* list1 = tail -> next;
	node* list2 = head2 -> next;
	if(list1 and list2){
		if(list1 -> data <= list2 -> data){
			tail = tail -> next;
			list1 = list1 -> next;
		}
		else{
			node* list2_next = list2 -> next;
			tail -> next = list2;
			list2 -> next = list1;
			list2 = list2_next;
			head2 -> next = list2_next;
			tail = list1;
		}
		merge(head, head2, tail);
	}
	else if(list2){
		tail -> next = list2;
		return;
	}
	else{
		return;
	}
}

void mergesort(node* head){
	if((head -> next) -> next == 0){
		return;
	}
	node* head2 = mid(head);
	mergesort(head);
	mergesort(head2);
	merge(head, head2, head);
}

int main(){
	node* head = create();
	// print(head);
	// cout << endl;
	mergesort(head);
	print(head);
}
