#include<iostream>
using namespace std;

class INT
{
private:
	int m_data;

public:
	INT(int value = 0):m_data(value){ }

	INT operator+(const INT& other)
	{	
		return INT(this->m_data + other.m_data) ;
	}

	INT operator+(int data)
	{
		return INT(this->m_data + data);
	}

	friend INT operator+(int data, INT& other);
	/*{
		return INT(data + other.m_data);
	}*/



	int getValue() { return m_data; }
};

INT operator+(int data, INT& other)
{
	return INT(data + other.m_data);
}



int main()
{

	INT a(10);
	INT b(20);

	INT c = a + b;
	INT d = a + 30;
	INT e = 30 + d;

	cout << "c = " << c.getValue() << endl;
	cout << "d = " << d.getValue() << endl;
	cout << "e = " << e.getValue() << endl;
	return 0;
}