/* 
Jerry Clayton
CS 2124
Recitation 8: Operator Overloading
Implements several operators for a Rational Number Class
*/
#import<iostream>
using namespace std;

class Rational{
	public:
		Rational(){} 
		Rational(int whole) : numerator(whole), denominator(1) {}
		Rational(int top, int bot) : numerator(top), denominator(bot) {
			normalize();
		}

		Rational& operator+=(const Rational& rhs){
			(numerator *= rhs.denominator) += (denominator * rhs.numerator);
			denominator *= rhs.denominator; 
			normalize();
			return *this;
		}
		Rational& operator++(){ //pre-increment
			numerator += denominator; 
			return *this;
		}
		Rational operator++(int){ //post-increment
			Rational result = *this;
			numerator += denominator;
			return result;
		}
		explicit operator bool(){
			return numerator != 0;
		}
	private:
		void normalize(){

		}
		int numerator;
		int denominator;
	friend ostream& operator<<(ostream& os, const Rational& r);
	friend istream& operator>>(istream& is, Rational& r);
	friend bool operator==(const Rational& lhs, const Rational& rhs);
};

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






