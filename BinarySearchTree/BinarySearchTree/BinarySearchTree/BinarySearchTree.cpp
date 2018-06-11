#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
	class node
	{
	public:
		node * left;
		node* right;
		node* parent;
		int key;
		string data;
	};


public:
	node * root;
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void INORDER_TREE_WALK(node*);
	void POSTORDER_TREE_WALK(node*);
	void PREORDER_TREE_WALK(node*);
	void DELETE(node*);
	int FIND_MAX(node*);
	node SUCCESSOR(node*);
	
	void TREE_INSERT(int);

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

	parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

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

void BinarySearchTree::POSTORDER_TREE_WALK(node *)
{
}

void BinarySearchTree::PREORDER_TREE_WALK(node *)
{
}

void BinarySearchTree::DELETE(node *)
{
}

int BinarySearchTree::FIND_MAX(node *)
{
	return 0;
}

node BinarySearchTree::SUCCESSOR(node *)
{
	return node();
}

int main()
{
	BinarySearchTree bst;
	int choice, key;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion " << endl;
		cout << " 2. Post-Order Traversal" << endl;
		cout << " 3. Pre-Order Traversal" << endl;
		cout << " 4. Find Max" << endl;
		cout << " 5. Remove Max" << endl;
		cout << " 6. Successor" << endl;
		cout << " 7. Delete" << endl;
		cout << " 8. Exit " << endl;

		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 2: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " -------------------" << endl;
			//Code needs to be added here
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			//Code needs to be added here
			break;
		case 4: cout << endl;
			cout << " Find Max " << endl;
			cout << " -------------------" << endl;
			//Code needs to be added here
			break;
		case 5: cout << endl;
			cout << " Remove Max " << endl;
			cout << " -------------------" << endl;
			//Code needs to be added here
			break;
		case 6: cout << endl;
			cout << " Successor " << endl;
			cout << " -------------------" << endl;
			//Code needs to be added here
			break;
		case 7: cout << endl;
			cout << " Delete " << endl;
			cout << " -------------------" << endl;
			//Code needs to be added here
			break;
		case 8: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}