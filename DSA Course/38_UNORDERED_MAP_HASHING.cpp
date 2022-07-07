#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map <string, int> umap; // unordered m order insertion jesa same nhi rhega
	umap["aryan"] = 44;       // mtlb jo pehle insert krenge vo pehle rhega ye jruri nhi
	umap["gfg"] = 56;
	umap["hw"] = 98;

	// map <string, int> :: iterator iter; ese likh k iterator bhi chla skte h
	for(auto x : umap)
	{
		cout<<x.first<<" "<<x.second<<"; ";
	}
	cout<<endl;

	umap.insert(make_pair("mobile", 88));

	cout<<umap.size()<<endl;

	// use in hashing

	int arr[] = {1, 3, 0, 14, 3, 7, 9, 12, 2, 7, 3, 13, 8, 9, 5};

	unordered_map <int, int> umap2;
	for (int i = 0; i < 15; ++i)
	{
		int key = arr[i];
		umap2[key]++;
	}

	for (auto it = umap2.begin();it != umap2.end(); it++)
	{
		cout<<it->first<<" "<<it->second<<"; ";
	}
	return 0;
}