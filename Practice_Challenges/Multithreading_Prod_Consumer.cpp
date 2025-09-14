#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

using namespace std;


class ServingLine
{
private:
	std::queue<int> soup_queue;
	mutex mtx;
	condition_variable cv;

public:
	void PrepareSoup(int i)
	{
		std::unique_lock<mutex> lock(mtx);
		soup_queue.push(i);
		printf("Producer produced %d item\n", i);
		lock.unlock();
		cv.notify_all();
	}

	//Below version is more cleaner
	//void PrepareSoup(int i) {
	//	{
	//		std::unique_lock<mutex> lock(mtx);
	//		soup_queue.push(i);
	//		printf("Producer produced %d item\n", i);
	//	} // lock released here
	//	cv.notify_one();
	//}


	int ConsumeSoup()
	{
		/*
		Acquires the mutex lock mtx using RAII (unique_lock).
		This ensures only one thread at a time can check or modify soup_queue.
		If another thread is already holding the lock, this thread will block until it becomes available.*/


		std::unique_lock<mutex> lock(mtx);

		/*
		If the queue is empty, the consumer can’t eat yet.
		So it waits on the condition variable cv.

		cv.wait(lock) does two things atomically:
			1.Releases the mutex (lock.unlock() internally).
			2.Puts the thread to sleep until cv.notify_one() or cv.notify_all() is called by the producer.

		When the consumer wakes up:
			It re-acquires the mutex (lock.lock() again).
			Then it re-checks the condition (while (soup_queue.empty())) to avoid spurious wake-ups.
	
		That’s why while is used, not if.
		*/
		while (soup_queue.empty())
		{
			cv.wait(lock);
		}
		int bowlNum = soup_queue.front();
		soup_queue.pop();

		/*
		*/
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		printf("Consumer consumed %d item\n", bowlNum);
		return bowlNum;
	}
};

//ServingLine servingLine/* = ServingLine()*/;

void SoupProducer(ServingLine& servingLine)
{
	for (int i = 0; i < 100; i++)
	{
		servingLine.PrepareSoup(i);
	}
	servingLine.PrepareSoup(-1);
	servingLine.PrepareSoup(-1);
	printf("Producer is done preparing soup\n");
}

void SoupConsumer(string name, ServingLine& servingLine)
{
	int soup_eaten = 0;
	while (true)
	{
		int bowl = servingLine.ConsumeSoup();
		if (bowl == -1)
		{
			//printf("Consumer eat %d bowls of soup\n", soup_eaten);
			break;
		}
		else
		{
			soup_eaten++;
		}
	}
	printf("%s ate %d bowls of soup\n", name.c_str(), soup_eaten);
}

int main()
{

	ServingLine servingLine;

	std::thread Sathvik(SoupProducer, std::ref(servingLine));
	std::thread Vijetha(SoupConsumer, "Vijetha", std::ref(servingLine));
	std::thread Samathva(SoupConsumer, "Samathva", std::ref(servingLine));

	Sathvik.join();
	Vijetha.join();
	Samathva.join();

	return 0;
}