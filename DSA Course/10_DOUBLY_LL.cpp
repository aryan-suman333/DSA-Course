#include<iostream>

using namespace std;

struct node{
	int data;
	node * prev;
	node * next;
};

void LLTraversalStart(node * ptr){
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void LLTraversalReverse(node * ptr){
	node * p = ptr;
	while(p->next != NULL){
		p = p->next;
	}
	while(p != NULL){
		cout<<p->data<<" ";
		p = p->prev;
	}
	cout<<endl;
}

node * insertAtFirst(node * head, int data){
	node * ptr = new node;
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = head;

	head->prev = ptr;
	head = ptr;
	return head;
}

node * insertAtLast(node * head, int data){
	node * ptr = new node;
	ptr->data = data;
	ptr->next = NULL;

	node * p = head;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = ptr;
	ptr->prev = p;
	return head;
}

node * deleteAValue(node * head, int value){
	node * p = head;
	node * q = head->next;
	node * r = q->next;
	while(q->data != value && q->next != NULL){
		p = p->next;
		q = q->next;
		r = r->next;
	}
	p->next = r;
	r->prev = p;
	delete q;
	return head;
}

int main(){
	node * head;
	node * second;
	node * third;
	node * fourth;
	head = new node;
	second = new node;
	third = new node;
	fourth = new node;

	head->data = 7;
	head->prev = NULL;
	head->next = second;
	second->data =11;
	second->prev = head;
	second->next = third;
	third->data = 66;
	third->prev = second;
	third->next = fourth;
	fourth->data = 79;
	fourth->prev = third;
	fourth->next = NULL;

	LLTraversalStart(head);
	LLTraversalReverse(head);

	head = insertAtFirst(head, 4);
	LLTraversalStart(head);
	LLTraversalReverse(head);

	head = insertAtLast(head, 95);
	LLTraversalStart(head);
	LLTraversalReverse(head);
	
	head = deleteAValue(head, 66);
	LLTraversalStart(head);
	LLTraversalReverse(head);
	
	return 0;
}