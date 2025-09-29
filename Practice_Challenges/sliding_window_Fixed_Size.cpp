#include<iostream>
#include<vector>
using namespace std;

int GetMaxSumSubArrayOfSizeK(std::vector<int>& vec, int k)
{
	int n = vec.size();

	int max_sum = 0; int window_sum = 0;

	for (int i = 0; i < k; ++i)
	{
		window_sum += vec[i];
	}
	max_sum = window_sum;

	for (int i = k; i < n; ++i)
	{
		window_sum = (window_sum + vec[i]) - vec[i - k];
		max_sum = max(max_sum, window_sum);
	}

	return max_sum;
} 

int main()
{
	std::vector<int> vec = { 2,7,1,3,9,4 };
	cout << "Max sum = " << GetMaxSumSubArrayOfSizeK(vec, 3) << endl;
	return 0;
}