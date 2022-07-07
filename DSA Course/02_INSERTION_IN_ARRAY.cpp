#include <iostream>

using namespace std;

void display(int arr[], int n){
	for (int i = 0; i < n; ++i) // traversal
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void indexInsertion(int arr[], int s, int e, int in){ 
	for (int i = s-1; i >= in ; --i)
	{
		arr[i+1] = arr[i];
	}
	arr[in] = e;
}

int main(){
	int arr[100] = {7, 8, 12, 27, 88};
	int size = 5, element = 45, capacity = 100, index = 3;
	display(arr, size);
	if(size < capacity){
		indexInsertion(arr, size, element, index);
		size += 1;
		display(arr, size);
	}

	return 0;
}
