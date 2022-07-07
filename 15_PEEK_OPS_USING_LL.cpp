#include <iostream>

using namespace std;

struct node
{
	int data;
	node * next;
};

void LLTraversal(node * top){
	while(top != NULL){
		cout<<top->data<<endl;
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

node * push(node * top, int x){
	if(isFull(top)){
		cout<<"Stack overflow "<<endl;
	}
	node * p = new node;
	p->data = x;
	p->next = top;
	top = p;
	return top;
}

int peek(node * top, int pos){
	node * ptr = top;
	for (int i = 0; i < pos-1 && ptr != NULL; ++i)
	{
		ptr = ptr->next;
	}
	if(ptr != NULL)
		return ptr->data;
	else return -1;
}

int main(){
	node * top = NULL;
	top = push(top, 7);
	top = push(top, 9);
	top = push(top, 14);
	top = push(top, 19);
	LLTraversal(top);

	for (int i = 1; i <= 4; ++i)
	{
		cout<<"Value at position "<<i<<" is "<<peek(top, i)<<endl;
	}
	return 0;
}