
#include <iostream>
#include <vector>
#include<algorithm>
void counting_sort(std::vector<int> &array)
{
    int max_val = *std::max_element(array.begin(), array.end()) + 1;
    std::vector<int> count(max_val,0);
    for_each(array.begin(), array.end(), [&](const int& N) { count[N]++; });
    int index = 0;
    for (int i = 0; i < max_val; i++)
    {
        while (count[i] > 0)
        {
            array[index++] = i;
            count[i]--;
        }
    }
}
int main()
{
    std::vector<int> array = { 513,831,498,776,643,121,634,965,106,627 };
    std::cout << "The vector before sorting:\n";
    for_each(array.begin(), array.end(), [](const int& N) { std::cout << N << ","; });
    std::cout << "\nThe vector after sorting:\n";
    counting_sort(array);
    for_each(array.begin(), array.end(), [](const int& N) { std::cout << N << ","; });
}

