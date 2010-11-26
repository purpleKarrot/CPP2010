/*
 * calc_frac.cpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#include <vector>
#include "calculator.hpp"
#include "../Ex1/fraction.hpp"

int main(int argc, char* argv[])
{
	std::vector<fraction> stack;
	calculator<fraction> calc(stack);

	calc.run();
}
