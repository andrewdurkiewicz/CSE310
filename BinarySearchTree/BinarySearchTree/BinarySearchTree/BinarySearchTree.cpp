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
		int key; //flight number
		double time; //landing time
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
	void TREE_INSERT(int);
	void DELETE(node*);
	BinarySearchTree::node* FIND_FLIGHT(node* root, int flightnumber);
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

void BinarySearchTree::POSTORDER_TREE_WALK(node *x)
{
}

void BinarySearchTree::PREORDER_TREE_WALK(node *x)
{
}

void BinarySearchTree::DELETE(node*T, node *z)
{
	
}

BinarySearchTree::node * BinarySearchTree::FIND_FLIGHT(node* x, int flightnumber)
{

	BinarySearchTree::node* minimum = FIND_MIN(x);
	try
	{

		while (true)
		{
			if (SUCCESSOR(minimum) == NULL)
			{
				throw SUCCESSOR(minimum);
			}
			else if (minimum->key = flightnumber)
			{
				return minimum;
			}
			else
			{
				minimum = SUCCESSOR(minimum);
			}
		}
	}
	catch (node* x)
	{
		cout << flightnumber << "Not found" << endl;

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
		cout << " 4. In-Order Traversal" << endl;
		cout << " 5. Find Max" << endl;
		cout << " 6. Remove Max" << endl;
		cout << " 7. Successor" << endl;
		cout << " 8. Delete" << endl;
		cout << " 9. Exit " << endl;

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
			bst.POSTORDER_TREE_WALK(bst.root);
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.PREORDER_TREE_WALK(bst.root);
			break;
		case 4: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 5: cout << endl;
			cout << " Find Max " << endl;
			cout << " -------------------" << endl;
			cout << "The Maximum Key is: " << bst.FIND_MAX(bst.root)->key << endl;;
			break;
		case 6: cout << endl;
			cout << " Remove Max " << endl;
			cout << " -------------------" << endl;
			//Code needs to be added here
			break;
		case 7: cout << endl;
			cout << " Successor " << endl;
			cout << " -------------------" << endl;
			cout << "The Successor of: " << bst.root->key << " is: " << bst.SUCCESSOR(bst.root)->key << endl;
			break;
		case 8: cout << endl;
			cout << " Delete " << endl;
			cout << " -------------------" << endl;
			cout << "Which Flight Number would you like to cancel?" << endl << flush;
			int flightnumber;
			cin >> flightnumber;
			b deletethis = bst

			break;
		case 9: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}