#include <iostream>
template<int N>
size_t f(const int(&arr)[N])
{
	return sizeof(int) * N;
}
int main()
{
	int arr[5]{ 5,6,8,9,4 };
	std::cout << sizeof(arr) << std::endl;
	std::cout << f(arr) << std::endl;

}