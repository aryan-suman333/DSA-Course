#include <iostream>

using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

node * createNode(int val)
{
	node * n = new node;
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

node * bin_search(node * root, int val)
{
	if(root == NULL)
		return NULL;
	if(root->data == val)
		return root;
	else if(val < root->data)
		return bin_search(root->left, val);
	else
		return bin_search(root->right, val);
}

int main()
{
	node * p = createNode(5);
	node * p1 = createNode(3);
    node * p2 = createNode(6);
	node * p3 = createNode(1);
	node * p4 = createNode(4);

	//   5
	//  / \
	//  3  6
	// / \
	//1   4
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;	

	// node * n = bin_search(p, 4);
	// if(n != NULL)
	// 	cout<<"Found: "<<n->data<<endl;
	// else cout<<"Element not found "<<endl;

	node * n = bin_search(p, 7);
	if(n != NULL)
		cout<<"Found: "<<n->data<<endl;
	else cout<<"Element not found "<<endl;
	return 0;
}