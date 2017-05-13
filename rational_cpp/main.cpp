#include <iostream>
#include "Rational.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Rational a, b, c;
	

	a.set(2,- 3);
	std::cout << a.to_string() << std::endl;

	b.set(-4, 9);
	std::cout << b.to_string() << std::endl;

	c = a.pow(-1); // fehler
	std::cout << c.to_string() << std::endl;

	Rational d = b.pow(3);
	std::cout << d.to_string() << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	int ok;
	std::cin >> ok;

	return 0;
}
