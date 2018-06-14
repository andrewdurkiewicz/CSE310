#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:



public:
	class node
	{
	public:
		node * left;
		node* right;
		node* parent;
		int key; //k
		int time; //landing time
	};
	node * root;
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void INORDER_TREE_WALK(node*);
	void POSTORDER_TREE_WALK(node*);
	void PREORDER_TREE_WALK(node*);
	void TREE_INSERT(int);
	void DELETE(node*);
	BinarySearchTree::node* SEARCH(node* root, int key);
	BinarySearchTree::node* FIND_MAX(node*);
	BinarySearchTree::node* SUCCESSOR(node*);
	BinarySearchTree::node* FIND_MIN(node*);



};

void BinarySearchTree::TREE_INSERT(int d)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->key = d;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

}

void BinarySearchTree::DELETE(node *z)

{
	cout << "DELETE" << " " << z->key;
	BinarySearchTree::node* temp;

	if ((z->left == NULL) && (z->right == NULL))//No children
	{
		temp = z->parent;
		if (temp->right == z)
		{
			temp->right = NULL;

		}
		else if (temp->left == z)
		{
			temp->left = NULL;
		}
		delete[] z;
	}
	else if ((z->right == NULL) && (z->left != NULL))
	{

		temp = z->parent;
		z = z->left;
		z->parent = temp;
		temp->left = z;
	}
	else if ((z->left == NULL) && (z->right != NULL))
	{
		temp = z->parent;
		z = z->right;
		z->parent = temp;
		temp->right = z;
	}
	else if ((z->left != NULL) && (z->right != NULL))
	{
		temp = FIND_MIN(z->right);
		z->key = temp->key;
		temp->parent->left = NULL;
		delete[] temp;


	}
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}


}

void BinarySearchTree::POSTORDER_TREE_WALK(node *x)
{
	if (x != NULL)
	{
		POSTORDER_TREE_WALK(x->left);
		POSTORDER_TREE_WALK(x->right);
		cout << " " << x->key << " ";
	}


}

void BinarySearchTree::PREORDER_TREE_WALK(node *x)
{
	if (x != NULL)
	{
		cout << " " << x->key << " ";
		PREORDER_TREE_WALK(x->left);
		PREORDER_TREE_WALK(x->right);
	}
}



BinarySearchTree::node * BinarySearchTree::SEARCH(node* x, int key)
{

	BinarySearchTree::node* minimum = FIND_MIN(x);

	while (x->right != NULL)
	{
		if (x->key == key)
		{
			return x;
		}
		else
		{
			x = x->right;
		}
	}


}

BinarySearchTree::node * BinarySearchTree::FIND_MAX(node *x)
{
	while (x->right != NULL)
	{
		x = x->right;
	}
	return x;
}

BinarySearchTree::node * BinarySearchTree::SUCCESSOR(node *x)
{
	if (x->right == NULL)
	{
		return x->parent;
	}
	else
	{
		return FIND_MIN(x->right);
	}
}

BinarySearchTree::node * BinarySearchTree::FIND_MIN(node *x)
{
	BinarySearchTree::node* minimum = x;

	if (x->left != NULL)
	{
		minimum = x->left;
		FIND_MIN(minimum);
	}
	return minimum;
}





bool flightRequest(BinarySearchTree::node* flightNode);

int main()
{
	BinarySearchTree bst;
	BinarySearchTree::node* x = new BinarySearchTree::node();
	BinarySearchTree::node* y = new BinarySearchTree::node();

	return 0;

	
}

bool flightRequest(BinarySearchTree::node * flightNode)
{
	int k = flightNode->key;
	if (k >= (flightNode->right->time - flightNode->left->time))
	{
		return true;
	}
	else
	{
		return false;
	}
\}
