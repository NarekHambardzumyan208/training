#include <iostream>
#include <memory>
#include <functional>
template <typename T>
struct default_deleter {
	void operator()(T* ptr) {
		delete ptr;
	}
};
template<typename T>
struct default_deleter<T[]>
{
	void operator()(T* ptr) {
		delete[] ptr;
	}
};
template<typename T,class Deleter = default_deleter<T>>
class unique_ptr {
public:
	using pointer = T*;
	explicit unique_ptr(pointer ptr = nullptr) : ptr(ptr)  {};
	unique_ptr(unique_ptr<T>&& rvalue) 
	{
		ptr = rvalue.ptr;
		rvalue.ptr = nullptr;
	};
	unique_ptr operator=(unique_ptr<T>&& rvalue) { if (this != &rvalue) { reset(); ptr = rvalue.ptr; rvalue.ptr = nullptr; } return *this; };
	unique_ptr(const unique_ptr<T>&) = delete;
	unique_ptr& operator=(const unique_ptr<T>&) = delete;
	~unique_ptr() { Deleter(ptr); }
	pointer realase(){
		return std::exchange(ptr, nullptr);
	}
	void reset() {
	   Deleter(ptr);
	}
	void reset(pointer ptr){
		Deleter(ptr);
		this->ptr = ptr;
	}
	void swap(unique_ptr& obj)
	{
		pointer temp = obj.ptr;
		obj.ptr = ptr;
		ptr = temp;
	}
	pointer get()
	{
		return ptr;
	}
	Deleter& get_deleter() {
		return Deleter;
	}
	operator bool() {
		if (ptr == nullptr)
		{
			return false;
		}
		return true;
	}
	pointer operator*() { return ptr; };
	pointer operator->() { return ptr; };
private:
	pointer ptr;
};
template<typename T, class Deleter>
class unique_ptr<T[],Deleter> {
public:
	using pointer = T*;
	explicit unique_ptr(pointer ptr = nullptr) : ptr(ptr) {};
	unique_ptr(unique_ptr<T>&& rvalue)
	{
		ptr = rvalue.ptr;
		rvalue.ptr = nullptr;
	};
	unique_ptr operator=(unique_ptr<T>&& rvalue) { if (this != &rvalue) { reset(); ptr = rvalue.ptr; rvalue.ptr = nullptr; } return *this; };
	unique_ptr(const unique_ptr<T>&) = delete;
	unique_ptr& operator=(const unique_ptr<T>&) = delete;
	pointer release() {
		return std::exchange(ptr, nullptr);
	}
	template<typename T[], class Deleter = default_deleter<T[]>>
	void reset() {
		Deleter(ptr);
	}
	~unique_ptr() { Deleter(ptr); }
	template<typename T[], class Deleter = default_deleter<T[]>>
	void reset(pointer ptr) {
		Deleter(ptr);
		this->ptr = ptr;
	}
	void swap(unique_ptr& obj)
	{
		pointer temp = obj.ptr;
		obj.ptr = ptr;
		ptr = temp;
	}
	pointer get()
	{
		return ptr;
	}
	template<typename T[], class Deleter = default_deleter<T[]>>
	Deleter& get_deleter() {
		return Deleter;
	}
	operator bool() {
		if (ptr == nullptr)
		{
			return false;
		}
		return true;
	}
	pointer operator*() { return ptr; };
	pointer operator->() { return ptr; };
	T& operator[](size_t index) { return ptr[index]; }
private:
	pointer ptr;
};
template<typename T,typename... Args>
unique_ptr<T> make_unique(Args&&... args)
{
	return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T, typename... Args>
unique_ptr<T[]> make_unique_array(size_t size, Args&&... args) {
	return unique_ptr<T[]>(new T[size]{ std::forward<Args>(args)... });
}

int main()
{
	unique_ptr<int[]> a = make_unique_array<int>(10,5);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	std::cout << a[3];
}