template<typename Base>
class range_checked_iterator: public Base
{
public:
	range_checked_iterator(Base const& begin, Base const& end) :
		Base(begin), begin(begin), end(end)
	{
	}

	// check also:
	// operator--(int)
	// operator++(int)

	// better: dont check increment/decrement, but dereference operators!

	range_checked_iterator& operator--()
	{
		if (*this == begin)
		{
			throw std::out_of_range("trying to decrement pre begin");
		}

		this->Base::operator--();
	}

	range_checked_iterator& operator++()
	{
		if (*this == end)
		{
			throw std::out_of_range("trying to increment post end");
		}

		this->Base::operator++();
	}

private:
	Base begin, end;
};
