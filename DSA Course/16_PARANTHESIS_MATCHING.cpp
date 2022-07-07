#include <iostream>
#include <string>

using namespace std;

struct stack
{
	int size;
	int top;
	char * arr;	
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

void push(stack * ptr, char value){
	if(isFull(ptr))
		cout<<"Stack overflow, can't push "<<value<<endl;
	else{
		ptr->top++;
		ptr->arr[ptr->top] = value;
	}
}

char pop(stack * ptr){
	if(isEmpty(ptr)){
		cout<<"Stack underflow, can't pop"<<endl;
		return -1;
	}
	else{
		char val = ptr->arr[ptr->top];
		ptr->top--;
		cout<<"Popped "<<val<<" from the stack"<<endl;
		return val;
	}
}

int paranthesisMatch(const char * exp){
	stack * sp = new stack;
	sp->size = 100;
	sp->top = -1;
	sp->arr = new char[sp->size];
	for (int i = 0; exp[i] != '\0'; ++i)
	{
		if(exp[i] == '('){
			push(sp, exp[i]);
		}
		else if(exp[i] == ')'){
			if(isEmpty(sp))
				return 0;
			pop(sp);
		}
	}
	if(isEmpty(sp))
		return 1;
	else return 0;
}

int main(){

	const char * s1 = "8*(9)";
	const char * s2 = "8*(9))";
	const char * s3 = "8)*(9";

	if(paranthesisMatch(s1))
		cout<<"Paranthesis is matching "<<endl;
	else cout<<"Paranthesis is not matching "<<endl;

	if(paranthesisMatch(s2))
		cout<<"Paranthesis is matching "<<endl;
	else cout<<"Paranthesis is not matching "<<endl;

	if(paranthesisMatch(s3))
		cout<<"Paranthesis is matching "<<endl;
	else cout<<"Paranthesis is not matching "<<endl;

	return 0;
}