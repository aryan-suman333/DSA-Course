#include <iostream>

using namespace std;

struct node
{
	int data;
	node * next;
};

void LLTraversal(node * top){
	while(top != NULL){
		cout<<top->data<<" ";
		top = top->next;
	}
	cout<<endl;
}

int isEmpty(node * top){
	if(top == NULL)
		return 1;
	else return 0;
}

int isFull(node * top){
	node * q = new node;
	if(q == NULL)        // heap m memory available nhi hogi to q null ho jaega mtlb
		return 1;        // stack full
	else return 0;
}

node* push(node* top, int x){
	if(isFull(top)){
		cout<<"Stack overflow "<<endl;
	}
	node* p = new node;
	p->data = x;
	p->next = top;
	top = p;
	return top;
}

node * pop(node * top){
	if(isEmpty(top)){
		cout<<"Stack underflow "<<endl;
	}
	node * p = top;
	top = top->next;
	int e = p->data;
	delete(p);
	cout<<"Popped "<<e<<" from stack"<<endl;
	return top;
}

int main(){
	node * top = NULL;
	top = push(top, 7);
	top = push(top, 9);
	top = push(top, 14);
	top = push(top, 19);
	LLTraversal(top);

	top = pop(top);
	LLTraversal(top);
	return 0;
}