//Fibonacci series using memoizations works primarily using recursion.
// but we will have a array which stores the computed values
//Time complexity - O(n)

#include<iostream>
#include<vector>
using namespace std;

int fib(int n, std::vector<int>& dp)
{
	//Base cases
	if (n <= 1)
	{
		dp[n] = n;
		return dp[n];
	}

	//If the value is previously computed, return the value.
	if (dp[n] != -1) return dp[n];
	
	//Store the computed value in array 
	return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
	
	
}

int main()
{
	cout << "Enter the number" << endl;
	int n;
	cin >> n;

	std::vector<int> dp(n+1, -1);
	
	fib(n, dp);

	for (auto elem : dp)
		cout << elem << endl;

}