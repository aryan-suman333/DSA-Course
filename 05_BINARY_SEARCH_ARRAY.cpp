#include<iostream>

using namespace std;

int binarysearch(int arr[], int s, int e){
	int l = 0, m , h = s-1;

	while(l <= h){
		m = (l + h)/2;
		if(arr[m] == e)
			return m;
		else if(arr[m] < e)
			l = m+1;        // pta h ki m to e nhi h
		else h = m-1;       // pta h ki m to e nhi h
	}
	return -1;
}

int main(){
	int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
	int element, size = sizeof(arr)/sizeof(int);
	cout<<"Enter number: ";
	cin>>element;
	int searchindex = binarysearch(arr, size, element);

	if(searchindex != -1)
		cout<<"The element "<<element<<" was found at index "<<searchindex<<endl;
	else cout<<"Element not found"<<endl;

	return 0;
}