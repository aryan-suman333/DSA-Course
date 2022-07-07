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

int partition(int a[], int low, int high)
{
	int pivot = a[low], temp;
	int i = low+1;
	int j = high;
	do
	{
	 	while(a[i] <= pivot && i <= high)
			i++;
		while(a[j] > pivot && j >= low)
			j--;
		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	} while (i < j);

	temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	return j;
}

void quickSort(int a[], int low, int high)
{
	int partitionIndex; // index of pivot after partition

	if(low < high)
	{
		partitionIndex = partition(a, low, high);
		printarray(a, 9);
		quickSort(a, low, partitionIndex-1);      // sorting left subarray
		quickSort(a, partitionIndex+1, high);     // sorting right subarray
	}
}

int main()
{
	int arr1[] = {8, 5, 7, 12, 13, 3, 2, 45, 30};
	int n = 9;

	printarray(arr1, n);
	quickSort(arr1, 0, n-1);
	printarray(arr1, n);
	
	return 0;
}