#include<iostream>

using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
    int height;
};

int max(int a, int b){
    return a>b?a:b;
}

int getHeight(node  * n){
    if(n == NULL)
        return 0;
    return n->height;
}

node * createNode(int val)
{
	node * n = new node;
	n->data = val;
	n->left = NULL;
	n->right = NULL;
    n->height = 1;
	return n;
}

int getBalanceFactor(node * n){
    if(n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node * rightRotate(node * y){
    node * x = y->left;    //     y        node x bnaya jo y k left k equal h
    node * t2 = x->right;  //    / \       node t2 bnaya jo x k right k equal h
                           //   x   t3
    x->right = y;          //  / \         rotation k baad x ka right y ho jaega
    y->left = t2;          // t1  t2       rotation k baad y ka left t2 ho jaega

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x; // x ab root node h
}
node * leftRotate(node * x){
    node * y = x->right;   //     x        node y bnaya jo x k right k equal h
    node * t2 = y->left;   //    / \       node t2 bnaya jo y k left k equal h
                           //   t1  y
    y->left = x;           //      / \     rotation k baad y ka left x ho jaega
    x->right = t2;         //     t2  t3   rotation k baad x ka right t2 ho jaega

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y; // y ab root node h
}

node * insert(node * root, int val)
{
	if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    if(val > root->data)
        root->right = insert(root->right, val);

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    // LL Case
    if(bf > 1 && val < root->left->data){
        return rightRotate(root);
    }

    // RR Case
    if(bf < -1 && val > root->right->data){
        return leftRotate(root);
    }

    // LR Case
    if(bf > 1 && val > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if(bf < -1 && val < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
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

int main(){
    node * root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);
    return 0;
}