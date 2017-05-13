#include "Rational.h"
#include <iostream>
#include <sstream>

Rational::Rational(){
	set(0UL,1UL);
	set_reduce(true);
	set_sign(false);
}

Rational::Rational(const int _numerator,const int _denominator) {
	set(_numerator, _denominator);  // go to the int version and than to the long
}

Rational::Rational(const long _numerator,const long _denominator) {
	set(_numerator, _denominator); // the long version
}

void Rational::set(const int _numerator, const int _denominator) {
	set(static_cast<long>(_numerator), static_cast<long>(_denominator)); // just go to the long setter
}

void Rational::set(const long _numerator, const long _denominator) {
	set_sign(xor (_numerator < 0, _denominator < 0));
	set(abs(_numerator), abs(_denominator));
}

void Rational::set(const unsigned long _numerator, const unsigned long _denominator) {
	if (_numerator != 0) {
		numerator = _numerator;
		denominator = _denominator;
	}
	else {
		numerator = 0UL;
		denominator = 1UL;
	}
}

void Rational::set_reduce(const bool _reduce) {
	reduce = _reduce;
}

void Rational::set_sign(const bool _sign) {
	sign = _sign;
}

unsigned long Rational::get_numerator() {
	return numerator;
}

unsigned long Rational::get_denominator() {
	return denominator;
}

bool Rational::get_sign() {
	return sign;
}

Rational Rational::add(Rational r){
	Rational a;

	unsigned long _y = r.get_denominator() * numerator;
	unsigned long _x = r.get_numerator() * denominator;
	if ( sign && r.get_sign() ) { // addition of 2 negativ Rationals
		a.set_sign(true);    // the result will be negative
		a.set(_x + _y, r.get_denominator() * denominator);
	}
	else if ( !sign && r.get_sign() ) { // addtion if a positiv PLUS a negativ Rational 
		if (_x >= _y) { // the result will be negative or zero
			a.set_sign(true);
			a.set(_x - _y, r.get_denominator() * denominator);
		}
		else { // the result will be positive
			a.set(_y - _x, r.get_denominator() * denominator);
		}
	}
	else if ( sign && !r.get_sign() ) { // addtion if a negativ PLUS a positiv Rational 
		if (_y >= _x) { // the result will be negativ or zero
			a.set_sign(true);
			a.set(_y - _x, r.get_denominator() * denominator);
		}
		else { // the result will be positive
			a.set(_x - _y, r.get_denominator() * denominator);
		}
	}
	else { // addition of 2 positiv Rationals
		a.set(_x + _y, r.get_denominator() * denominator);
	}
	return a;
}

Rational Rational::sub(Rational r){
	Rational a;
	r.set_sign(xor(true,r.get_sign()));
	a = this->add(r);
	return a;
}

Rational Rational::mul(Rational r){
	Rational a;
	a.set_sign( xor(sign, r.get_sign()) );
	a.set(r.get_numerator() * numerator, r.get_denominator() * denominator);
	return a;
}

Rational Rational::div(Rational r){
	Rational a;
	a = this->mul(r.inv());
	return a;
}

Rational Rational::pow(int n){
	Rational a;
	if (n % 2 == 0) {
		a.set_sign(false);
	}
	else {
		a.set_sign(get_sign());
	}

	if (n > 0) {
		a.set(pow(get_numerator(), n), pow(get_denominator(), n));
	}
	else if (n < 0) {
		a.set(pow(get_denominator(), -n), pow(get_numerator(), -n));
	}
	else { // if n == 0
		a.set(1UL, 1UL);
	}

	return a;
}

Rational Rational::inv(){
	Rational a;
	a.set_sign(get_sign());
	a.set(get_denominator(), get_numerator());
	return a;
}

		
/*Rational operator+(Rational a,Rational b);
Rational operator-(Rational a,Rational b);
Rational operator*(Rational a,Rational b);
Rational operator/(Rational a,Rational b);
	
Rational operator==(Rational a,Rational b);
Rational operator!=(Rational a,Rational b);
Rational operator<=(Rational a,Rational b);
Rational operator>=(Rational a,Rational b);
Rational operator<(Rational a,Rational b);
Rational operator>(Rational a,Rational b);*/

long Rational::gcd(){
	return 1L;
}

std::string Rational::to_string(){
	std::stringstream ss;
	ss << ( (sign) ? "-" : "" );
	ss << numerator << " // " << denominator;
	return ss.str();
}

bool Rational::xor(const bool p, const bool q){
	return (p && !q) || (!p && q);
}

unsigned long Rational::abs(long a) {
	if (a < 0) {
		return static_cast<unsigned long>(-a);
	}
	else{
		return static_cast<unsigned long>(a);
	}
}

unsigned long Rational::pow(const unsigned long b, const unsigned int n){
	if (n == 0) return 1UL;
	unsigned long p2 = pow(b, n / 2);
	if (n % 2)
		return p2*p2*b;
	else
		return p2*p2;
}