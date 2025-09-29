//Fibonacci serie using recursion.
//for every value of the series, we are running the recursive function
//Time complexity - 2^n


#include<iostream>
using namespace std;

int fib(int n)
{
	//Base cases
	if (n <= 1)
		return n;

	//return after final computation.
	//Method is called recursively till the base cases are hit
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	cout << "Enter the number" << endl;
	int n;
	cin >> n;

	cout << "Fibonacci series = " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << fib(i) << " ";
	}

	return 0;
}