#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

void insertionSort(double A[], int size);
void printArray(double A[], int size);
void swap(double A[], int indexOne, int indexTwo);
void quickSort(double A[], int p, int r);
int partition(double A[], int p, int r);
double* makeRandArray(int size, double min, double max);
double getRand(double min, double max);


int main()
{
	int size = 50;
	double min = 100.00;
	double max = 1000.00;
	double* ptr = makeRandArray(size, min, max);
	//quickSort(ptr, 0, size - 1);
	//insertionSort(ptr, size);
	printArray(ptr, size);

	return 0;
}
void insertionSort(double A[], int A_Length)
{
	int i , j;
	double key;
	for (j = 1; j < A_Length; j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}

void printArray(double arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << i << ": " << arr[i] << endl;
	system("pause");
}

double* makeRandArray (int size, double min, double max)
{
	double* randArray = new double[size];
	srand((unsigned int)time(0));

	for (int i = 0; i < size; i++)
	{
		randArray[i] = getRand(min, max);
	}
	return randArray;

}

double getRand(double min, double max)
{
	double randF = (double)rand() / RAND_MAX;
	return min + randF * (max - min);
}

int partition(double A[], int p, int r)
{
	double pivot = A[r]; //get pivot
	int i = p;
	int j = r - 1;
	while (true)
	{
		while (j >= p)
		{
			if (A[j] < pivot)
			{
				break;
			}
			else 
			{
				j--;
			}

		}
		while (i < r)
		{
			if (A[i] >= pivot)
			{
				break;
			}
			else
			{
				i++;
			}
		}
		if (i < j)
		{
			swap(A, i, j);
		}
		else
		{
			swap(A, i, r);
			return i;
		}

	}

}

void quickSort(double A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void swap(double A[], int indexOne, int indexTwo)
{
	double temp = A[indexOne];
	A[indexOne] = A[indexTwo];
	A[indexTwo] = temp;
}