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
		
		Rational add( Rational a);
		Rational sub( Rational a);
		Rational mul( Rational a);
		Rational div( Rational a);
		Rational pow( const int b);
		Rational Rational::inv();
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
		
		std::string to_string();
		
		
};
