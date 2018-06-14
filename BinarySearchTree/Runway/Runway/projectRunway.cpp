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
	cout << "DELETE" << " " << z->arrivalTime;
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
		z->arrivalTime = temp->arrivalTime;
		temp->parent->left = NULL;
		delete[] temp;


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
			if (k >= (timeArrival - tmp->arrivalTime))
			{
				clearedForLanding(timeArrival);
			}
		}
		else if (tmp->right != NULL)
		{
			if (k >= (timeArrival - tmp->arrivalTime) && k >= (timeArrival - tmp->right->arrivalTime))
			{
				clearedForLanding(timeArrival);
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



BinarySearchTree::node * BinarySearchTree::SEARCH(node* x, int arrivalTime)
{

	BinarySearchTree::node* minimum = FIND_MIN(x);

	while (x->right != NULL)
	{
		if (x->arrivalTime == arrivalTime)
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
	int LT, choice, timegap;

	while (true)
	{
		cout << "Welcome to SkyHarbor" << endl;
		cout << "What option would you like to see? " << endl;
		cout << "1. Add a flight." << endl;
		cout << "2. Print the current flight list" << endl;
		cout << "3. Remove a flight from the current list" << endl;
		cout << "4. Exit" << endl << flush;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "What time gap are we looking at here? " << endl << flush;
			cin >> timegap;
			cout << "This is Roblox runway 32B, What is your landing time inbound? " << endl << flush;
			cin >> LT;
			bst.flightRequest(bst.root, LT, timegap);
			break;
		case 2:
			bst.INORDER_TREE_WALK(bst.root);
			break;

		default:
			break;
		}

	}
	system("pause");

	return 0;

	
}


