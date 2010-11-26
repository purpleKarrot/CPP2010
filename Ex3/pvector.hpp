/*
 * pvector.hpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#ifndef PVECTOR_HPP
#define PVECTOR_HPP

#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

template<typename T>
class pvector: public std::vector<T>
{
public:
	pvector(const char* filename) :
		filename(filename)
	{
		std::ifstream file(filename);
		std::copy(std::istream_iterator<T>(file), std::istream_iterator<T>(),
				std::insert_iterator<std::vector<T> >(*this, this->begin()));
	}

	~pvector()
	{
		std::ofstream file(filename);
		std::copy(this->begin(), this->end(), std::ostream_iterator<T>(file, "\n"));
	}

private:
	const char* filename;
};

#endif /* PVECTOR_HPP */
