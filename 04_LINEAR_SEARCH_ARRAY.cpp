#include<iostream>

using namespace std;

int linearsearch(int arr[], int s, int e){
	for (int i = 0; i < s; ++i)
	{
		if(arr[i] == e){
			return i;
			break;
		}
	}
	return -1;
}

int main(){
	int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 54634, 56, 34};
	int size = sizeof(arr)/sizeof(int), element;
	cout<<"Enter number: ";
	cin>>element;
	int searchindex = linearsearch(arr, size, element);

	if(searchindex != -1)
		cout<<"The element "<<element<<" was found at index "<<searchindex<<endl;
	else cout<<"Element not found"<<endl;

	return 0;
}