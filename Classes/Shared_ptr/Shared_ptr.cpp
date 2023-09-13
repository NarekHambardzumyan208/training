#include <iostream>
#include <algorithm>
template<typename T>
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
template<typename T, class Deleter = default_deleter<T>>
class shared_ptr {
public:
	using pointer = T*;
	explicit shared_ptr(pointer ptr = nullptr) : ptr(ptr) {
		if (ptr != nullptr)
		{
			Control_Block = new ControlBlock;
			Control_Block->set_data(1);
	    }
	};
	shared_ptr(shared_ptr<T>&& rvalue) noexcept
	{
		Control_Block = rvalue.Control_Block;
		ptr = rvalue.ptr;
		rvalue.ptr = nullptr;
		rvalue.Control_Block = nullptr;
	};
	shared_ptr operator=(shared_ptr<T>&& rvalue) { 
		if (this != &rvalue) 
		{
if (ptr != nullptr)
{
if(Control_Block->decrement_count == 0)
{
		delete Control_Block;
		delete ptr;
}
}
		Control_Block = rvalue.Control_Block;
		ptr = rvalue.ptr;
		rvalue.ptr = nullptr;
		rvalue.Control_Block = nullptr;
	    }
	    return *this; 
    };
	shared_ptr(const shared_ptr<T>& ptr)
	{
		Control_Block = ptr.Control_Block;
		Control_Block->increment_data();
		this->ptr = ptr.ptr;
	};
	shared_ptr& operator=(const shared_ptr<T>& obj)
	{
		if (this != &obj)
		{
			delete Control_Block;
			delete ptr;
			Control_Block = ptr.Control_Block;
			Control_Block->increment_data();
			this->ptr = ptr.ptr;
		}
	}
	~shared_ptr() { 
		if (0 == Control_Block->decrement_data())
		{
			delete Control_Block;
			Deleter(ptr);
		}
     }
	pointer realase() {
		if (Control_Block->decrement_data() == 0) {
			delete Control_Block;
		}
		return std::exchange(ptr, nullptr);
	}
	void reset() {
		delete Control_Block;
		Deleter(ptr);
	}
	void reset(pointer ptr) {
		Control_Block->set_data(1);
		Deleter(ptr);
		this->ptr = ptr;
	}
	void swap(shared_ptr& obj)
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
	class ControlBlock {
		int data = 0;
	public:
		int get_data(){
			return data;
		}
		void set_data(int a)
		{
			data = a;
		}
		int decrement_data()
		{
			data--;
			return data;
		}
		void increment_data()
		{
			data++;
		}
	};
	ControlBlock* Control_Block;
};
template<typename T, class Deleter>
class shared_ptr<T[], Deleter> {
	public:
		using pointer = T*;
		explicit shared_ptr(pointer ptr = nullptr) : ptr(ptr) {
			if (ptr != nullptr)
			{
				Control_Block = new ControlBlock;
				Control_Block->set_data(1);
			}
		};
		shared_ptr(shared_ptr<T>&& rvalue)
		{
			Control_Block = rvalue.Control_Block;
				ptr = rvalue.ptr;
			rvalue.ptr = nullptr;
			rvalue.Control_Block = nullptr;
		};
		shared_ptr operator=(shared_ptr<T>&& rvalue) {
			if (this != &rvalue)
			{
				delete Control_Block;
				delete ptr;
				Control_Block = rvalue.Control_Block;
					ptr = rvalue.ptr;
				rvalue.ptr = nullptr;
				rvalue.Control_Block = nullptr;
			}
			return *this;
		};
		shared_ptr(const shared_ptr<T>& ptr)
		{
			Control_Block = ptr.Control_Block;
			Control_Block->increment_data();
			this->ptr = ptr.ptr;
		};
		shared_ptr& operator=(const shared_ptr<T>& obj)
		{
			if (this != &obj)
			{
				delete Control_Block;
				delete ptr;
				Control_Block = ptr.Control_Block;
				Control_Block->increment_data();
				this->ptr = ptr.ptr;
			}
		}
		~shared_ptr() {
			if (0 == Control_Block->decrement_data())
			{
				delete Control_Block;
				Deleter(ptr);
			}
		}
		pointer realase() {
			if (Control_Block->decrement_data() == 0) {
				delete Control_Block;
			}
			return std::exchange(ptr, nullptr);
		}
		void reset() {
			delete Control_Block;
			Deleter(ptr);
		}
		void reset(pointer ptr) {
			Control_Block->set_data(1);
			Deleter(ptr);
			this->ptr = ptr;
		}
		void swap(shared_ptr& obj)
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
		pointer operator*() { return ptr; }
		T& operator[](int index){ return ptr[index]; }
		pointer operator->() { return ptr; }
	private:
		pointer ptr;
		class ControlBlock {
			int data = 0;
		public:
			int get_data() {
				return data;
			}
			void set_data(int a)
			{
				data = a;
			}
			int decrement_data()
			{
				data--;
				return data;
			}
			void increment_data()
			{
				data++;
			}
		};
		ControlBlock* Control_Block;
	};
template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args)
{
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T, typename... Args>
shared_ptr<T[]> make_shared_array(size_t size, Args&&... args) {
	return shared_ptr<T[]>(new T[size]{ std::forward<Args>(args)... });
}
int main(){
	shared_ptr<int[]> a = make_shared_array<int>(4, 1);
	for(int i = 0 ; i < 4; i++)
	{
		a[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << a[i] <<std::endl;
	}

}
