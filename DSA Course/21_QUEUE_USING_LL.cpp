#include <iostream>

using namespace std;

struct node
{
	int data;
	node * next;
};

node * f = NULL;
node * r = NULL;

void LLTraversal(node * ptr){
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void enqueue(int val){
	node * n = new node;
	if(n == NULL)                     // ll full ki condition check
		cout<<"Queue is full"<<endl;
	else{
		n->data = val;
		n->next = NULL;
		if(f == NULL){       // queue empty hogi to f or r dono null honge isliye dono
							 //	ko n p point kraenge
			f = r = n;
		}
		else{
			r->next = n;
			r = n;       // rear ab last wala node hoga
		}
	}
}

int dequeue(){
	int val = -1;
	node * ptr = f;

	if(f == NULL)                     // queue empty ki condition check
		cout<<"Queue is empty "<<endl;
	else{
		f = f->next;
		val = ptr->data;
		delete(ptr);
	}
	return val;
}

int main(){
	LLTraversal(f);
	cout<<"Dequeuing "<<dequeue()<<endl;

	enqueue(4);
	enqueue(7);
	enqueue(9);
	LLTraversal(f);

	cout<<"Dequeuing "<<dequeue()<<endl;
	cout<<"Dequeuing "<<dequeue()<<endl;
	cout<<"Dequeuing "<<dequeue()<<endl;

	LLTraversal(f);
	return 0;
}