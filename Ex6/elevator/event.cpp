/*
 * event.cpp
 *
 *  Created on: 24.11.2010
 *      Author: daniel
 */

#include "event.hpp"
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cassert>

static inline std::istream& operator>>(std::istream& in, event& e)
{
	(in >> e.time).ignore(2, ',');
	(in >> e.floor).ignore(2, ',');
	(in >> e.target).ignore(2, '\n');
	e.time *= 2;
	return in;
}

static inline bool operator>(event const& e1, event const& e2)
{
	return e1.time > e2.time;
}

static std::vector<event> read_events(std::istream& in)
{
	std::vector<event> events;

	typedef std::istream_iterator<event> input_iterator;
	std::copy(input_iterator(in), input_iterator(), std::back_inserter(events));

	std::sort(events.begin(), events.end(), std::greater<event>());
	return events;
}

std::vector<event> read_events(const char* filename)
{
	assert(filename);

	if (filename[0] == '-' && !filename[1])
		return read_events(std::cin);

	std::ifstream file(filename);
	return read_events(file);
}

