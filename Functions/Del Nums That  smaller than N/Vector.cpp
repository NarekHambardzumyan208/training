#include <iostream>
#include <vector>
using namespace std;
void del_num(vector<int>& a, int num)
{
	for (vector<int>::iterator iter = a.begin() ; iter !=a.end();)
	{
		cout << *iter << ",";

		if (*iter < num)
		{
			iter = a.erase(iter);
		}
		else {
			iter++;
		}
	}
	cout << endl;
}
void display(vector<int> a)
{
	for (vector<int>::iterator iter = a.begin();iter != a.end();iter++)
	{
		cout << *iter << ",";
	}
	cout << endl;
}
int main()
{
	vector<int> a = {1,5,78,6,7,3,2};
	display(a);
	del_num(a, 6);
	display(a);
}
