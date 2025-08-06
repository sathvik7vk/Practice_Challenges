#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Job
{
public:
	int id;
	int priority;
	string name;

	Job(int mid, int mp, string n): id(mid), priority(mp), name(n){ }
};

class JobComparator
{
public: 
	bool operator()(const Job& j1, const Job& j2)
	{
		if (j1.priority == j2.priority)
		{
			return j1.id > j2.id;
		}
		return j1.priority > j2.priority;
	}
};


int main()
{
	priority_queue<Job, vector<Job>, JobComparator> jobList;
	jobList.push(Job(1, 5, "job1"));
	jobList.push(Job(2, 9, "job2"));
	jobList.push(Job(3, 7, "job3"));
	jobList.push(Job(4, 2, "job4"));
	jobList.push(Job(5, 4, "job5"));

	while (!jobList.empty())
	{
		Job job = jobList.top();
		cout << "ID = " << job.id << "   Name = " << job.name <<"  Priority = "<<job.priority<< endl;
		jobList.pop();
	}

	return 0;
}