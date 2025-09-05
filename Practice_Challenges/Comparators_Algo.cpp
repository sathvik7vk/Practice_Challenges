#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Comparator
{
private:
	bool m_decreasing;
public:
	Comparator(bool decreasing = false) :m_decreasing(decreasing) {}
	bool operator()(const int& a, const int& b) {
		if (m_decreasing)
		{
			return a > b;
		}
		else
		{
			return a < b;
		}
	}
};

auto Comparator_lambda = [](const int& a, const int& b) { return a > b; };

int main()
{
	std::vector<int> vec = { 55,47,65,12,89 };

	//Using algorithm library
	//std::sort(vec.begin(), vec.end(), greater<int>());

	//Using custom comparator class 
	//bool decreasing = true;
	//std::sort(vec.begin(), vec.end(), Comparator(decreasing));

	//Using lambda function for custom comparator
	std::sort(vec.begin(), vec.end(), Comparator_lambda);

	for (auto elem : vec)
		cout << elem << " ";

	return 0;
}