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
		root = z;
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

void BinarySearchTree::flightRequest(node * root, int timeArrival, int k)
{
	int flightnumber;
	BinarySearchTree::node* tmp = root;
	if (root = NULL)
	{
		cout << "you are clear for landing" << endl;
		cout << "What is your flight number?";
		cin >> flightnumber;
		TREE_INSERT(timeArrival, flightnumber);
	}
	else if (tmp != NULL)
	{
		while (tmp->right != NULL)
		{
			if (tmp->arrivalTime >= timeArrival)
			{
				if (k >= (timeArrival - tmp->arrivalTime) && k >= (tmp->right->arrivalTime - timeArrival))
				{
					cout << "you are clear for landing" << endl;
					cout << "What is your flight number?";
					cin >> flightnumber;
					TREE_INSERT(timeArrival, flightnumber);


				}
			}
		}
	}
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->arrivalTime << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}


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





\
int main()
{
	BinarySearchTree bst;
	cout << "Welcome to SkyHarbor" << endl;
	bst.flightRequest(bst.root, 45, 1);
	bst.flightRequest(bst.root, 60, 1);

	bst.PREORDER_TREE_WALK(bst.root);
	system("pause");

	return 0;

	
}

void flightRequest(BinarySearchTree::node* root,int timeArrival, int k)
{
	BinarySearchTree bst;
	int flightnumber;
	BinarySearchTree::node* tmp = root;
	if(tmp = NULL)
	{
		cout << "you are clear for landing" << endl;
		cout << "What is your flight number?";
		cin >> flightnumber;
		bst.TREE_INSERT(timeArrival, flightnumber);
	}
	else if (tmp != NULL)
	{
		while (tmp->right != NULL)
		{
			if (tmp->arrivalTime >= timeArrival)
			{
				if (k >= (timeArrival - tmp->arrivalTime) && k >= (tmp->right->arrivalTime - timeArrival))
				{
					cout << "you are clear for landing" << endl;
					cout << "What is your flight number?";
					cin >> flightnumber;
					bst.TREE_INSERT(timeArrival, flightnumber);


				}
			}
		}
	}
}
