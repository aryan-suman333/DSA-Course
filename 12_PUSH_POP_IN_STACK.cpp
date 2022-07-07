#include<iostream>

using namespace std;

struct stack
{
	int size;
	int top;
	int * arr;	
};

void traversal(stack * ptr){
	if(ptr->top == -1){
		cout<<"Stack is empty"<<endl;
	}
	else{
	for (int i = 0; i < ptr->top+1; ++i)
	{
		cout<<ptr->arr[i]<<" ";
	}
	cout<<endl;
	}
}

int isEmpty(stack * ptr){
	if(ptr->top == -1)
		return 1;
	else return 0;
}

int isFull(stack * ptr){
	if(ptr->top == (ptr->size -1))
		return 1;
	else return 0;
}

void push(stack * ptr, int value){
	if(isFull(ptr))
		cout<<"Stack overflow, can't push "<<value<<endl;
	else{
		ptr->top++;
		ptr->arr[ptr->top] = value;
	}
}

int pop(stack * ptr){
	if(isEmpty(ptr)){
		cout<<"Stack underflow, can't pop"<<endl;
		return -1;
	}
	else{
		int val = ptr->arr[ptr->top];
		ptr->top--;
		cout<<"Popped "<<val<<" from the stack"<<endl;
		return val;
	}
}

int main(){
	stack * s = new stack;
	s->size = 10;
	s->top = -1;
	s->arr = new int[s->size];

	push(s, 2);
	cout<<isEmpty(s)<<endl;

	push(s, 5);
	push(s, 9);
	push(s, 15);
	push(s, 23);
	push(s, 44);
	push(s, 56);
	push(s, 64);
	push(s, 73);
	push(s, 89);
	cout<<isFull(s)<<endl;

	traversal(s);
	push(s, 101);

	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	pop(s);
	traversal(s);
	
	cout<<isEmpty(s)<<endl;
	return 0;
}