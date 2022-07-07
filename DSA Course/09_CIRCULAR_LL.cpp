#include<iostream>

using namespace std;

struct node
{
	int data;
	node * next;	
};

void LLTraversal(node * head){
	node * ptr = head;
	do{
		cout<<ptr->data<<' ';
		ptr = ptr->next;
	}while(ptr != head);
	cout<<endl;
}

node * insertAtHead(node * head, int data){
	node * ptr = new node;
	ptr->data = data;
	node * p = head->next;

	while(p->next != head){  // p last m point krega loop k end m
		p = p->next;
	}

	p->next = ptr;
	ptr->next = head;
	head = ptr;
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

	head->data = 4;
	head->next = second;
	second->data =3;
	second->next = third;
	third->data = 6;
	third->next =fourth;
	fourth->data = 1;
	fourth->next = head;

	LLTraversal(head);

	head = insertAtHead(head, 80);
	LLTraversal(head);
	return 0;
}
