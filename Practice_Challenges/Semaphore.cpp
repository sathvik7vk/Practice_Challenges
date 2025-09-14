#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

class Semaphore
{
private:
	int count;
	mutex mtx;
	condition_variable cv;

public:
	Semaphore(unsigned int cntr)
	{
		count = cntr;
	}

	void acquire()
	{
		std::unique_lock<mutex> lock(mtx);
		while (count == 0)
		{
			cv.wait(lock);
		}
		count--;
	}

	void release()
	{
		std::unique_lock<mutex> lock(mtx);
		count++;
		lock.unlock();
		cv.notify_one();
	}
};

//Semaphore charger(4);

void cellPhone(int id, Semaphore& charger)
{
	charger.acquire();
	printf("Phone %d acquired charging\n", id);
	//srand(id);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	printf("Phone %d charged completely\n",id);
	charger.release();

}
int main()
{
	Semaphore charger(4);

	std::thread phones[10];

	for (int i = 0; i < 10; i++)
	{
		phones[i] = std::thread(cellPhone, i, std::ref(charger));
	}


	for (auto& sem : phones)
	{
		sem.join();
	}

	return 0;
}
