// Copyright (c) 2010 Daniel Pfeifer <daniel@pfeifer-mail.de>

#include <algorithm>
#include <iostream>

class fraction
{
public:
	explicit fraction(int num = 0, int den = 1) :
		num(num), den(den)
	{
		normalize();
	}

	fraction(fraction const& other) :
		num(other.num), den(other.den)
	{
	}

	operator double() const
	{
		return double(num) / double(den);
	}

	fraction& operator=(fraction const& other)
	{
		num = other.num;
		den = other.den;
		return *this;
	}

	fraction& operator+=(fraction const& other)
	{
		int f = gcd(den, other.den);

		num = (other.den / f) * num + (den / f) * other.num;
		den = (den / f) * other.den;

		return *this;
	}

	fraction& operator-=(fraction const& other)
	{
		return operator+=(fraction(-other.num, other.den));
	}

	fraction& operator*=(fraction const& other)
	{
		int f1 = gcd(num, other.den);
		int f2 = gcd(other.num, den);

		num = (num / f1) * (other.num / f2);
		den = (den / f2) * (other.den / f1);

		return *this;
	}

	fraction& operator/=(fraction const& other)
	{
		return operator*=(fraction(other.den, other.num));
	}

	bool operator==(fraction const& other) const
	{
		return num == other.num && den == other.den;
	}

	bool operator!=(fraction const& other) const
	{
		return !operator==(other);
	}

private:
	friend std::istream& operator>>(std::istream& in, fraction& self)
	{
		return (in >> self.num).ignore(2, '/') >> self.den;
	}

	friend std::ostream& operator<<(std::ostream& out, fraction const& self)
	{
		return out << self.num << '/' << self.den;
	}

	friend fraction operator+(fraction left, fraction const& right)
	{
		return left += right;
	}

	friend fraction operator-(fraction left, fraction const& right)
	{
		return left -= right;
	}

	friend fraction operator*(fraction left, fraction const& right)
	{
		return left *= right;
	}

	friend fraction operator/(fraction left, fraction const& right)
	{
		return left /= right;
	}

	void normalize()
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

	static int gcd(int a, int b)
	{
		return !b ? a : gcd(b, a % b);
	}

private:
	int num;
	int den;
};
