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

int main();

int getTotalStudents(int type);
void insert(node *hash[1000], int keyValue, string thisName, string thisLevel, double thisGPA);
void printList(node*hash[1000]);
void Delete(node* hash[1000], int kV);
node *Search(node* hash[1000], int findKey);
int main()
{
	srand(time(0));
	int choice, levelChoice, Dy, Sy;
	string stu_name, last_Name, thislevel;
	double GPA;
	string level[4] = { "Freshman", "Sophomore", "Junior", "Senior" };

	node* hash[1000];

	for (int i = 0; i < 1000; i++)
	{
		hash[i] = new node;
	}
	cout << endl << "Welcome to Arizona State University." << endl << endl;
	while (true)
	{
		node* iterate;
		node* tmp; 
		node* fromsearch;

		int kv;

		cout << "# of Students in Database: "<< getTotalStudents(0) << endl;
		cout << "Select From the Menu Below:" << endl;
		cout << "------------------------------" << endl;
		cout << "1. Insert a student" << endl;
		cout << "2. Delete a student" << endl << flush;
		cout << "3. Print current list" << endl;
		cout << "4. Search the table" << endl;
		cout << "9. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl << "Enter first name: " << endl << flush;
			cin >> stu_name;
			cout << endl << "Enter Last name: " << endl << flush;
			cin >> last_Name;
			stu_name = stu_name + " " + last_Name;
			cout << endl << "What is their academic level? Select from the following:" << endl;
			cout << "1. Freshman" << endl << "2. Sophomore" << endl << "3. Junior" << endl << "4. Senior" << endl << flush;
			cin >> levelChoice;
			thislevel = level[levelChoice - 1];
			cout << endl << "What is their GPA?" << endl;
			cin >> GPA;
			cout << endl << "Enter a key value (between 0-65536)" << endl << flush;
			cin >> kv;
			while (kv < 0 && kv> 65536)
			{
				cout << "Error, key must be between 0 and 65536, please retry." << endl << flush;
				cin >> kv;
			}
			insert(hash, kv, stu_name, thislevel, GPA);
			cout << endl << "Insert Completed" << endl << endl;
			break;
		case 2:
			cout << "Enter a key value (between 0-65536) to Delete: " << endl << flush;
			cin >> Dy;
			while (Dy < 0 && Dy> 65536)
			{
				cout << "Error, key must be between 0 and 65536, please retry." << endl << flush;
				cin >> Dy;
			}
			Delete(hash, Dy);

			break;
		case 3:
			printList(hash);
			break;
		case 4:
			cout << "Enter a key value (between 0-65536) to search for: " << endl << flush;
			cin >> Sy;
			while (Sy < 0 && Sy> 65536)
			{
				cout << "Error, key must be between 0 and 65536, please retry." << endl << flush;
				cin >> Sy;
			}
			fromsearch = Search(hash, Sy);
			if (fromsearch == NULL)
			{
				cout << "Nothing was found with a key value of: " << Sy;
			}
			else
			{
				cout << "The following student profile was located with a key value of: " << endl << Sy;
				cout << "Name: " << fromsearch->name << endl;
				cout << "GPA: " << fromsearch->gpa << endl;
				cout << "Academic Level" << fromsearch->ALevel << endl;
			}
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
				//int compare = tmp->key;
				if (tmp->key == keyValue)
				{
					cout << "Error, Key already exist" << endl;
					break;
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

void Delete(node * hash[1000], int kV)
{
	node* find = Search(hash, kV);

	node* tmp = hash[(kV % 1000)];
	if ((find != find->head) && (find->right != NULL))
	{
		while (tmp->right != find)
		{
			tmp = tmp->right;
		}
		tmp->right = find->right;
		find = NULL;
		getTotalStudents(2);

	}
	else if ((find->right == NULL) && (find != find->head))
	{
		//on the end, but not the head
		while (tmp->right != find)
		{
			tmp = tmp->right;
		}
		tmp->right = NULL;
		find = NULL;
		getTotalStudents(2);

	}
	else if (tmp == find)
	{
		if (tmp->right == NULL)
		{
			tmp->ALevel = "";
			tmp->head = NULL;
			tmp->right = NULL;
			tmp->gpa = 0.0;
			tmp->name = "";
			tmp->key = NULL;//head by itself;
		}
		else
		{
			tmp = tmp->right;
			find->head = tmp;
			if (tmp != NULL) {
				while (tmp->right != NULL)
				{
					find->gpa = tmp->gpa;
					find->name = tmp->name;
					find->key = tmp->key;
					find->right = tmp->right;
					find = find->right;
					tmp = tmp->right;
				}
			}
			tmp = NULL;
			find->right = NULL;
		}
		getTotalStudents(2);


	}
	else {
		cout << "something wrong";
	}

}

node* Search(node * hash[1000], int findKey)
{
	int index = findKey % 1000;
	node* tmp = hash[index];
	if (tmp->right == NULL && (tmp->key == findKey)) { return tmp; }
	else if(tmp->right != NULL)
	{
		while (tmp->right != NULL)
		{
			if (tmp->key == findKey)
			{
				return tmp;
			}
			else
			{
				tmp = tmp->right;
			}
		}

	}
	if (tmp->key == findKey)
	{
		return tmp;
	}
	else
	{
		cout << "Not found";
		return NULL;
	}
}
