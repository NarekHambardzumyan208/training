#include <iostream>
#include <vector>
template<typename T = int>
void swap(T& temp1,T& temp2)
{
	T temp = temp1;
	temp1 = temp2;
	temp2 = temp;
}
template<typename T = int>
void sort(std::vector<T>& arr)
{
    for(int i = 0;i < arr.size();i++)
    {
		for (int j = i + 1; j < arr.size() - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[j], arr[i]);
			}
		}
    }
}
template<typename T = int>
void display(std::vector<T>& arr)
{
	for(int i = 0; i < arr.size();i++)
	{
		std::cout << arr[i] << ",";
	}
}
int main()
{
std::vector<int> a = {4,6,7,3,9};
display(a);
sort(a);
std::cout << std::endl;
display(a);
}
