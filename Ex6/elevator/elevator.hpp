/*
 * elevator.hpp
 *
 *  Created on: 03.11.2010
 *      Author: daniel
 */

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <queue>

class elevator
{
public:
	elevator() :
		floor_(0), state_(ready_)
	{
	}

	~elevator()
	{
	}

	//! get the current floor ot the elevator
	int floor() const
	{
		return floor_;
	}

	bool ascending() const
	{
		return ascending_;
	}

	bool ready() const
	{
		return state_ == ready_;
	}

	//! advance time 0.5 seconds
	void step();

	//! send elevator to destination
	void send(int from, int to);

private:
	int floor_;
	int door_;

	//! the elevator will move upwards
	bool ascending_;

	enum
	{
		ready_, moving_, opening_, closing_
	} state_;

	std::priority_queue<int, std::vector<int>, std::greater<int> > up_dest_;
	std::priority_queue<int, std::vector<int>, std::less<int> > down_dest_;

private:
	elevator(elevator const&);
	void operator=(elevator const&);
};

#endif /* ELEVATOR_HPP */
