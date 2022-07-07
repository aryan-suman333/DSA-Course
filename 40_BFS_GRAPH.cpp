#include <iostream>

using namespace std;

struct queue
{
	int size;
	int f;
	int r;
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
		return;
	else{
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
	q.size = 400;
	q.f = -1;
	q.r = -1;
	q.arr = new int[q.size];

    //BFS Implementation
    int node;
    int i = 1; // jis node se start krna h
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int a[7][7] = { // adjcancy matrix representation
        {0, 1, 1, 1, 0, 0, 0},    //  0--1
        {1, 0, 0, 1, 0, 0, 0},    //  | \|
        {1, 0, 0, 1, 1, 0, 0},    //  2--3
        {1, 1, 1, 0, 1, 0, 0},    //   \/
        {0, 0, 1, 1, 0, 1, 1},    //   4
        {0, 0, 0, 0, 1, 0, 0},    /*  / \   */
        {0, 0, 0, 0, 1, 0, 0},    // 5   6
    };

	cout<<i;
	visited[i] = 1; // jisko visit kr diya uska index 1 kr diya
	enqueue(&q, i);
	while (!isEmpty(&q))
	{
		int node = dequeue(&q);
		for (int j = 0; j < 7; j++) // exploring node
		{
			if(a[node][j] == 1 && visited[j] == 0){ // koi node se connected h or 											 abhi tk visited nhi h 
				cout<<j;
				visited[j] = 1;
				enqueue(&q, j);
			}
		}
	}
    return 0;
}