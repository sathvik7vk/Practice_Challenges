//Program to check palindrome of a string

//Solution by Sathvik
#include<iostream>
using namespace std;

bool IsInputPalindrome(const std::string& str)
{
	int size = str.size();
	for (int i = 0; i < size / 2; ++i)
	{
		if (str[i] != str[size - 1 - i])
		{
			//break;
			return false;
		}
	}
	return true;
}
int main()
{
	cout << "Enter the string" << endl;
	std::string str;
	cin >> str;

	bool isPalindrome = IsInputPalindrome(str);
	if (isPalindrome)
		cout << "The string \"" << str << "\" is a palindrome." << endl;
	else
		cout << "The string \"" << str << "\" is not a palindrome." << endl;

	return 0;
}

