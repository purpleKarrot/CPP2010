/*
 * event.hpp
 *
 *  Created on: 24.11.2010
 *      Author: daniel
 */

#ifndef EVENT_HPP
#define EVENT_HPP

#include <vector>

struct event
{
	int time;
	int floor;
	int target;
};

std::vector<event> read_events(const char* filename);

#endif /* EVENT_HPP */
