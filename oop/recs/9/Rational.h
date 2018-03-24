#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
namespace CS2124{
	class Rational{
	public:
		Rational();
		Rational(int whole);
		Rational(int top, int bot);

		Rational& operator+=(const Rational& rhs);
		Rational& operator++();
		Rational operator++(int);
		explicit operator bool();
		private:
			int greatestCommonDivisor(int x, int y);
			void normalize();
			int numerator;
			int denominator;
	friend std::ostream& operator<<(std::ostream& os, const Rational& r);
	friend std::istream& operator>>(std::istream& is, Rational& r);
	friend bool operator==(const Rational& lhs, const Rational& rhs);
	};

	std::ostream& operator<<(std::ostream& os, const Rational& r);

	std::istream& operator>>(std::istream& is, Rational& r);

	bool operator==(const Rational& lhs, const Rational& rhs);

	bool operator!=(const Rational& lhs, const Rational& rhs);
	Rational operator+(Rational lhs, const Rational& rhs);

	Rational& operator--(Rational& r);
	Rational operator--(Rational& r, int);
}
#endif