/*
 * calculator.cpp
 *
 *  Created on: 29.09.2010
 *      Author: daniel
 */

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <sstream>
#include <iostream>

#include "min.hpp"

template<typename T>
class calculator
{
public:
	calculator(std::vector<T>& stack) :
		stack(stack)
	{
	}

	bool run_once()
	{
		std::cout << "Command: ";

		std::string line;
		std::getline(std::cin, line);
		std::istringstream in(line);

		char command;
		for (;;)
		{
			in >> command;

			if (in.eof())
				return true;

			switch (command)
			{
			case 'q':
			case 'Q':
				return false;
			case 'n':
			case 'N':
			{
				T number;
				in >> number;
				stack.push_back(number);
				break;
			}
			case 'd':
			case 'D':
				stack.pop_back();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case 'm':
			{
				T i2 = stack.back();
				stack.pop_back();

				T i1 = stack.back();
				stack.pop_back();

				stack.push_back(calculate(command, i1, i2));
				break;
			}

			default:
				std::cout << "Ignoring command '" << command << "'"
						<< std::endl;
			}
		}
		return true;
	}

	void print()
	{
		for (std::size_t i = 0; i < stack.size(); ++i)
		{
			std::cout << i + 1 << ": " << stack[i] << std::endl;
		}
	}

	void run()
	{
		do
			print();
		while (run_once());
	}

private:
	T calculate(char op, T i1, T i2)
	{
		switch (op)
		{
		case '+':
			return i1 + i2;
		case '-':
			return i1 - i2;
		case '*':
			return i1 * i2;
		case '/':
			return i1 / i2;
		case 'm':
			return mymin(i1, i2);
		}
		//assert(!"invalid operator");
	}

private:
	std::vector<T>& stack;
};

#endif /* CALCULATOR_HPP */
