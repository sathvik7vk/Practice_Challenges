#include<iostream>
#include<new>
#include<print>
using namespace std;

class MyClass
{
	int value;

public:
	MyClass(int val) :value(val)
	{
		std::println("Constructor called");
	}

	~MyClass() { println("Destructor called"); }
};
int main()
{
	char* buffer = new char[sizeof(MyClass)];

	MyClass* obj = new(buffer) MyClass(100);

	obj->~MyClass();

	delete[] buffer;
}