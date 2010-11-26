/*
 * min.hpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#ifndef MIN_HPP
#define MIN_HPP

template<typename T>
class mymin
{
public:
	mymin(T& val) :
		val(val)
	{
	}

	void operator()(T other)
	{
		if (val > other)
			val = other;
	}

private:
	T& val;
};

#endif /* MIN_HPP */
