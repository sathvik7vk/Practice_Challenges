#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void SortInDecreasing(vector<int>& other)
{
	std::sort(other.begin(), other.end(), [](int x, int y) { return x > y; });
}

void Print(vector<int>& other)
{
	for (auto elem : other)
	{
		cout << elem << " ";
	}
	cout << endl;
}
int main()
{
	vector<int> vec = { 9, 5, 7, 3, 8, 2, 4 };
	cout << "Before sorting" << endl;
	Print(vec);
	SortInDecreasing(vec);

	cout << "After sorting" << endl;
	Print(vec);
	return 0;

}