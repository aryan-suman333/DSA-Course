#include<iostream>

using namespace std;

struct node{
	int data;
	node * next;
};

void LLTraversal(node * ptr){
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

node * deleteAtFirst(node * head){
	node * ptr = new node;
	ptr = head;
	head = head->next;
	delete ptr;
	return head;
}

node* deleteAtIndex(node * head, int index){
	node* p = head;

	int i = 0;
	while(i != index-1){
		p = p->next;
		i++;
	}

	node* q = p->next;
	p->next = q->next;
	delete q;
	return head;
}

node * deleteAtEnd(node * head){
	node * p = head;
	while(p->next->next != NULL){
		p = p->next;
	}
	
	node* q = p->next;
	p->next = NULL;
	delete q;
	return head;
}

node * deleteAValue(node * head, int value){
	node * p = head;
	node * q = head->next;

	while(q->data != value && q->next != NULL){
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	delete q;
	return head;
}

int main(){
	node * head;
	node * second;
	node * third;
	node * fourth;
	node * fifth;
	node * sixth;
	head = new node;
	second = new node;
	third = new node;
	fourth = new node;
	fifth = new node;
	sixth = new node;

	head->data = 7;
	head->next = second;
	second->data =11;
	second->next = third;
	third->data = 66;
	third->next = fourth;
	fourth->data = 74;
	fourth->next = fifth;
	fifth->data = 89;
	fifth->next = sixth;
	sixth->data = 101;
	sixth->next = NULL;

	LLTraversal(head);

	head = deleteAtFirst(head); 
	LLTraversal(head);
	
	head = deleteAtIndex(head, 1); 
	LLTraversal(head);

	head = deleteAtEnd(head); 
	LLTraversal(head);

	head = deleteAValue(head, 89); 
	LLTraversal(head);
	return 0;
}
