#include <iostream>
using namespace std;
template<int A = 3>
class Fibonnaci
{
public:
	static const int value = Fibonnaci<A - 2>::value + Fibonnaci<A - 1>::value;
};
template<>
class Fibonnaci<0>
{
public:
	static const int value = 0;
};
template<>
class Fibonnaci<1> {
public:
	static const int value = 1;
};
int main()
{
        int a = Fibonnaci<5>::value;
	cout << a;
}

