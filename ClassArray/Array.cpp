#include <iostream>
#include <vector>
using namespace std;
class Array
{
private:
    int* m_ptr;
    int m_size;
public:
    Array() {
        std::cout << "Input the m_size of array\n";
        getsize();
        m_ptr = new int[m_size];
        std::cout << "The array was created\n";
    }
    void getsize() 
    {
        while (m_size <= 0)
        {
            cout << "Input the size of matrix\n";
            cin >> m_size;
        }
    }
    Array(Array&& obj) : m_size(obj.m_size), m_ptr(obj.m_ptr) {
        obj.m_size = 0;
        obj.m_ptr = nullptr;
    }
    Array& operator=(Array&& obj) {
        if (this != &obj)
        {
            delete[] m_ptr;
            m_ptr = obj.m_ptr;
            m_size = obj.m_size;
            obj.m_ptr = nullptr;
            obj.m_size = 0;
        }
        return *this;
    }
    Array(const Array& other)
    {
        delete[] m_ptr;
        m_ptr = nullptr;
        m_ptr = new int[other.m_size];
        m_size = other.m_size;
        for (int i = 0; i < other.m_size; i++)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }
    Array& operator=(const Array& other)
    {
        if (this != &other) {
            delete[] m_ptr;
            m_ptr = nullptr;
            m_ptr = new int[other.m_size];
            m_size = other.m_size;
            for (int i = 0; i < other.m_size; i++)
            {
                m_ptr[i] = other.m_ptr[i];
            }
        }
        return *this;
    }
    void gen_elements()
    {
        for (int i = 0; i < m_size; i++)
        {
            m_ptr[i] = rand();
        }
    }
    void display()
    {
        for (int i = 0; i < m_size; i++)
        {
            std::cout << m_ptr[i] << ",";
        }
        std::cout << std::endl;
    }
    int at(int num) {
        if (num < m_size)
        {
            return m_ptr[num];
        }
        return m_ptr[m_size];
    }
    ~Array()
    {
        std::cout << "The destructor was called\n";
        delete[] m_ptr;
        m_ptr = nullptr;
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
    std::cout << std::endl;
}