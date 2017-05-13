# rationalNumber

In the new programming language "Julia" exist a cool feature which allows you to use rational numbers. Here I provide a similar tool for C++. 


In the future, there will be this tool also for other programming language like C# or Java.

# c++

How to use this library?

First, use have to add this repository to your code. After that you have to include it:

#include "Rational.h"

Is this done you can declare rational numbers with:

  Rational r1;  

It exist also a constructor to set a rational number. 

  Rational r2(3,5);
  
and of course a setter methode

  r1.set(5,7);
  
The first argument is the numerator and the secound is the denominator.

Actual are the following methode available to calculate with rational numbers:

Rational R = r1.add(r2);     // Will add up the two rational numbers and return the result as a rational number

Rational R = r1.sub(r2);     // do the subtraction

Rational R = r1.mul(r2);     // do the multiplication

Rational R = r1.div(r2);     // do the division

Rational R = r1.inv();       // calculate the reciprocal

Rational R = r1.pow(n);      // calculates the power. Wherebe n have to be an integer type

to get the results you can use the getter methodes:

R.get_numerator();
R.get_denominator();

For the sign of the rational number use 

R.get_sign();  // true == negativ number, false == positiv number

