#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

struct node
{
	node * right = NULL;
	node * head = NULL;
	string name = "";
	string ALevel = "";
	double gpa;
	int key;
};

int getTotalStudents(int type);
void insert(node *hash[1000], int keyValue, string thisName, string thisLevel, double thisGPA);
void printList(node*hash[1000]);
int main()
{
	srand(time(0));
	int choice, levelChoice;
	string stu_name, last_Name, thislevel;
	double GPA;
	string level[4] = { "Freshman", "Sophomore", "Junior", "Senior" };

	node* hash[1000];

	for (int i = 0; i < 1000; i++)
	{
		hash[i] = new node;
	}
	while (true)
	{
		int keyValue = rand() % 65536;
		int index = keyValue % 1000;

		cout << "Welcome to Arizona State University. There Are currently " << getTotalStudents(0) << " students in our system" << endl;
		cout << "1. Insert a student" << endl;
		cout << "2. Delete a student" << endl << flush;
		cout << "3. Print current list" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter first name?" << endl << flush;
			cin >> stu_name;
			cout << "Enter Last name?" << endl << flush;
			cin >> last_Name;
			stu_name = stu_name + " " + last_Name;
			cout << "What is their academic level? Select from the following:" << endl;
			cout << "1. Freshman" << endl << "2. Sophomore" << endl << "3. Junior" << endl << "4. Senior" << endl << flush;
			cin >> levelChoice;
			thislevel = level[levelChoice - 1];
			cout << "What is their GPA?" << endl;
			cin >> GPA;
			cout << "attempting to add in index: " << index << endl;
			insert(hash, keyValue, stu_name, thislevel, GPA);
		case 2:
			break;
		case 3:
			printList(hash);
			break;

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

void insert(node* hash[1000], int keyValue, string thisName, string thisLevel, double thisGPA)
{
	int size = getTotalStudents(0);
	if (size <= 10000)
	{

		node* tmp;
		int index = keyValue % 1000;
		if (hash[index]->head != NULL) // check, is it empty?
		{
			tmp = hash[index]->head;
			//if it is not, we need to get to the last element to add to the chain while checking the key values
			while (tmp->right != NULL)
			{
				if (tmp->key = keyValue)
				{
					cout << "Error, Key already exist" << endl;
					continue;
				}
				else
				{
					tmp = tmp->right;
				}
			}
			//when we get to the end we need to add it.
			node* n = new node;
			tmp->right = n;
			n->head = tmp->head;
			n->ALevel = thisLevel;
			n->gpa = thisGPA;
			n->key = keyValue;
			n->right = NULL;
			n->name = thisName;
		}
		else if (hash[index]->head == NULL)
		{
			hash[index]->gpa = thisGPA;
			hash[index]->name = thisName;
			hash[index]->ALevel = thisLevel;
			hash[index]->head = hash[index];
			hash[index]->right = NULL;
			hash[index]->key = keyValue;

		}
		getTotalStudents(1);
		}
		else
		{
			cout << "University Full" << endl;
		}
	}

void printList(node * hash[1000])
{
	node* tmp;
	for (int i = 0; i < 1000; i++)
	{
		if (hash[i]->head == NULL)
		{
			continue;
		}
		else
		{
			tmp = hash[i]->head;
			cout << "Index:" << i << " " << tmp->name << " | GPA: " << tmp->gpa << " | Academic level: " << tmp->ALevel <<  endl;
			while (tmp->right != NULL)
			{
				tmp = tmp->right;
				cout << "Index:" << i << " " << tmp->name << " | GPA: " << tmp->gpa << " | Academic level: " << tmp->ALevel << endl;
			}
		}
	}
	cout << endl << endl;
}
