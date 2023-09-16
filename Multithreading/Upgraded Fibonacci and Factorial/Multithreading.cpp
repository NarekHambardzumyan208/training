#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
std::mutex mtx;

std::vector < int >
sequence
{
  1,
1 };

void
random(std::vector < int >& a)
{

	for (int i = 0; i < 21; i++)

	{

		a.push_back(rand() % 15 + 0);

	}
}
int

fibonacci(int n)
{

	mtx.lock();

	if (n < 2)

	{

		mtx.unlock();

		return 1;


	}

	if (n < sequence.size())

	{

		mtx.unlock();

		return sequence[n];

	}

	int
		result = fibonacci(n - 2) + fibonacci(n - 1);

	sequence.push_back(result);

	mtx.unlock();

	return result;

}


int main() {
	std::vector<int> r;
	random(r);

	std::thread t1([&]() {
		int res = fibonacci(r[0]);
	mtx.lock();
	std::cout << "t1:(" << r[0] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t2([&]() {
		int res = fibonacci(r[1]);
	mtx.lock();
	std::cout << "t2:(" << r[1] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t3([&]() {
		int res = fibonacci(r[2]);
	mtx.lock();
	std::cout << "t3:(" << r[2] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t4([&]() {
		int res = fibonacci(r[3]);
	mtx.lock();
	std::cout << "t4:(" << r[3] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t5([&]() {
		int res = fibonacci(r[4]);
	mtx.lock();
	std::cout << "t5:(" << r[4] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t6([&]() {
		int res = fibonacci(r[5]);
	mtx.lock();
	std::cout << "t6:(" << r[5] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t7([&]() {
		int res = fibonacci(r[6]);
	mtx.lock();
	std::cout << "t7:(" << r[6] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t8([&]() {
		int res = fibonacci(r[7]);
	mtx.lock();
	std::cout << "t8:(" << r[7] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t9([&]() {
		int res = fibonacci(r[8]);
	mtx.lock();
	std::cout << "t9:(" << r[8] << ")	 " << res << std::endl;
	mtx.unlock();
		});
	std::thread t10([&]() {
		int res = fibonacci(r[9]);
	mtx.lock();
	std::cout << "t10:(" << r[9] << ")	  " << res << std::endl;
	mtx.unlock();
		});
	std::thread t11([&]() {
		int res = fibonacci(r[10]);
	mtx.lock();
	std::cout << "t11:(" << r[10] << ")	   " << res << std::endl;
	mtx.unlock();
		});
	std::thread t12([&]() {
		int res = fibonacci(r[11]);
	mtx.lock();
	std::cout << "t12:(" << r[11] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t13([&]() {
		int res = fibonacci(r[12]);
	mtx.lock();
	std::cout << "t13:(" << r[12] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t14([&]() {
		int res = fibonacci(r[13]);
	mtx.lock();
	std::cout << "t14:(" << r[13] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t15([&]() {
		int res = fibonacci(r[14]);
	mtx.lock();
	std::cout << "t15:(" << r[14] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t16([&]() {
		int res = fibonacci(r[15]);
	mtx.lock();
	std::cout << "t16:(" << r[15] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t17([&]() {
		int res = fibonacci(r[16]);
	mtx.lock();
	std::cout << "t17:(" << r[16] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t18([&]() {
		int res = fibonacci(r[17]);
	mtx.lock();
	std::cout << "t18:(" << r[17] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t19([&]() {
		int res = fibonacci(r[18]);
	mtx.lock();
	std::cout << "t19:(" << r[18] << ")	    " << res << std::endl;
	mtx.unlock();
		});
	std::thread t20([&]() {
		int res = fibonacci(r[19]);
	mtx.lock();
	std::cout << "t20:(" << r[19] << ")	    " << res << std::endl;
	mtx.unlock();
		});


	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();
}