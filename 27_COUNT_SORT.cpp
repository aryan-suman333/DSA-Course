#include <iostream>
#include <climits>

using namespace std;

void printarray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int maximum(int a[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		if(max < a[i])
			max = a[i];
	}
	return max;
}
void countSort(int a[], int n)
{
	int max = maximum(a, n);
	int * count = new int[max+1];
	int i, j;

	for (i = 0; i < max+1; ++i)   // initializing count array from 0
	{
		count[i] = 0;
	}

	for (i = 0; i < n; ++i)
	{
		count[a[i]]++;
	}

	i = 0; // counter for count array
	j = 0; // counter for given array

	while(i <= max)
	{
		if(count[i] > 0)
		{
			a[j] = i;
			count[i]--;
			j++;
		}
		i++;
	}
}

int main()
{
	int arr1[] = {12, 54, 65, 7, 23, 9};
	int n = 6;
	printarray(arr1, n);
	countSort(arr1, n);
	printarray(arr1, n);
	return 0;
}