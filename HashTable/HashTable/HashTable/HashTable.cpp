#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct node
{
	node * left;
	node * right;
	node * head;
	string name;
	string ALevel;
	double gpa;
	int key;
};

int getTotalStudents(int type);
void insert(node *hash[65536], int k, string thisName, string thisLevel, double thisGPA);
int main()
{
	int choice,k, levelChoice;
	string stu_name;
	string thislevel;
	double GPA;
	string level[4] = { "Freshman", "Sophomore", "Junior", "Senior" };

	node** hash =  new node*[65536];
	while (true)
	{
		cout << "Welcome to Arizona State University. There Are currently " << getTotalStudents(0) << " students in our system" << endl;
		cout << "1. Insert a student" << endl;
		cout << "2. Delete a student" << endl << flush;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "What is his/her name?" << endl << flush;
			cin >> stu_name;
			cout << "What is their academic level? Select from the following:" << endl;
			cout << "1. Freshman" << endl << "2. Sophomore" << endl << "3. Junior" << endl << "4. Senior" << endl << flush;
			cin >> levelChoice;
			thislevel = level[levelChoice + 1];
			cout << "What is their GPA?" << endl;
			cin >> GPA;
			cout << "What is the key value?" << endl;
			cin >> k;
			insert(hash, k, stu_name, thislevel, GPA);
		}
	}
	system("pause");
	return 0;

}

int getTotalStudents(int type) //type 0 is reading, type 1 is increasing, type 2 is decreasing
{
	static int size = 0;
	switch (type)
	{
	case 0 :
		break;
	case 1:
		size++;
	case 2:
		size--;
	};
	return size;
}

void insert(node* hash[65536], int k, string thisName, string thisLevel, double thisGPA)
{
	int size = getTotalStudents(0);
	if (size <= 10000)
	{

		node* n = new node();
		int key = k % 1000;
		if (hash[key] != NULL)
		{
			//chain
			node* tmp = hash[key];
			n->head = tmp;
			while (tmp->right != NULL)
			{
				tmp = tmp->right;
			}
			tmp->right = n;
			n->left = tmp;
			n->name = thisName;
			n->ALevel = thisLevel;
			n->gpa = thisGPA;
			
		}
		else if (hash[key] == NULL)
		{
			hash[key] = n;
			n->head = n;
			n->left = NULL;
			n->name = thisName;
			n->ALevel = thisLevel;
			n->gpa = thisGPA;
			n->right = NULL;
		}
		getTotalStudents(1);
	}
	else
	{
		cout << "University Full" << endl;
	}
}


