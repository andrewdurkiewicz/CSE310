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







int main()
{
	BinarySearchTree bst;
	BinarySearchTree::node* x = new BinarySearchTree::node();
	BinarySearchTree::node* y = new BinarySearchTree::node();

	int delChoice;
	int SucChoice;

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
			bst.DELETE(bst.FIND_MAX(bst.root));
			break;
		case 7: cout << endl;
			cout << " Successor " << endl;
			cout << " -------------------" << endl;
			cout << "Which value do you want to find the successor of?" << endl << flush;
			cin >> SucChoice;
			x = bst.SEARCH(bst.root, SucChoice);
			cout << "The Successor of: " << x->key << " is: " << bst.SUCCESSOR(x)->key<< endl;
			break;
		case 8: cout << endl;
			cout << " Delete " << endl;
			cout << " -------------------" << endl;
			cout << "Enter the key for which you want to delete: " << endl << flush;
			cin >> delChoice;
			bst.DELETE(bst.SEARCH(bst.root, delChoice));
			
			break;
		case 9: system("pause");
			break;
		default:
			cout << "Invalid choice";
		}
		
	}
}
