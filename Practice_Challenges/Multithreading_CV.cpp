#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

int soup_servings = 10;
std::mutex cooker_lid;
std::condition_variable cv;

void hungry_person(int id)
{
	int put_lid_back = 0;

	while (soup_servings > 0)
	{
		std::unique_lock<mutex> lock(cooker_lid);
		
		while ((id == soup_servings % 5) && (soup_servings > 0))
		{
			put_lid_back++;
			cv.wait(lock);
		}

		if (soup_servings > 0)
		{
			soup_servings--;
			lock.unlock();
			cv.notify_all();
		}

		/*else
		{
			put_lid_back++;
		}*/
	}
	printf("Person %d put the lid back %d times\n", id, put_lid_back);
}

int main()
{
	std::thread hungry_threads[5];

	for (int i = 0; i < 5; ++i)
	{
		hungry_threads[i] = std::thread(hungry_person, i);
	}

	for (auto& ht : hungry_threads)
	{
		ht.join();
	}

	return 0;
}