/*
 * calc_pvec.cpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#include "pvector.hpp"
#include "calculator.hpp"

int main(int argc, char* argv[])
{
	pvector<int> stack("numbers.txt");
	calculator<int> calc(stack);

	calc.run();
}
