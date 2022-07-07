#include <iostream>
#include <queue>

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

void preorder(node * root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node * root)
{
	if(root != NULL)
	{	
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
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

void levelorder(node * root){
	queue <node*> q;
	cout<<root->data<<" ";
	q.push(root);

	while(!q.empty()){
		root = q.front();
		q.pop();
		if(root->left){
			cout<<root->left->data<<" ";
			q.push(root->left);
		}
		if(root->right){
			cout<<root->right->data<<" ";
			q.push(root->right);
		}
	}
}

int main()
{
	node * p = createNode(4);
	node * p1 = createNode(1);
    node * p2 = createNode(6);
	node * p3 = createNode(5);
	node * p4 = createNode(2);

	//   4 
	//  / \
	//  1  6
	// / \
	//5   2 
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;

	preorder(p);   // 4 1 5 2 6 (root left right)
	cout<<endl;
	postorder(p);  // 5 2 1 6 4 (left right root)
	cout<<endl;
	inorder(p);    // 5 1 2 4 6 (left root right)
	cout<<endl;
	levelorder(p); // 4 1 6 5 2 (left root right)
	return 0;
}