#include <string>
class Rational{
	private:
		unsigned long numerator;
		unsigned long denominator;
		bool sign;    // false == positive; true == negative
		bool reduce;
		
		void set(const unsigned long _numerator, const unsigned long _denominator);
		long gcd();
		bool xor(const bool p,const bool q);
		unsigned long Rational::abs(long a);
		unsigned long Rational::pow(const unsigned long b, const unsigned int n);
		long Rational::sgn(long a);

	public:
		Rational();
		Rational(const int _numerator, const int _denominator);
		Rational(const long _numerator, const long _denominator);

		void set(const int _numerator, const int _denominator);
		void set(const long _numerator, const long _denominator);
		void set_reduce(const bool _reduce);
		void set_sign(const bool _sign);
		
		unsigned long get_numerator();
		unsigned long get_denominator();
		bool get_sign();
		bool equal(Rational r);
		bool identical(Rational r);
		bool Rational::lessThan(Rational r);
		bool Rational::greaterThan(Rational r);
		bool Rational::lessThanOrEqual(Rational r);
		bool Rational::greaterThanOrEqual(Rational r);


		Rational add( Rational r);
		Rational sub( Rational r);
		Rational mul( Rational r);
		Rational div( Rational r);
		Rational pow( const int r);
		Rational Rational::inv();
		Rational operator+(Rational r);
		Rational operator-(Rational r);
		Rational operator*(Rational r);
		Rational operator/(Rational r);
		

		bool operator==(Rational r);
		bool operator!=(Rational r);
		bool operator<=(Rational r);
		bool operator>=(Rational r);
		bool operator<(Rational r);
		bool operator>(Rational r);
		
		std::string to_string();
		
		
};
