#include <iostream>
#include <cstdlib>
#include <cmath>
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
		int flightnumber;
		int arrivalTime; //landing time
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
	void TREE_INSERT(int,int);
	void DELETE(node*);
	void flightRequest(node*, int, int);
	void clearedForLanding(int);
	void swap(BinarySearchTree::node*, BinarySearchTree::node*);
	BinarySearchTree::node* SEARCH(node* root, int arrivalTime);
	BinarySearchTree::node* FIND_MAX(node*);
	BinarySearchTree::node* SUCCESSOR(node*);
	BinarySearchTree::node* FIND_MIN(node*);



};

void BinarySearchTree::TREE_INSERT(int timeArrival, int flightNumber)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->arrivalTime = timeArrival;
	z->flightnumber = flightNumber;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->arrivalTime < x->arrivalTime)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		this->root = z;
	else if (z->arrivalTime < y->arrivalTime)
		y->left = z;
	else
		y->right = z;

}

void BinarySearchTree::DELETE(node *z)
{
	node* y = new node();
	if (z->left == NULL)
	{
		swap(z, z->right);
	}
	else if (z->right == NULL)
	{
		swap(z, z->left);
	}
	else
	{
		y = FIND_MIN(z->right);
		if (y->parent != z)
		{
			swap(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		swap(z, y);
		y->left = z->left;
		y->left->parent = y;
	}


}

void BinarySearchTree::swap(BinarySearchTree::node *u, BinarySearchTree::node *v) //from the book
{
	if (u->parent == NULL)
	{
		root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	if (v != NULL)
	{
		v->parent = u->parent;
	}
}

void BinarySearchTree::flightRequest(node * tmp, int timeArrival, int k)
{
	if (tmp == NULL)
	{
		clearedForLanding(timeArrival);
	}
	else if (tmp != NULL)
	{
		if (tmp->right == NULL)
		{
			if (k <= abs(timeArrival - tmp->arrivalTime))
			{
				clearedForLanding(timeArrival);
			}
			else
			{
				cout << "You are NOT clear to land, not enough time between" << endl;
			}
		}
		else if (tmp->right != NULL)
		{
			if (k <= abs(timeArrival - tmp->arrivalTime) && k <= abs(timeArrival - tmp->right->arrivalTime))
			{
				clearedForLanding(timeArrival);
			}
			else
			{
				cout << "You are NOT clear to land, not enough time between" << endl;
			}
		}

	}
}
void BinarySearchTree::INORDER_TREE_WALK(node *x)
{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << "Flight #" << x->flightnumber << " Arriving in: " << x->arrivalTime << " Minutes" << endl;
		if (x->right) INORDER_TREE_WALK(x->right);
	}
void BinarySearchTree::clearedForLanding(int timeArrival)
{
	int FNumber;
	cout << "you are clear for landing" << endl;
	cout << "What is your flight number? ";
	cin >> FNumber;
	TREE_INSERT(timeArrival, FNumber);
}





void BinarySearchTree::POSTORDER_TREE_WALK(node *x)
{
	if (x != NULL)
	{
		POSTORDER_TREE_WALK(x->left);
		POSTORDER_TREE_WALK(x->right);
		cout << " " << x->arrivalTime << " ";
	}


}

void BinarySearchTree::PREORDER_TREE_WALK(node *x)
{
	if (x != NULL)
	{
		cout << " " << x->arrivalTime << " ";
		PREORDER_TREE_WALK(x->left);
		PREORDER_TREE_WALK(x->right);
	}
}



BinarySearchTree::node * BinarySearchTree::SEARCH(node* x, int FN)
{

	BinarySearchTree::node* minimum = FIND_MIN(x);

	while (x->right != NULL)
	{
		if (x->flightnumber == FN)
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
	BinarySearchTree::node* temp;
	int LT, choice, timegap, cancelChoice;
	cout << "Welcome to SkyHarbor" << endl;
	cout << "What time gap are we looking at here? " << endl << flush;
	cin >> timegap;
	while (true)
	{
		cout << "What option would you like to see? " << endl;
		cout << "1. Add a flight." << endl;
		cout << "2. Print the current flight list" << endl;
		cout << "3. Remove a flight from the current list" << endl;
		cout << "4. Exit" << endl << flush;
		cin >> choice;

		switch (choice)
		{
		case 1:

			cout << "This is Roblox runway 32B, What is your landing time inbound? " << endl << flush;
			cin >> LT;
			bst.flightRequest(bst.root, LT, timegap);
			break;
		case 2:
			bst.INORDER_TREE_WALK(bst.root);
			
			break;
		case 3:
			bst.INORDER_TREE_WALK(bst.root);
			cout << "Which Flight would you like to cancel? " << endl;
			cin >> cancelChoice;
			temp = bst.SEARCH(bst.root, cancelChoice);
			bst.DELETE(temp);
			bst.INORDER_TREE_WALK(bst.root);
		case 4:
			exit(0);
		default:
			cout << "Error: Not an option" << endl;
			break;
		}
		cout << endl << endl;

	}
	system("pause");

	return 0;

	
}


