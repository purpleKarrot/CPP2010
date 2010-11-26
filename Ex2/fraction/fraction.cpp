/*
 * fraction.cpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#include "fraction.hpp"
#include "util.hpp"
#include <iostream>

fraction::fraction(int num, int den) :
	num(num), den(den)
{
	normalize();
}

fraction::fraction(fraction const& other) :
	num(other.num), den(other.den)
{
}

fraction::operator double() const
{
	return double(num) / double(den);
}

fraction& fraction::operator=(fraction const& other)
{
	num = other.num;
	den = other.den;
	return *this;
}

fraction& fraction::operator+=(fraction const& other)
{
	int f = gcd(den, other.den);

	num = (other.den / f) * num + (den / f) * other.num;
	den = (den / f) * other.den;

	return *this;
}

fraction& fraction::operator-=(fraction const& other)
{
	return operator+=(fraction(-other.num, other.den));
}

fraction& fraction::operator*=(fraction const& other)
{
	int f1 = gcd(num, other.den);
	int f2 = gcd(other.num, den);

	num = (num / f1) * (other.num / f2);
	den = (den / f2) * (other.den / f1);

	return *this;
}

fraction& fraction::operator/=(fraction const& other)
{
	return operator*=(fraction(other.den, other.num));
}

bool fraction::operator==(fraction const& other) const
{
	return num == other.num && den == other.den;
}

bool fraction::operator!=(fraction const& other) const
{
	return !operator==(other);
}

std::ostream& operator<<(std::ostream& out, fraction const& self)
{
	return out << self.num << '/' << self.den;
}

fraction operator+(fraction left, fraction const& right)
{
	return left += right;
}

fraction operator-(fraction left, fraction const& right)
{
	return left -= right;
}

fraction operator*(fraction left, fraction const& right)
{
	return left *= right;
}

fraction operator/(fraction left, fraction const& right)
{
	return left /= right;
}

void fraction::normalize()
{
	int d = gcd(num, den);
	num /= d;
	den /= d;

	if (den < 0)
	{
		num = -num;
		den = -den;
	}
}
