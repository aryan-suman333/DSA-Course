#include <iostream>
#include <string.h>

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
		return val;
	}
}

int precedence(char ch){
	if(ch == '*' || ch == '/')
		return 2;
	else if(ch == '+' || ch == '-')
		return 1;
	else return 0;
}

int isOperator(char ch){
	if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
		return 1;
	else return 0;
}

char * infToPost(const char * infix){

	struct stack * sp = new stack;
	sp->size = 100;

	sp->top = -1;
	sp->arr = new char[sp->size];

	char * postfix = new char[strlen(infix) + 1];
	int i = 0;   // for infix traversal
	int j = 0;   // for postfix

	while(infix[i] != '\0')
	{
		if(!isOperator(infix[i]))
		{
			postfix[j] = infix[i];
			i++;
			j++;
		}
		else if(precedence(infix[i]) > precedence(sp->arr[sp->top]))
		{
			push(sp, infix[i]);
			i++;
		}
		else
		{
			postfix[j] = pop(sp);
			j++;
		}
	}
	while(!isEmpty(sp))      // stack m agar last m koi operator bcha h to
	{
		postfix[j] = pop(sp);
		j++;
	}
	postfix[j] = '\0';
	return postfix;
}

int main(){

	const char * infix1 = "a-b+t/6";
	cout<<"Postfix is "<<infToPost(infix1)<<endl;

	const char * infix2 = "a-b";
	cout<<"Postfix is "<<infToPost(infix2)<<endl;
	
	const char * infix3 = "x-y/z-k*d";
	cout<<"Postfix is "<<infToPost(infix3)<<endl;
	
	return 0;
}