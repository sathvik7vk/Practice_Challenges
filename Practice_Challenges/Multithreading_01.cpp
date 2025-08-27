//#include<iostream>
//#include<thread>
//#include<atomic>
//
//using namespace std;
//
//atomic<bool> chopping = true;
//
//void cutVeggies(string name)
//{
//	unsigned int count = 0;
//	while (chopping)
//	{
//		count++;
//	}
//	//cout << name << " has cut " << count << " vegetables" << endl;
//	printf("%s chopped %u vegetables\n", name.c_str(), count);
//}
//
//int main()
//{
//	std::thread t1(cutVeggies, "Sathvik");
//	std::thread t2(cutVeggies, "Vijetha");
//
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	chopping = false;
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

#include<iostream>
#include<thread>
//#include<atomic>
#include<mutex>

using namespace std;

bool chopping = true;

mutex mtx;

void cutVeggies(string name)
{
	unsigned int count = 0;
	std::unique_lock<mutex> lock(mtx);
	while (chopping)
	{
		lock.unlock();
		count++;
		lock.lock();
	}
	//cout << name << " has cut " << count << " vegetables" << endl;
	printf("%s chopped %u vegetables\n", name.c_str(), count);
}

int main()
{
	std::thread t1(cutVeggies, "Sathvik");
	std::thread t2(cutVeggies, "Vijetha");

	std::this_thread::sleep_for(std::chrono::seconds(1));
	chopping = false;

	t1.join();
	t2.join();

	return 0;
}