#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
float b_nlogn(int n, double b);
float a_n2(int n, double a);
int main()
{
  double a, b, result1, result2;
  cout << "Enter your a value: " << flush;
  cin >> a;
  cout << "Enter your b value: " << flush;
  cin >> b;
  int n = 2;
  while(a_n2(n,a) <= b_nlogn(n,b))
  {
    cout << "Insertion sort = " << a_n2(n,a) << " Merge sort  = " << b_nlogn(n,b) << endl << flush;
    cout << "N = " << n << endl;
    n *= 2;
  }
  cout << "Insertion sort = " << a_n2(n,a) << " Merge sort  = " << b_nlogn(n,b) << endl << flush;
  cout << "N = " << n << endl;
  cout << "value of n that insertion sort beat merge sort is : " << n << endl;


  return 0;

}

float b_nlogn(int n, double b)
{
  return b*n*log2(n);
}

float a_n2(int n, double a)
{
  return a*n*n;
}
