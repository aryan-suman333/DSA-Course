#include <iostream>

using namespace std;

struct queue
{
	int size;
	int f;    // front 
	int r;    // rear
	int * arr;
};

int isFull(queue * q){
	if(q->r == q->size-1)
		return 1;
	else return 0;
}

int isEmpty(queue * q){
	if(q->r == q->f)
		return 1;
	else return 0;
}

void enqueue(queue * q, int val){
	if(isFull(q))
		cout<<"This queue is full "<<endl;
	else{
		cout<<"Enqueued element "<<val<<endl;
		q->r++;
		q->arr[q->r] = val;
	}
}

int dequeue(queue * q){
	int a = -1;
	if(isEmpty(q))
		cout<<"This queue is empty "<<endl;
	else{
		q->f++;
		a = q->arr[q->f];
	}
	return a;
}

int main(){
	queue q;
	q.size = 100;
	q.f = -1;
	q.r = -1;
	q.arr = new int[q.size];

	if(isEmpty(&q))
		cout<<"Queue is empty "<<endl;

	enqueue(&q, 12);
	enqueue(&q, 15);
	enqueue(&q, 18);

	cout<<dequeue(&q)<<endl;
	cout<<dequeue(&q)<<endl;
	cout<<dequeue(&q)<<endl;


	if(isEmpty(&q))
		cout<<"Queue is empty "<<endl;
	return 0;
}