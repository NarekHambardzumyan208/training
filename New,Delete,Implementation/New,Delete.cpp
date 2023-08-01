#include <iostream>
using namespace std;
void* operator new(size_t size)
{
    void* ptr = malloc(size);
        if (ptr = nullptr)
        {
            throw bad_alloc();
        }
}
void operator delete(void* ptr) noexcept
{
    free(ptr);
}
int main()
{
    int* ptr = new int(5);
    int size = 0;
    while (size < 5)
    {
        ptr[size] = rand();
        cout << ptr[size];
    }
    delete[] ptr;
}
