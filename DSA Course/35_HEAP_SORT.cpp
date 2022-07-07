#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

class minHeap
{
	public:
		int * arr;
		int capacity;
		int size;

		minHeap(int cap)  // constructor for creation of heap
		{
			size = cap;
			capacity = cap;
			arr = new int[cap];
		}

		void display()
		{
			for (int i = 0; i < size; ++i) 
				cout<<arr[i]<<" ";
			cout<<endl;
		}

		int left(int i)
		{
			return (2*i + 1);
		}

		int right(int i)
		{
			return (2*i + 2);
		}

		void minHeapify(int i)
		{
			int l = left(i);
			int r = right(i);
			int smallest = i;

			if(l < size && arr[l] < arr[i])
				smallest = l;
			if(r < size && arr[r] < arr[smallest])
				smallest = r;
			if(smallest != i)
			{
				swap(arr[i], arr[smallest]);
				minHeapify(smallest);
			}
		}

		int extractMin()
		{
			if(size <= 0)
			{
				cout<<"Heap is empty "<<endl;
				return INT_MAX;
			}

			if(size == 1)
			{
				size--;
				return arr[0];
			}

			int root = arr[0];
			arr[0] = arr[size-1];
			size--;
			minHeapify(0);
			return root;
		}

		void getUnsortedArray()
		{
			cout<<"Enter "<<capacity<<" no of elements to sort using HeapSort "<<endl;
			for (int i = 0; i < capacity; ++i)
				cin>>arr[i];
		}

		void heapSort()
		{
			int tempo[capacity];
			for (int j = 0; j < capacity; ++j)
			{
				tempo[j] = extractMin();
				cout<<tempo[j]<<" ";
			}
			cout<<endl;
		}
};

int main()
{
	int s;
	cout<<"Enter the capacity "<<endl;
	cin>>s;

	minHeap obj(s);
	cout<<"MinHeap created "<<endl;

	obj.getUnsortedArray();

	cout<<"Unsorted array "<<endl;
	obj.display();

	for (int i = s/2-1; i >= 0; --i) // leaf node k ek level upar se start hoga
		obj.minHeapify(i);
	
	cout<<"Heap sorted array "<<endl;
	obj.heapSort();
	return 0;
}