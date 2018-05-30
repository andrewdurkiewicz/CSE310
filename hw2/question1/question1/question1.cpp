#include <iostream>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <time.h>
#include <fstream>


using namespace std;

void insertionSort(double A[], int size);
void printArray(double A[], int size);
void swap(double A[], int indexOne, int indexTwo);
void quickSort(double A[], int p, int r);
void mergeSort(double A[], int p, int r);
void merge(double arr[], int l, int m, int r);
int partition(double A[], int p, int r);
double* makeRandArray(int size, double min, double max);
double getRand(double min, double max);
void getTime(int sizeValue[], float timevalues[7][3][5], int index, int trial);


int main()
{
	int sizeValue[7] = {1000, 10000, 25000, 50000, 100000, 150000, 200000};
	float timeValues[7][3][5];
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			getTime(sizeValue, timeValues, i, j);

		}
	}
	ofstream myfile;
	myfile.open("TimeResults.csv");
	myfile << "N,Merge,Insertion,QuickSort\n";
	for (int i = 0; i < 7; i++)
	{
		myfile << sizeValue[i] << ",";
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				myfile << timeValues[i][j][k] << ",";

			}

		}
		myfile << "\n";
	}
	myfile.close();
	return 0;
}


void getTime(int sizeValue[], float timevalues[7][3][5], int index, int trial)
{
	double min = 100.00;
	double max = 1000.00;
	for (int i = 0; i < 7; i++)
	{
		double* ptr = makeRandArray(sizeValue[i], min, max);
		switch (index) {
		case 0:
		{
			clock_t begin = clock();
			mergeSort(ptr, 0, sizeValue[i] - 1);
			clock_t end = clock() - begin;
			timevalues[i][0][trial] = ((float)end) / CLOCKS_PER_SEC;
			delete ptr;
			break;
		}
		case 1:
		{
			clock_t begin = clock();
			insertionSort(ptr, sizeValue[i]);
			clock_t end = clock() - begin;
			timevalues[i][1][trial] = ((float)end) / CLOCKS_PER_SEC;
			delete ptr;

			break;
		}
		case 2:
		{
			clock_t begin = clock();
			quickSort(ptr, 0, sizeValue[i] - 1);
			clock_t end = clock() - begin;
			timevalues[i][2][trial] = ((float)end) / CLOCKS_PER_SEC;
			delete ptr;

			break;
		}
		}
	}

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

void insertionSort(double A[], int A_Length) 
{
	int i, j;
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

void mergeSort(double A[], int p, int r)
{
	if (p < r)
	{
		int q = p + (r - p) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

void merge(double arr[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	double* Left = new double[n1];
	double* Right = new double[n2];

	for (i = 0; i < n1; i++)
	{
		Left[i] = arr[p + i];
	}

	for (j = 0; j < n2; j++)
	{
		Right[j] = arr[q + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = p; 
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
	delete Left;
	delete Right;
}
void swap(double A[], int indexOne, int indexTwo)
{
	double temp = A[indexOne];
	A[indexOne] = A[indexTwo];
	A[indexTwo] = temp;
}

void printArray(double arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << i << ": " << arr[i] << endl;
	system("pause");
}