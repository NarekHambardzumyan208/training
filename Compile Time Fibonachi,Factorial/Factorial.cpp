#include <iostream>
using namespace std;
template<int A = 1>
class Factorial
{
public:
	static const int value = A * Factorial<A - 1>::value;
	
};
template<>
class Factorial<0> {
public:
	static const int value = 1;
};
int main()
{
        int a = Factorial<5>::value;
	cout << a;
}
