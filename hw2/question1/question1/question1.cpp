#include <iostream>
#include <random>
#include<time.h>
#include <cstdlib>


void insertionSort(double arr[], int n);
void printArray(double arr[], int n);
double* makeRandArray(int size);

using namespace std;





/* Driver program to test insertion sort */
int main()
{
	double* ptr = makeRandArray(50);
	for (int i = 0; i < 50; i++)
	{
		cout << ptr[i] << endl;
	}

	int n = 50;

	insertionSort(ptr, n);
	printArray(ptr, n);

	return 0;
}
void insertionSort(double arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(double arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	system("pause");
}

double* makeRandArray (int size)
{
	double* randArray = new double[size];
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		randArray[i] = rand() / 10.00;
	}
	return randArray;

}