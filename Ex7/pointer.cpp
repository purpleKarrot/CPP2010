template<typename T>
class dumb_ptr
{
public:
	dumb_ptr(T* pointee) :
		pointee(pointee)
	{
	}

	~dumb_ptr()
	{
		delete pointee;
	}

	T& operator*()
	{
		return *pointee;
	}

	T& operator->()
	{
		return *pointee;
	}

private:
	T* pointee;

	// noncopyable
	dumb_ptr(dumb_ptr const&);
	void operator=(dumb_ptr const&);
};

template<typename T>
class smart_ptr
{
public:
	smart_ptr(T* pointee) :
		pointee(pointee), refcount(new int(1))
	{
	}

	smart_ptr(smart_ptr const& other) :
		pointee(other.pointee), refcount(other.refcount)
	{
		++*refcount;
	}

	~smart_ptr()
	{
		if (!--*refcount)
		{
			delete pointee;
			delete refcount;
		}
	}

	T& operator*()
	{
		return *pointee;
	}

	T& operator->()
	{
		return *pointee;
	}

private:
	T* pointee;
	int* refcount;
};

