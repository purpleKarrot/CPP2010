/*
 * fraction.hpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iosfwd>

class fraction
{
public:
	explicit fraction(int num = 0, int den = 1);

	fraction(fraction const& other);

	operator double() const;

	fraction& operator=(fraction const& other);

	fraction& operator+=(fraction const& other);

	fraction& operator-=(fraction const& other);

	fraction& operator*=(fraction const& other);

	fraction& operator/=(fraction const& other);

	bool operator==(fraction const& other) const;

	bool operator!=(fraction const& other) const;

private:
	friend std::ostream& operator<<(std::ostream& out, fraction const& self);

	friend fraction operator+(fraction left, fraction const& right);

	friend fraction operator-(fraction left, fraction const& right);

	friend fraction operator*(fraction left, fraction const& right);

	friend fraction operator/(fraction left, fraction const& right);

	void normalize();

private:
	int num;
	int den;
};

#endif /* FRACTION_HPP */
