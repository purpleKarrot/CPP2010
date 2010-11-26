/*
 * combineops.cpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>

template<class BinOp, class Op1, class Op2>
class combineops_t: public std::unary_function<typename Op1::argument_type,
		typename BinOp::result_type>
{
public:
	combineops_t(BinOp binop, Op1 op1, Op2 op2) :
		o(binop), o1(op1), o2(op2)
	{
	}

	typename BinOp::result_type operator()(const typename Op1::argument_type &x)
	{
		return o(o1(x), o2(x));
	}

protected:
	BinOp o;
	Op1 o1;
	Op2 o2;
};

template<typename T>
class add: public std::unary_function<T, T>
{
public:
	add(T val) :
		val(val)
	{
	}

	T operator()(T number)
	{
		return number + val;
	}

private:
	T val;
};

template<typename T>
struct subtract: std::unary_function<T, T>
{
public:
	subtract(T val) :
		val(val)
	{
	}

	T operator()(T number)
	{
		return number - val;
	}

private:
	T val;
};

template<typename T>
struct divide: std::binary_function<T, T, double>
{
	double operator()(T a, T b)
	{
		return double(a) / double(b);
	}
};

// x-1/x+1
template<typename T>
struct fancy_op: combineops_t<divide<T> , subtract<T> , add<T> >
{
	typedef combineops_t<divide<T> , subtract<T> , add<T> > super;

	fancy_op() :
		super(divide<T> (), subtract<T> (1), add<T> (1))
	{
	}
};

int main(int argc, char* argv[])
{
	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//! boost::phoenix could make it much more readable!!
	//!	std::transform(numbers, numbers + 10, //
	//!			std::ostream_iterator<double>(std::cout, ", "), _1 - 1 / _1 + 1);

	std::transform(numbers, numbers + 10, //
			std::ostream_iterator<double>(std::cout, ", "), fancy_op<int> ());

	std::cout << std::endl;
}
