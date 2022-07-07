#include <iostream>

using namespace std;

void printarray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void selectionSort(int a[], int n)
{
	int indexOfMin, temp;
	for (int i = 0; i < n-1; ++i)
	{
		indexOfMin = i;
		for (int j = i+1; j < n; ++j)
		{
			if(a[j] < a[indexOfMin])
				indexOfMin = j;
		}
		temp = a[i];
		a[i] = a[indexOfMin];
		a[indexOfMin] = temp;
	}
}

int main()
{
	int arr1[] = {3, 5, 2, 13, 12};
	int n = 5;

	printarray(arr1, n);
	selectionSort(arr1, n);
	printarray(arr1, n);

	return 0;
}