#include<iostream>

using namespace std;

struct node
{
	int data;
	node * next;
};

void LLTraversal(node * ptr){
	while(ptr != NULL){
		cout<<ptr->data<<endl;
		ptr = ptr->next;
	}
	cout<<endl;
}

node* insertAtFirst(node * head, int data){
	node* ptr = new node;
	ptr->next = head;
	ptr->data = data;
	return ptr;
}

node* insertAtIndex(node * head, int data, int index){
	node* ptr = new node;
	node* p = head;
	int i = 0;
	while(i != index-1){
		p = p->next;
		i++;
	}
	ptr->data = data;
	ptr->next = p->next;
	p->next = ptr;
	return head;
}

node * insertAtEnd(node * head, int data){
	node * ptr = new node;
	ptr->data = data;
	node * p = head;

	while(p->next != NULL){
		p = p->next;
	}
	p->next = ptr;
	ptr->next = NULL;
	return head;
}

node * insertAfterNode(node * head,node * previousNode, int data){
	node * ptr = new node;
	ptr->data = data;
	ptr->next = previousNode->next;
	previousNode->next = ptr;
	return head;
}

int main(){
	node* head;
	node* second;
	node* third;
	head = new node;
	second = new node;
	third = new node;

	head->data = 7;
	head->next = second;
	second->data =11;
	second->next = third;
	third->data = 66;
	third->next = NULL;

	LLTraversal(head);

	head = insertAtFirst(head, 56);
	LLTraversal(head);

	head = insertAtIndex(head, 64, 3);
	LLTraversal(head);

	head = insertAtEnd(head, 70);
	LLTraversal(head);

	head = insertAfterNode(head, second, 44);
	LLTraversal(head);
	return 0;
}