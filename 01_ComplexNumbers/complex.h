
#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;

class Complex
{
private:
	double _real;
	double _imaginary;

public:

	//Default and Overloaded Constructors taking: 0 arguments, 1, argument, and 2 arguments
	Complex();
	Complex(double real);
	Complex(double real, double imaginary);

	//Accessor Methods that return the private data fields
	//labeled "const" to tell compiler this method will NOT change any data fields of objects
	double getReal() const;
	double getImaginary() const;

	//Mutator Methods that have access to changing the private data fields
	void setReal(double r);
	void setImaginary(double i);

	//Overloading the input operator to tell the compiler how to input user input
	friend void operator>>(istream& input, Complex& complex);
	//Overloading the output operator to tell the compiler how to print complex number objects to console
	friend ostream& operator<<(ostream& output, const Complex& complex);

	//Getting the conjugate of a complex number
	Complex conjugate();

	//Implementation of Adding two complex numbers and returning the answer as a new complex number
	Complex operator+ (const Complex& right) const;
	//Implementation of Subtracting two complex numbers and returning the answer as a new complex number
	Complex operator- (const Complex& right) const;
	//Implementation of Multiplying a complex number and an integer and returning the answer as a new complex number
	Complex operator* (const int right) const;
	//Implementation of Multiplying two complex numbers and returning the answer as a new complex number
	Complex operator* (const Complex& right) const;
	//Implementation of Dividing two complex numbers and returning a complex number
	Complex operator/ (const Complex right) const;
	//Overload Implemntation of Sum Assignment Operator for two complex numbers
	
	Complex& operator+=(Complex& right) ;
	//Overload Implemntation of Subtraction Assignment Operator for two complex numbers
	Complex& operator-=(Complex& right) ;
	//Overload Implemntation of Multiplication Assignment Operator for two complex numbers
	Complex& operator*=(Complex& right) ;
	//Overload Implemntation of Multiplication Assignment Operator for a complex number and an integer
	Complex& operator*=(int right) ;
	//Overload Implemntation of Division Assignment Operator for a complex number and a complex number
	Complex& operator/=(Complex& right) ;
	//Overload Implemntation of Multiplication Assignment Operator for a complex number and an integer
	Complex& operator/=(int right) ;

	//Overloading the equal too operator to compare two complex numbers
	bool operator== (Complex& right) const;
	//Overloading the equal too operator to compare two complex numbers
	bool operator!= (Complex& other) const;
};

#endif



