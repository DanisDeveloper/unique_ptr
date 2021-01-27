#ifndef _MY_UNIQUE_PTR_
#define _MY_UNIQUE_PTR_
                                                                     // not for array
template<class T>
class my_unique_ptr
{
private:
	T* m_ptr;

public:
	my_unique_ptr(T* ptr = nullptr) :m_ptr(ptr) {}
	my_unique_ptr(const my_unique_ptr<T>&& ptr)
	{
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;
	}
	my_unique_ptr& operator=(const my_unique_ptr<T>&& ptr)
	{
		if (m_ptr = ptr.m_ptr)
			return *this;

		delete m_ptr;
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;

		return *this;
	}

	my_unique_ptr(const my_unique_ptr<T>& ptr) = delete;
	my_unique_ptr& operator=(const my_unique_ptr<T>& ptr) = delete;

	T& operator*() const { return *m_ptr; }
	T* operator->()const { return m_ptr; }

	bool isNull() const { return (m_ptr == nullptr); }

	~my_unique_ptr() { delete m_ptr; }

};

                                                                     // for array
template<class T>
class my_unique_ptr<T[]>
{
private:
	T* m_ptr;

public:
	my_unique_ptr(T* ptr = nullptr) :m_ptr(ptr) {}
	my_unique_ptr(const my_unique_ptr < T[]>&& ptr)
	{
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;
	}
	my_unique_ptr& operator=(const my_unique_ptr<T[]>&& ptr)
	{
		if (m_ptr = ptr.m_ptr)
			return *this;

		delete m_ptr;
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;

		return *this;
	}

	my_unique_ptr(const my_unique_ptr<T[]>& ptr) = delete;
	my_unique_ptr& operator=(const my_unique_ptr<T[]>& ptr) = delete;

	T& operator*() const { return *m_ptr; }
	T* operator->()const { return m_ptr; }
	T& operator[](const int& number)
	{
		return m_ptr[number];
	}

	bool isNull() const { return (m_ptr == nullptr); }

	~my_unique_ptr() { delete[] m_ptr; }

};

#endif