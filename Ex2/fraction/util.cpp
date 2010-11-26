/*
 * util.cpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#include "util.hpp"

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
