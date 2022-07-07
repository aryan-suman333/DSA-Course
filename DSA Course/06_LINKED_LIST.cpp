#include<iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

void LLTraversal(node * ptr){
	while(ptr != NULL){
		cout<<ptr->data<<' ';
		ptr = ptr->next;
	}
	cout<<endl;
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
	return 0;
}
