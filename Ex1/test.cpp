/*
 * test.cpp
 *
 *  Created on: 29.09.2010
 *      Author: daniel
 */

#include "fraction.hpp"
#include <stdexcept>
#include <sstream>

#define CHECK_EQUAL(A, B) check_equal(#A" == "#B, A, B)

template<typename A, typename B>
void check_equal(const char* name, A a, B b)
{
	std::cout << "check '" << name << "' ";

	if (a == b)
	{
		std::cout << "passed: " << a << " == " << b << ".";
	}
	else
	{
		std::cout << "failed: " << a << " != " << b << "!";
	}

	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	fraction f_1_2(1, 2);
	fraction f_1_4(1, 4);
	fraction f_2_4(2, 4);
	fraction f_3_4(3, 4);

	//normalize
	CHECK_EQUAL(f_2_4, f_1_2);

	//plus
	CHECK_EQUAL(f_1_2 + f_1_4, f_3_4);

	//minus
	CHECK_EQUAL(f_1_2 - f_1_4, f_1_4);

	//multiplies
	CHECK_EQUAL(f_1_2 * f_1_2, f_1_4);

	//divides
	CHECK_EQUAL(f_1_2 / f_1_4, 2);
}

