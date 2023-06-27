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
    int& operator[](int index) {
        if (index > size) {
            std::cerr << "The index cant be a bigger than size\n";
            throw abort;
        }
        return ptr[index];
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
    std::cout << first[3]<< std::endl;
   std::cout << first.at(2) << std::endl;
   std::cout<<std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
