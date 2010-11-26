/*
 * rect.cpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

// rect as base of square or vice versa?

// OO designer's view:
// square 'is a' rect, OK!
// rect 'is a' square, not ok!
// --> square should inherit rect.

// prematurely optimizing implementor's view:
// rect has exactly the same mebers as square and some more
// --> rect should inherit square.

// policy based approach is given below.

#include <cassert>

template<typename P>
class rectangle;

class square_policy
{
public:
	static rectangle<square_policy> create(int a);

	void set(int w, int h)
	{
		assert(w == h);
		a = w;
	}

	int w() const
	{
		return a;
	}

	int h() const
	{
		return a;
	}

private:
	int a;
};

class rect_policy
{
public:
	static rectangle<rect_policy> create(int w, int h);

	void set(int w, int h)
	{
		a = w;
		b = h;
	}

	int w() const
	{
		return a;
	}

	int h() const
	{
		return b;
	}

private:
	int a, b;
};

template<typename P>
struct rectangle: P
{
	rectangle()
	{
	}

	template<typename OP>
	rectangle(const rectangle<OP>& other)
	{
		set(other.w(), other.h());
	}

	template<typename OP>
	rectangle& operator=(const rectangle<OP>& other)
	{
		set(other.w(), other.h());
		return *this;
	}

	int area() const
	{
		return this->w() * this->h();
	}
};

rectangle<square_policy> square_policy::create(int a)
{
	rectangle<square_policy> rect;
	rect.set(a, a);
	return rect;
}

rectangle<rect_policy> rect_policy::create(int w, int h)
{
	rectangle<rect_policy> rect;
	rect.set(w, h);
	return rect;
}

typedef rectangle<square_policy> square;
typedef rectangle<rect_policy> rect;

#include <iostream>

int main(int argc, char* argv[])
{
	square s = square::create(2);
	rect r = rect::create(2, 3);

	std::cout << sizeof(s) << " " << s.area() << std::endl;
	std::cout << sizeof(r) << " " << r.area() << std::endl;

	r = s;

	s = rect::create(4, 4);

	std::cout << r.area() << std::endl;
}
