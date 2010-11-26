/*
 * elevator.cpp
 *
 *  Created on: 03.11.2010
 *      Author: daniel
 */

#include "elevator.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cassert>

void elevator::step()
{
	if (up_dest_.empty() && down_dest_.empty())
		return;

	// check for state switches
	switch (state_)
	{
	case ready_:
		state_ = closing_;
		door_ = 12;
		break;
	case moving_:
		if ((!up_dest_.empty() && up_dest_.top() == floor_)
				|| (!down_dest_.empty() && down_dest_.top() == floor_))
		{
			std::cout << "stop on " << floor_ << std::endl;
			state_ = opening_;
			door_ = 12;
		}
		break;
	case opening_:
		if (door_ == 0)
		{
			while (!up_dest_.empty() && up_dest_.top() == floor_)
				up_dest_.pop();

			while (!down_dest_.empty() && down_dest_.top() == floor_)
				down_dest_.pop();

			if (up_dest_.empty() && down_dest_.empty())
			{
				state_ = ready_;
				std::cout << "done" << std::endl;
			}
			else
			{
				std::cout << "bye" << std::endl;
				ascending_ = down_dest_.empty();
				state_ = closing_;
				door_ = 12;
			}
		}
		break;
	case closing_:
		if (door_ == 0)
		{
			state_ = moving_;
			std::cout << "door closed, up=" << ascending_ << std::endl;
		}
		break;
	}

	// update depending on new state
	switch (state_)
	{
	case moving_:
		if (ascending_)
			++floor_;
		else
			--floor_;
		break;
	case opening_:
	case closing_:
		--door_;
		break;
	}
}

void elevator::send(int from, int to)
{
	int next = (from == floor_) ? to : from;

	if (ready())
	{
		ascending_ = next > floor_;
	}
	else
	{
		assert(next > floor_ == ascending_);
	}

	if (from > floor_)
		up_dest_.push(from);
	else if (from < floor_)
		down_dest_.push(from);

	if (to > from)
		up_dest_.push(to);
	else if (to < from) // haha, some idiot pressed the button ;-)
		down_dest_.push(to);
}
