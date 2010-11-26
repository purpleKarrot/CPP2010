/*
 * calculator.cpp
 *
 *  Created on: 29.09.2010
 *      Author: daniel
 */

#include <vector>
#include <sstream>
#include <iostream>

class calculator
{
public:
	calculator()
	{
	}

	bool run()
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
				int number;
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
			{
				int i2 = stack.back();
				stack.pop_back();

				int i1 = stack.back();
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

private:
	int calculate(char op, int i1, int i2)
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
		}
		//assert(!"invalid operator");
	}

private:
	std::vector<int> stack;
};

int main(int argc, char* argv[])
{
	calculator calc;

	while (calc.run())
		calc.print();
}
