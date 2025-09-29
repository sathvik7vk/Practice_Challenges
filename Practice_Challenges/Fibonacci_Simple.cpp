#include<iostream>
using namespace std;

int main()
{
	cout << "Enter the number" << endl;
	int n;
	cin >> n;

	int a = 0; int b = 1;
	for (int i = 0; i < n; ++i)
	{
		cout << a << " ";
		int next = a + b;
		a = b;
		b = next;
	}
}