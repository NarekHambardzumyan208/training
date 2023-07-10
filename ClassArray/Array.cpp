#include <iostream>
#include <vector>
class Array {
private:
    int* ptr;
    int size;
public:
    Array() {
        std::cout << "Input the size of array\n";
        std::cin >> size;
        ptr = new int[size];
        std::cout << "The array was created\n";
    }
    Array(Array&& obj) : size(obj.size),ptr(obj.ptr) {
        obj.size = NULL;
        obj.ptr = NULL;
    }
    Array& operator=(Array&&obj){
        if (this != &obj)
        {
            delete[] ptr;
            ptr = obj.ptr;
            size = obj.size;
            obj.ptr = NULL;
            obj.size = NULL;
      }
        return *this;
    }
    Array(const Array& other)
    {
        delete[] ptr;
        ptr = nullptr;
        ptr = new int[other.size];
        size = other.size;
        for (int i = 0; i < other.size; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }
    Array& operator=(const Array& other)
    {
        if (this != &other){
           delete[] ptr;
           ptr = nullptr;
           ptr = new int[other.size];
           size = other.size;
           for (int i = 0; i < other.size; i++)
           {
            ptr[i] = other.ptr[i];
           }
        }
        return *this;
    }
    void gen_elements()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand();
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << ptr[i] << ",";
        }
        std::cout << std::endl;
    }
    int at(int num) {
        if (num < size)
        {
            return ptr[num];
        }
        return ptr[size];
    }
    ~Array()
    {
        std::cout << "The destructor was called\n";
        delete[] ptr;
        ptr = nullptr;
        std::cout << "The array was deleted\n";
    }
};
int main()
{
    Array first;
    first.gen_elements();
    first.display();
    Array second(std::move(Array()));
    Array third;
    third = std::move(Array());
   std::cout << first.at(5);
   std::cout<<std::endl;
}
