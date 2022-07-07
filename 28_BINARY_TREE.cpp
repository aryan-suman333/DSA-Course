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

int main()
{
	node * p = createNode(2); // root node
	node * p1 = createNode(1);
	node * p2 = createNode(4);

	p->left = p1;
	p->right = p2;
	return 0;
}