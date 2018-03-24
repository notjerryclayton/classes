/* 
Jerry Clayton
CS 2124
Recitation 8: Operator Overloading
Implements several operators for a Rational Number Class
*/

#include "Rational.h"
#import<iostream>
using namespace std;
namespace CS2124{

	Rational::Rational(){} 
	Rational::Rational(int whole) : numerator(whole), denominator(1) {}
	Rational::Rational(int top, int bot) : numerator(top), denominator(bot) {
		normalize();
	}

	Rational& Rational::operator+=(const Rational& rhs){
		(numerator *= rhs.denominator) += (denominator * rhs.numerator);
		denominator *= rhs.denominator; 
		normalize();
		return *this;
	}
	Rational& Rational::operator++(){ //pre-increment
		numerator += denominator; 
		return *this;
	}
	Rational Rational::operator++(int){ //post-increment
		Rational result = *this;
		numerator += denominator;
		return result;
	}
	Rational::operator bool(){
		return numerator != 0;
	}
	int Rational::greatestCommonDivisor(int x, int y) {
	    while (y != 0) {
	        int temp = x % y;
	        x = y;
	        y = temp;
	    }
    return x;

	}
	void Rational::normalize(){
		bool negative = false;
		int gcd;
		if((0 > numerator ||  0 > denominator) && !(0 > numerator && 0 > denominator))
			negative = true;

		gcd = (numerator > denominator) ? greatestCommonDivisor(numerator, denominator) :
			greatestCommonDivisor(denominator, numerator);

		numerator /= gcd;
		denominator /= gcd;

		if(negative && denominator < 0){
			numerator *= -1;
			denominator *= -1;
		}
	}

	int numerator;
	int denominator;
	

	ostream& operator<<(ostream& os, const Rational& r){
		os << r.numerator << '/' << r.denominator;
		return os;
	}

	istream& operator>>(istream& is, Rational& r){
		char slash;
		is >> r.numerator >> slash >> r.denominator;
		r.normalize();
		return is;
	}

	bool operator==(const Rational& lhs, const Rational& rhs){
		if(lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator)
			return true;

		return false;
	}

	bool operator!=(const Rational& lhs, const Rational& rhs){
		if(lhs == rhs)
			return false;

		return true;
	}
	Rational operator+(Rational lhs, const Rational& rhs){
		lhs += rhs;
		return lhs;
	}

	Rational& operator--(Rational& r){ //pre-decrement
		r += -1;
		return r;
	}
	Rational operator--(Rational& r, int){ //post-decrement
		Rational result = r;
		r += -1;
		return result;
	}
}





