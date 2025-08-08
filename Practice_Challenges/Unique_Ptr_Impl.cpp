#include<iostream>
using namespace std;

template<typename T>
class UniquePtr
{
private:
	T* ptr;
public:
	UniquePtr(T* p = nullptr) :ptr(p) { cout << "constructor for ptr called" << endl; }
	~UniquePtr() { delete ptr; cout << "Destructor called" << endl; }

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	UniquePtr(UniquePtr&& other) noexcept
	{
		ptr = other.ptr;
		other.ptr = nullptr;
	}

	UniquePtr& operator=(UniquePtr&& other) noexcept
	{
		if (this != &other)
		{
			delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;
		}
		return *this;
	}

	T& operator*() { return *ptr; }
	T* operator->() { 
		try {
			if (!ptr)
				throw std::runtime_error("Null pointer");
			return ptr;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error" << e.what() << std::endl;
			return nullptr;
		}
	}

	void reset(T* newPtr)
	{
		delete ptr;
		ptr = newPtr;
	}

	T* release()
	{
		T* rawPtr = ptr;
		ptr = nullptr;
		return rawPtr;
	}

};
int main()
{
	UniquePtr<int> uniqPtr(new int(99));

	uniqPtr.reset(new int(85));

	return 0;
}


