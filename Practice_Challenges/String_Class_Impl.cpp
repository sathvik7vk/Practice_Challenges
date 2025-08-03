#include<iostream>
//#include<cstring>

using namespace std;

class String
{
private:
	char* m_str;
	size_t m_length;

public:
	//Default Constructor
	String():m_str(nullptr), m_length(0){ }

	//Parameterized Constructor
	String(const char* str)
	{
		m_length = strlen(str) + 1;
		m_str = new char[m_length];
		strcpy_s(m_str, m_length, str);
	}

	//Destructor
	~String()
	{
		delete[] m_str;
		m_length = 0;
	}


	//Copy constrctor
	String(const String& other)
	{
		m_length = other.m_length;
		m_str = new char[m_length];
		strcpy_s(m_str, m_length, other.m_str);
	}

	//Copy assignment operator
	String& operator=(const String& other)
	{
		if (this != &other)
		{
			delete[] m_str;
			m_str = nullptr;

			m_length = other.m_length;
			m_str = new char[m_length];
			strcpy_s(m_str, m_length, other.m_str);

		}
		return *this;
	}

	//Move constructor
	String(String&& other)
	{
		m_length = other.m_length;
		m_str = other.m_str;
		
		other.m_length = 0;
		other.m_str = nullptr;
	}

	//Move assignment operator
	String& operator=(String&& other)
	{
		if (this != &other)
		{
			delete[] m_str;
			m_str = other.m_str;
			m_length = other.m_length;

			other.m_str = nullptr;
			other.m_length = 0;
		}
		return *this;
	}

	//Concatenation
	//String operator+(const String& other) const
	//{
	//	char* newData = new char[strlen(this->m_str) + strlen(other.m_str) + 1];

	//	strcpy_s(newData, this->m_length, this->m_str);
	//	strcat_s(newData, other.m_length-1, other.m_str);
	//	String result(newData);
	//	//delete[] newData;

	//	return result;
	//}

	String operator+(const String& other) const {
		size_t newLength = strlen(m_str) + strlen(other.m_str) + 1;
		char* newData = new char[newLength];
		strcpy_s(newData, newLength, m_str);
		strcat_s(newData, newLength, other.m_str);

		String result(newData);
		delete[] newData; // Safe: result copies the data in its constructor
		return result;
	}

	//Comparison
	bool operator==(const String& other) const
	{
		return strcmp(m_str, other.m_str) == 0;
	}

	bool operator!=(const String& other) const 
	{
		return strcmp(m_str, other.m_str) != 0;
	}

	//Print
	friend ostream& operator<<(ostream& out, const String& other);
	
};

ostream& operator<<(ostream& out, const String& other)
{
	out << other.m_str;
	return out;
}

int main()
{
	String s1("Hello");
	String s2("World");
	String s3 = s1 + " " + s2;

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;

	if (s1 == String("Hello"))
		cout << "s1 equals 'Hello'" << endl;


	return 0;
}