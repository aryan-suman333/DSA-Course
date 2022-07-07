#include<iostream>

using namespace std;

class myArray{
	int total_size;
	int used_size;
	int * ptr;
	friend void createArray(myArray*, int, int);
	friend void show(myArray *);
	friend void setVal(myArray *);
};

void createArray(myArray * a, int tSize, int uSize){
	(*a).total_size = tSize;
	a->used_size = uSize;
	a->ptr = new int[tSize]; // malloc pointer return krta h
}

void show(myArray * a){
	for (int i = 0; i < a->used_size; ++i)
	{
		cout<<(a->ptr)[i]<<endl;
	}
}

void setVal(myArray * a){
	int n;
	for (int i = 0; i < a->used_size; ++i)
	{
		cout<<"Enter element"<<i<<endl;
		cin>>n;
		(a->ptr)[i] = n;
	}
}

int main(){
	myArray marks;
	createArray(&marks, 10, 2);
	setVal(&marks);
	show(&marks);

	return 0;
}
