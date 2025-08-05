#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	std::priority_queue<int> q1;

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