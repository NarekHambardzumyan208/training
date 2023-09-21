#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include<vector>
size_t size = 5; 
size_t products = 1000;
std::vector<int> produc;
std::condition_variable not_full;
std::condition_variable not_empty;
std::mutex mtx;
void producter()
{
	for (int i = 0; i < products; i++)
	{
		std::unique_lock<std::mutex> lock(mtx);
		not_full.wait(lock, []() {return produc.size() < size; });
		produc.push_back(i);
		not_empty.notify_all();
		lock.unlock();
	}
}
void consumer()
{
	for (int i = 0; i < products; i++)
	{
		std::unique_lock<std::mutex> lock(mtx);
		not_empty.wait(lock, []() {return !produc.empty(); });
		produc.pop_back();
		not_full.notify_all();
		lock.unlock();
	}
}
int main()
{
	auto start_time = std::chrono::high_resolution_clock::now();
	std::thread producer_thread(producter);
	std::thread consumer_thread(consumer);
	producer_thread.join();
	consumer_thread.join();
	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	std::cout << "Runtime duration: " << duration.count() << " microseconds" << std::endl;

}

