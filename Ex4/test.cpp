/*
 * test.cpp
 *
 *  Created on: 29.09.2010
 *      Author: daniel
 */

#include "persistent.hpp"

int main(int argc, char* argv[])
{
	pset<int> set("numbers.txt");

	set.insert(5);
	set.insert(6);
	set.insert(3);
}
