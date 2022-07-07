#include <iostream>

using namespace std;

void display(int arr[], int n){
	for (int i = 0; i < n; ++i) // traversal
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void indexDeletion(int arr[], int s, int in){ 
	for (int i = in; i < s-1; ++i)
	{
		arr[i] = arr[i+1];
	}
}

int main(){
	int arr[100] = {7, 8, 12, 27, 88};
	int size = 5, capacity = 100, index = 3;
	display(arr, size);

	indexDeletion(arr, size, index);
	size -= 1;
	display(arr, size);

	return 0;
}
