/*
Functor
In C++, a functor, also known as a function object, is an object of a class or struct that can be called and 
executed like a regular function. This is achieved by overloading the function call operator operator().

*/

#include<iostream>
using namespace std;

class MultBy
{
private:
	int mem;
public:
	MultBy(int m):mem(m){ }
	int operator()(int n) { return mem *n; }
};
int main()
{
	MultBy MultBy4(4);
	MultBy multBy3(3);

	cout << "Result for 3* 5 " << multBy3(5) << endl;
	cout << "Result for 4* 5 " << MultBy4(5) << endl;

	return 0;
}