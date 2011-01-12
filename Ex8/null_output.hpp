// iterator that ignores all output

class null_output_iterator:
	public std::iterator<std::output_iterator_tag, void, void, void, void>
{
public:
	// default ctors and dtor are ok

	template<typename T>
	null_output_iterator& operator=(const T&)
	{
		return *this;
	}

	null_output_iterator& operator*()
	{
		return *this;
	}

	null_output_iterator& operator++()
	{
		return *this;
	}

	null_output_iterator& operator++(int)
	{
		return *this;
	}
};
