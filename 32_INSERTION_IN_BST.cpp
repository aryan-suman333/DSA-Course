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

void insert(node * root, int val)
{
	node * temp = NULL;
	while(root != NULL)
	{
		temp = root;
		if(val == root->data)
		{
			cout<<"Cannot insert, "<<val<<" already present in BST "<<endl;
			return;
		}
		else if(val < root->data)
			root = root->left;
		else root = root->right;
	}
	node * n = createNode(val);
	if(val < temp->data)
		temp->left = n;
	else temp->right = n;
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

	insert(p, 7);
	insert(p, 2);

	cout<<p->right->right->data<<endl;
	cout<<p3->right->data<<endl;
	insert(p, 7);
	return 0;
}