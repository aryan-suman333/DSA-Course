#include <iostream>
#include <math.h>
#define MAX 1000

using namespace std;

bool hash_table[MAX + 1][2]; // 1st column +ve k liye 2nd -ve k liye

bool search(int x)
{
	if(x >= 0)
	{
		if(hash_table[x][0] == 1)
		{
			cout<<"Element found "<<endl;
			return true;
		}
		else
		{
			cout<<"Element not found "<<endl;
			return false;
		}
	}
	else
	{
		if(hash_table[abs(x)][1] == 1)
		{
			cout<<"Element found "<<endl;
			return true;
		}
		else
		{ 
			cout<<"Element not found "<<endl;
			return false;
		}
	}
}

void insert(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if(arr[i] >= 0)
			hash_table[arr[i]][0] = 1;
		else 
			hash_table[abs(arr[i])][1] = 1;
	}
}

int main(){
	int arr[] = {-1, 9, 2, -8, 3, 1};

	insert(arr, 6);

	int s;
	cout<<"Enter the num to be searched "<<endl;
	cin>>s;

	search(s);
	return 0;
}