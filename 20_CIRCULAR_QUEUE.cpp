#include <iostream>

using namespace std;

struct circularQueue
{
	int size;
	int f;    // front 
	int r;    // rear
	int * arr;
};

int isFull(circularQueue * q){
	if(((q->r+1) % q->size) == q->f)
		return 1;
	else return 0;
}

int isEmpty(circularQueue * q){
	if(q->r == q->f)
		return 1;
	else return 0;
}

void enqueue(circularQueue * q, int val){
	if(isFull(q))
		cout<<"This queue is full "<<endl;
	else{
		cout<<"Enqueued  element "<<val<<endl;
		q->r = (q->r+1) % q->size;
		q->arr[q->r] = val;
	}
}

int dequeue(circularQueue * q){
	int a = -1;
	if(isEmpty(q))
		cout<<"This queue is empty "<<endl;
	else{
		q->f = (q->f+1) % q->size;
		a = q->arr[q->f];
	}
	return a;
}

int main(){
	circularQueue q;
	q.size = 100;
	q.f = 0;
	q.r = 0;
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