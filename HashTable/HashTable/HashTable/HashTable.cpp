#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

struct node
{
	node * right;
	node * head;
	string name;
	string ALevel;
	double gpa;
	int key;
};

int getTotalStudents(int type);
void insert(node *hash[1000], int k, string thisName, string thisLevel, double thisGPA);
int main()
{
	srand(time(0));
	int choice, levelChoice;
	string stu_name;
	string thislevel;
	double GPA;
	string level[4] = { "Freshman", "Sophomore", "Junior", "Senior" };

	node* hash[1000];
	node* tmp = new node;
	tmp->right = NULL;
	tmp->name = "";
	tmp->ALevel = "";
	tmp->gpa = 0.0;
	tmp->head = NULL;

	for (int i = 0; i < 1000; i++)
	{
		hash[i] = tmp;
	}
	while (true)
	{
		int k = rand() % 65536;
		int index = (k) % 1000;

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
			thislevel = level[levelChoice - 1];
			cout << "What is their GPA?" << endl;
			cin >> GPA;
			cout << "attempting to add in index: " << index << " with a key value of: " << k << endl;
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
	case 0:
		break;
	case 1:
		size++;
		break;
	case 2:
		size--;
		break;
	};
	return size;
}

void insert(node* hash[1000], int k, string thisName, string thisLevel, double thisGPA)
{
	int size = getTotalStudents(0);
	if (size <= 10000)
	{

		node* n = new node();
		int index = k % 1000;
		if (hash[index] != NULL)
		{
			//chain
			node* tmp = hash[index];
			n->head = tmp;
			while (tmp->right != NULL)
			{
				if (tmp->right->key != k)
				{
					tmp = tmp->right;

				}
				else
				{
					cout << "Error! key already exists! Rehash necessary" << endl;
					break;
				}

				tmp->right = n;
				n->name = thisName;
				n->ALevel = thisLevel;
				n->gpa = thisGPA;
				n->key = k;

			}
		else if (hash[index] == NULL)
		{
			hash[index] = n;
			n->head = n;
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