#include <iostream>
#include <list>
void del_numbers(std::list<int>& a, int num)
{
	for (std::list<int>::iterator iter = a.begin(); iter != a.end();)
	{
		std::cout << *iter << ",";
		if (*iter < num)
		{
			iter = a.erase(iter);
		}
		else {
			iter++;
		}
	}
	std::cout << std::endl;
}
void display(std::list<int> a)
{
	for (std::list<int>::iterator iter = a.begin(); iter != a.end(); iter++)
	{
		std::cout << *iter  << ",";
	}
	std::cout << std::endl;
}
int main()
{
	std::list<int> a = {1,5,86,8,67,65,7,46,5,47,4,8,5};
	display(a);
	
	del_numbers(a,8);
	display(a);
}