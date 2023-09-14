#include <iostream>
#include <thread>
const int n = 10;
int factorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return factorial(n - 1) * n;
}
int fibonacci(int n)
{
	if (n == 1 && n == 0)
	{
		return n;
	}
	return fibonacci(n - 2) * fibonacci(n - 1);
}
int main()
{
	std::thread fib([]() {std::cout << "The Fibonacci of " << n << " is " << fibonacci(n); });
	std::thread fac([]() {std::cout << "The Factorial of " << n << " is " << factorial(n); });
	fib.join();
	fac.join();
}