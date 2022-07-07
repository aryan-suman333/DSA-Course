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

void merge(int a[], int mid, int low, int high)
{
	int i = low, j = mid+1, k = low, b[high + 1];
	// mid+1 as partition k baad se j shuru hoga

	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}

	while(i <= mid)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		b[k] = a[j];
		j++;
		k++;
	}
	for (int x = low; x <= high; ++x)
	{
		a[x] = b[x];
	}
}

void mergeSort(int a[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a , mid, low, high);
	}
}

int main()
{
	int arr1[] = {12, 54, 65, 7, 23, 9, 34};
	int n = 7;
	printarray(arr1, n);
	mergeSort(arr1, 0, n-1);
	printarray(arr1, n);
	return 0;
}