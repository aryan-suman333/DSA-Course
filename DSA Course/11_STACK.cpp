#include<iostream>

using namespace std;

struct stack
{
	int size;
	int top;
	int * arr;	
};

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

int main(){
	// stack s;
	// s.size = 80;
	// s.top = -1;
	// s.arr = new int[s.size];

	stack * s; // pointer h to function ko pass krne m easy rhega
	s->size = 80;
	s->top = -1;
	s->arr = new int[s->size];

	if(isEmpty(s))
		cout<<"Stack is empty"<<endl;
	else cout<<"Stack is not empty"<<endl;

	s->arr[0] = 4;
	s->top++;
	if(isEmpty(s))
		cout<<"Stack is empty"<<endl;
	else cout<<"Stack is not empty"<<endl;

	return 0;
}