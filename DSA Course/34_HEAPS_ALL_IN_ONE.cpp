#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

class minHeap
{
	public:
		int * arr;
		int capacity;
		int size;

		minHeap(int cap)  // constructor for creation of heap
		{
			size = 0;
			capacity = cap;
			arr = new int[cap];
		}

		void linearsearch(int e)
		{
			for (int i = 0; i < size; ++i)
			{
				if(arr[i] == e)
					return;
			}
			cout<<"Element not found "<<endl;
		}

		void display()
		{
			for (int i = 0; i < size; ++i) 
				cout<<arr[i]<<" ";
			cout<<endl;
		}

		int getMin()
		{
			return arr[0];
		}

		int height()
		{
			return ceil(log2(size + 1)) - 1;
		}

		int parent(int i)
		{
			return (i-1)/2;
		}

		int left(int i)
		{
			return (2*i + 1);
		}

		int right(int i)
		{
			return (2*i + 2);
		}

		void insertkey(int k)
		{
			if(size == capacity)
			{
				cout<<"Heap overflow, can't insert "<<endl;
				return;
			}

			size++;
			int i = size - 1;
			arr[i] = k;

			while(i != 0 && arr[parent(i)] > arr[i])
			{
				swap(arr[i], arr[parent(i)]);
				i = parent(i);  // ab key jaha gyi h usko uske parent se compare krenge
			}
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
			arr[0] = arr[size-1]; // root ki jagah last element ko de denge
			size--;
			minHeapify(0);        // phir heapify kr denge
			return root;
		}

		void decreaseKey(int i, int min)
		{
			arr[i] = min;
			while(i != 0 && arr[parent(i)] > arr[i])
			{
				swap(arr[i], arr[parent(i)]);
				i = parent(i);
			}
		}

		void deleteKey(int i)
		{
			decreaseKey(i, INT_MIN);
			extractMin();
		}
};

int main()
{
	int s;
	cout<<"Enter the capacity "<<endl;
	cin>>s;

	minHeap obj(s);
	cout<<"MinHeap created "<<endl;

	int option, val;
	do{
		cout<<"What operation do you want to perform? "<<"Enter 0 to exit. "<<endl;
		cout<<"1. Insert key/node "<<endl;
		cout<<"2. Search key/node "<<endl;
		cout<<"3. Delete key/node "<<endl;
		cout<<"4. Get Min "<<endl;
		cout<<"5. Extract Min "<<endl;
		cout<<"6. Height of heap "<<endl;
		cout<<"7. Print/Traversal heap "<<endl;
		cout<<"8. Clear screen "<<endl;
		cout<<"0. Exit Program "<<endl;

		cin>>option;

		switch(option)
		{
			case 0:
				break;
			case 1:
			    cout<<"Enter value to insert in heap "<<endl;
			    cin>>val;
			    obj.insertkey(val);
			    cout<<val<<" inserted successfully "<<endl;
			    break;
			case 2:
				cout<<"Enter value to search in heap "<<endl;
				cin>>val;
				obj.linearsearch(val);
				break;
			case 3:
				cout<<"Enter index to delete in heap "<<endl;
				cin>>val;
				obj.deleteKey(val);
				cout<<"Element at index "<<val<<" deleted successfully "<<endl;
				break;
			case 4:
				cout<<obj.getMin()<<endl;
				break;
			case 5:
				cout<<obj.extractMin()<<endl;
				break;
			case 6:
				cout<<obj.height()<<endl;
				break;
			case 7:
				obj.display();
				break;
			case 8:
				system("clear"); // ye kaam na kre to system("cls");
				break;
			default:
			    cout<<"Enter proper option number "<<endl;
			    break;
		}
	}while(option != 0);

	return 0;
}