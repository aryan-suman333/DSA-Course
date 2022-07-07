#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set <int> s; // unordered m order insertion jesa same nhi rhega
	s.insert(10);          // mtlb jo pehle insert krenge vo pehle rhega ye jruri nhi
	s.insert(5);	
	s.insert(15);	
	s.insert(20);

	// unordered_set <int> :: iterator it; ya to ese likhlo ya it k pehle auto likhlo
	for(auto it = s.begin(); it != s.end(); it++)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;

	cout<<s.size()<<endl;

	s.insert(20);         
	cout<<s.size()<<endl; // same element vps insert nhi hoga isliye size 4 hi rhega

	// s.clear();
	// cout<<s.size()<<endl;

	s.erase(15);
	cout<<s.size()<<endl;
	return 0;
}