/*
 * persistent.hpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#ifndef PERSISTENT_HPP
#define PERSISTENT_HPP

#include <set>
#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>

template<typename T, typename U = T>
struct persistor
{
	template<typename C>
	static void read(const char* filename, C& self)
	{
		std::ifstream file(filename);
		std::copy(std::istream_iterator<T>(file), std::istream_iterator<T>(),
				std::insert_iterator<C>(self, self.begin()));
	}

	template<typename C>
	static void write(const char* filename, const C& self)
	{
		std::ofstream file(filename);
		std::copy(self.begin(), self.end(),
				std::ostream_iterator<U>(file, "\n"));
	}
};

//struct line
//{
//	std::string data;
//
//	operator std::string() const
//	{
//		return data;
//	}
//
//	friend std::istream& operator>>(std::istream& str, line& self)
//	{
//		return std::getline(str, self.data);
//	}
//};
//
//template<>
//struct persistor<std::string> : persistor<line, std::string>
//{
//};

template<typename T, typename P = persistor<T> >
class pvector: public std::vector<T>
{
public:
	pvector(const char* filename) :
		filename(filename)
	{
		P::read(filename, *this);
	}

	~pvector()
	{
		P::write(filename, *this);
	}

private:
	const char* filename;
};

template<typename T, typename P = persistor<T> >
class pset: public std::set<T>
{
public:
	pset(const char* filename) :
		filename(filename)
	{
		P::read(filename, *this);
	}

	~pset()
	{
		P::write(filename, *this);
	}

private:
	const char* filename;
};

#endif /* PERSISTENT_HPP */
