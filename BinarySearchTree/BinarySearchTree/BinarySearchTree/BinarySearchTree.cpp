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
		int key; //flight number
		double time; //landing time
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
	void DELETE(node*, node*,node*);
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

void BinarySearchTree::DELETE( node* x, node* y, node *z)
{

	if ((z->left == NULL) || (z->right == NULL))
	{
		y = z;
	}
	else if ((z->left != NULL) && (z->right != NULL))
	{
		y = SUCCESSOR(z);
	}
	if (y->left != NULL)
	{
		x = y->left;
	}
	else if (y->left == NULL)
	{
		x = y->right;
	}
	if (x != NULL)
	{
		x->parent = y->parent;
	}
	if (y->parent == NULL)
	{
		root = x;
	}
	else if (y->parent != NULL)
	{
		if (y = y->parent->left)
		{
			y->parent->left = x;
		}
		else
		{
			y->parent->right = x;
		}
	}
	if (y != z)
	{
		z->key = y->key;
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







int main()
{
	BinarySearchTree bst;
	BinarySearchTree::node* x = new BinarySearchTree::node();
	BinarySearchTree::node* y = new BinarySearchTree::node();

	int newChoice;

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
			cout << "The Maximum Key is: " << bst.FIND_MAX(bst.root)->key << endl;;
			cout << "Now Deleteing Max..." << endl;
			bst.DELETE(x, y, bst.FIND_MAX(bst.root));


			break;
		case 7: cout << endl;
			cout << " Successor " << endl;
			cout << " -------------------" << endl;
			cout << "Which value do you want to find the successor of?" << endl << flush;
			cin >> newChoice;
			x = bst.SEARCH(bst.root, newChoice);
			cout << "The Successor of: " << x->key << " is: " << bst.SUCCESSOR(x)->key<< endl;
			break;
		case 8: cout << endl;

			cout << " Delete " << endl;
			cout << " -------------------" << endl;
			bst.DELETE(x, y, bst.root);
			break;
		case 9: system("pause");
			break;
		default:
			cout << "Invalid choice";
		}
		
	}
}
