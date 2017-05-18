#include <iostream>
#include "Rational.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Rational a, b, c, d;
	
	a.set_cancel(false);
	a.set(3,0);
	std::cout << a.to_string() << std::endl;

	b.set_cancel(false);
	b.set(2,0);
	std::cout << b.to_string() << std::endl;

	std::cout << "Mul c" << std::endl;

	c = a + b;
	std::cout << c.to_string() << std::endl;

	std::cout << "Mul d" << std::endl;
	d.set_cancel(false);
	d = a + b;
	std::cout << d.to_string() << std::endl;

	std::cout << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << a.identical(b) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << c.to_double() << std::endl;
	std::cout << d.to_float() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	int ok;
	std::cin >> ok;

	return 0;
}
