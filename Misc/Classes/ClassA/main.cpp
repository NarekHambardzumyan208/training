#include <iostream>
using namespace std;
struct A {
	A() 
	{ 
		std::cout << "call A Constructor\n";
	
	}
	~A()  try{
		std::string err = "Special error for tests";
		std::cout << "call A Destructor\n";
		throw err;
    }
	catch (const std::string& err) {
		std::cout << err << std::endl;
	}
};
int main()
{
	try
	{
		std::cout << "creating A object\n";
			A obj;
	}
	catch (const std::string& err)
	{
		std::cout << err << std::endl;
		std::cout << "catched the true error\n";
	}
	catch (...)
	{
		std::cout << "Catching other errors\n";
	}
}