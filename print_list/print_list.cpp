#include <iostream>
#include <algorithm>
#include <list>
int main() {
	std::list<int> temp = { 50,75,100,125,150,175,200,225,250 };
	std::for_each(temp.begin(), temp.end(), [](const int& N) {if (N < 200 && N > 100) std::cout << N << ","; });
}