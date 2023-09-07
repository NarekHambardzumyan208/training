// auto_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
template<typename T>
class auto_ptr {
    T* m_ptr;
    static size_t Control_Block;
public:
    T operator*() {
        return *m_ptr;
    }
    T* operator->()
    {
        return m_ptr;
    }
    T operator[](int i){
        return m_ptr[i];
    }
    auto_ptr(const auto_ptr& A) : m_ptr(A.m_ptr) 
    {
        Control_Block++;
    };
    auto_ptr(T* m_ptr) : m_ptr(m_ptr)
    {
        Control_Block++;
    };
    ~auto_ptr()
    { 
    --Control_Block;
    if (Control_Block == 0) 
     { 
        delete m_ptr; 
     } 
    }
};
template<typename T>
size_t auto_ptr<T>::Control_Block = 0;
int main()
{
    auto_ptr<int> ptr(new int[5]{1,5,3,4,6});
    auto_ptr<int> ptr2(ptr);
    std::cout << ptr[1] << std::endl;
    std::cout << ptr2[1] << std::endl;
}

