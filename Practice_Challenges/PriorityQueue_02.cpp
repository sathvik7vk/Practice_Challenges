#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	std::priority_queue<int, vector<int>, greater<int>> q1;
	/*
	template<
    class T,                        // The data type (e.g., int)
    class Container = vector<T>,   // The underlying container (default = vector)
    class Compare = less<T>        // The comparator (default = max-heap)
	> class priority_queue;

	int: type of elements
	vector<int>: container to use internally (by default it’s vector)
	greater<int>: comparator to make it a min-heap


	priority_queue<int>	max-heap (default: uses vector<int>, less<int>)
	priority_queue<int, vector<int>>	still max-heap (explicit container, default comparator)
	priority_queue<int, vector<int>, greater<int>>	min-heap (you change the comparator, so must specify container)
*/

	q1.push(10);
	q1.push(25);
	q1.push(13);
	q1.push(8);

	while (!q1.empty())
	{
		auto& elem = q1.top();
		cout << elem << endl;
		q1.pop();

	}
}