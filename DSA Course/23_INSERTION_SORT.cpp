#include<iostream>

using namespace std;

void printarray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void insertionSort(int a[], int n)
{
	int key, j;
	for (int i = 1; i <= n-1; ++i)  // for no. of passes
	{
		key = a[i];
		j = i-1;
		while(a[j] > key && j >= 0) // for each pass' comparison
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key; // j+1 isliye kyoki last m ek baar j-- hoga
	}
}

int main()
{
	int arr1[] = {12, 54, 65, 7, 23, 9};
	int n = 6;
	printarray(arr1, n);
	insertionSort(arr1, n);
	printarray(arr1, n);
	return 0;
}