#include <iostream>
#include <vector>
bool is_ten_bit(int a)
{
    if (a >> 9)
    {
        return 1;
    }
    else {
        return 0;
    }
}
// kam
bool is_ten_bit_1(int a)
{
    bool binary = a & (1 >> 9);
    return binary;
}
int unique(const std::vector<int>& a)
{
    int result = 0;
    for  (int num : a)
    {
        result ^= num;
    }
    return result;
}
int main()
{
    int b = 11;
    std::cout << is_ten_bit(b) << std::endl;
    std::vector<int> a = { 5,8,7,5,3,3,4,4,24,7,8,7,8 };
    std::cout << unique(a);
}
