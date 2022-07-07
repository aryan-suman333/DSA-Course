#include<iostream>

using namespace std;

struct stack
{
	int size;
	int top;
	int * arr;
};

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

int peek(stack * ptr, int i){
	int val = (ptr->top - i + 1);
	if(val < 0){
		cout<<"Invalid position "<<endl;
		return -1;
	}
	else return ptr->arr[val];
}

int main(){
	stack * s = new stack;
	s->size = 10;
	s->top = -1;
	s->arr = new int[s->size];

	push(s, 2);
	push(s, 5);
	push(s, 9);
	push(s, 15);
	push(s, 23);
	push(s, 44);
	push(s, 56);
	push(s, 64);
	push(s, 73);
	push(s, 89);

	for (int j = 1; j < s->top+2; ++j){
		cout<<"The value at position "<<j<<" is "<<peek(s, j)<<endl;
	}
	return 0;
}