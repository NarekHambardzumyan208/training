#include <iostream>
#include <set>
void del_nums(std::set<int> temp, int num)
{
	for (std::set<int>::iterator iter = temp.begin(); iter != temp.end();)
	{
		std::cout << *iter << ",";
		if (*iter < num)
		{
			iter = temp.erase(iter);
		}
		else {
			iter++;
		}
	}
	std::cout << std::endl;
}
void display(std::set<int> temp)
{
	for (std::set<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
	{
		std::cout << *iter << ",";
 	}
	std::cout << std::endl;
}
int main() {
	std::set<int> a = {1,2,3,4,5,6,7,8,9,10};
	display(a);
	del_nums(a, 5);
	display(a);
}