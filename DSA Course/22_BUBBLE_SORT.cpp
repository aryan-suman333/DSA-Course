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

void bubbleSortAdaptive(int a[], int n)
{
	int temp;
	for (int i = 0; i < n-1; ++i)      // for no. of passes
	{
		int isSorted = 1;
		for (int j = 0; j < n-1-i; ++j)  // for each pass' comparison
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				isSorted = 0;
			}
		}
		cout<<"Pass "<<i+1<<endl;
		if(isSorted)
			return;
	}
}

void bubbleSort(int a[], int n)
{
	int temp;
	for (int i = 0; i < n-1; ++i)      // for no. of passes
	{
		for (int j = 0; j < n-1-i; ++j)  // for each pass' comparison
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		cout<<"Pass "<<i+1<<endl;
	}
}

int main()
{
	int arr1[] = {12, 54, 65, 7, 23, 9};
	int arr2[] = {1, 2, 3, 4, 5, 6};
	int arr3[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 967};
	int n = 6;

	printarray(arr1, n);
	bubbleSortAdaptive(arr1, n);
	bubbleSort(arr1, n);
	printarray(arr1, n);

	printarray(arr2, n);
	bubbleSortAdaptive(arr2, n);
	bubbleSort(arr2, n);
	printarray(arr2, n);

	printarray(arr3, 11);
	bubbleSortAdaptive(arr3, 11);
	bubbleSort(arr3, 11);
	printarray(arr3, 11);
	return 0;
}