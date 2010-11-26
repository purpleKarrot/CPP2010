/*
 * main.cpp
 *
 *  Created on: 24.11.2010
 *      Author: daniel
 */

#include "event.hpp"
#include "elevator.hpp"
#include <iostream>
#include <cassert>

elevator elevators[3];

bool elevators_ready()
{
	return elevators[0].ready() && elevators[1].ready() && elevators[2].ready();
}

void handle_request(int floor, int target)
{
	for (int i = 0; i < 3; ++i)
	{
		elevator& e = elevators[i];

		int next = floor == e.floor() ? target : floor;
		bool right_direction = e.floor() < next == e.ascending();

		if (e.ready() || right_direction)
		{
			e.send(floor, target);
			return;
		}
	}

	assert(!"No elevator can handle this request with this simple logic!");
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "not enough parameters!" << std::endl;
		return -1;
	}

	std::vector<event> events = read_events(argv[1]);
	int time = 0;

	while (!events.empty() || !elevators_ready())
	{
		std::cout << "time: " << double(time) / 2 << ": ";

		while (events.back().time == time)
		{
			handle_request(events.back().floor, events.back().target);
			events.pop_back();
		}

		elevators[0].step();
		elevators[1].step();
		elevators[2].step();

		++time;

		std::cout << std::endl;
	}

	std::cout << "total delivery time: " << double(time) / 2 << " seconds."
			<< std::endl;
}
