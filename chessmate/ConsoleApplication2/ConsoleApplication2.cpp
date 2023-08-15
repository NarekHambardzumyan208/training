#include <iostream>
#include <unordered_set>
#include <C:\Users\User\source\repos\container\.vector\vector.cpp>
template<typename type>
void move_elems(vector<type> a, std::unordered_set<type>& b)
{
	b.clear();
	for (int i = 0; i < a.size(); i++)
	{
		b.insert(a[i]);
	}
}
void display(std::unordered_set<int> b)
{
	for (auto it : b)
	{
		std::cout << it;
	}
}
int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(5);
	a.push_back(7);
	a.push_back(8);
	a.push_back(4);
	std::unordered_set<int> b;
	move_elems(a, b);
	display(b);
}