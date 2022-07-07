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

void inorder(node * root)
{
	if(root != NULL)
	{	
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

node * inorder_predecessor(node * root)
{
	root = root->left;         // inorder predecessor left subtree ka rightmost element
							   // hota h
	while(root->right != NULL)
		root = root->right;
	return root;
}

node * del_node(node * root, int val)
{
	node * inpre;
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL)
	{
		delete(root);
		return NULL;
	}

	// searching of the node
	if(val < root->data)
		root->left = del_node(root->left, val);
	else if(val > root->data)
		root->right = del_node(root->right, val);

	// deleting the node
	else 
	{
		inpre = inorder_predecessor(root);
		root->data = inpre->data;
		root->left = del_node(root->left, inpre->data);
	}
	return root;
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

	inorder(p);
    cout<<endl;
    del_node(p, 5);
    inorder(p);
	return 0;
}