#ifndef COMPLEX_CPP
#define COMPLEX_CPP
#include "complex.h"
#include <math.h> 
using namespace std;

//Constructor Overloads
Complex::Complex() {
	_real = 0.0;
	_imaginary = 0.0;
}
Complex::Complex(double real) {
	_real = real;
	_imaginary = 0.0;
}
Complex::Complex(double real, double imaginary) {
	_real = real;
	_imaginary = imaginary;
}

//Getters for Real and Imaginary numbers
double Complex::getReal() const {
	return _real;
}
double Complex::getImaginary() const {
	return _imaginary;
}

//Setters for Real and Imaginary numbers
void Complex::setReal(double r) {
	_real = r;
}
void Complex::setImaginary(double i) {
	_imaginary = i;
}

//Overloading the input operator to tell the compiler how to input user input
void operator>>(istream& input, Complex& complex)
{

	input >> complex._real >> complex._imaginary;

}
//Overloading the output operator to tell the compiler how to print complex number objects to console
ostream& operator<<(ostream& output, const Complex& complex)
{
	char c;
	//Assiging mathmatic operator for equation
	if (complex._imaginary >= 0) {
		c = '+';
	}
	else {
		c = '-';
	}

	if (complex._imaginary == 0 && complex._real == 0) {
		output << complex._real;
	}
	else if (complex._imaginary == 0) {
		output << complex._real;
	}
	else if (abs(complex._imaginary) == 1 && complex._real == 0) {
		output << c << "i";
	}
	else if (abs(complex._imaginary) == 1) {
		output << complex._real << " " << c << " " << "i";
	}
	else if (abs(complex._imaginary) != 0 && complex._real == 0) {
		output << complex._imaginary;
	}
	else {
		output << complex._real << " " << c << " " << abs(complex._imaginary) << "i";
	}

	return output;
}

//Getting the conjugate of a complex number
Complex Complex::conjugate() {
	Complex conjugate(_real, abs(_imaginary));
	return conjugate;
}

//Implementation of Adding two complex numbers and returning the answer as a new complex number
Complex Complex::operator+ (const Complex& right) const {

	Complex temp;
	temp._real = _real + right._real;
	temp._imaginary = _imaginary + right._imaginary;
	return temp;
}
//Implementation of Subtracting two complex numbers and returning the answer as a new complex number
Complex Complex::operator- (const Complex& right) const {
	Complex temp;

	temp._real = _real - right._real;
	temp._imaginary = _imaginary - right._imaginary;
	return temp;
}
//Implementation of Multiplying a complex number and an integer and returning the answer as a new complex number
Complex Complex::operator* (const int right) const {

	Complex temp;
	temp._real = (_real * right);
	temp._imaginary = (_imaginary * right);
	return temp;
}
//Implementation of Multiplying two complex numbers and returning the answer as a new complex number
Complex Complex::operator* (const Complex& right) const {
	
	Complex temp;
	temp._real = (_real * right._real) - (_imaginary * right._imaginary);
	temp._imaginary = (_real * right._imaginary) + (_imaginary * right._real);
	return temp;
}
//Implementation of Dividing two complex numbers and returning a complex number
Complex Complex::operator/ (const Complex right) const {

	if (right._real == 0 && right._imaginary == 0) {
		cout << "Zero division Error" << endl;
		return *this;
	}
	else {
		Complex temp;
		temp._real = (_real * right._real + _imaginary * right._imaginary) / (right._real * right._real + right._imaginary * right._imaginary);
		temp._imaginary = (_imaginary * right._real + ((-1)*_real) * right._imaginary) / (right._real * right._real + right._imaginary * right._imaginary);
		return temp;
	}
}
//Overload Implemntation of Sum Assignment Operator for two complex numbers

Complex& Complex::operator+=(Complex& right) 
{
	*this = *this + right;
	return *this;
}
//Overload Implemntation of Subtraction Assignment Operator for two complex numbers
Complex& Complex::operator-=(Complex& right) 
{
	*this = *this - right;
	return *this;
}
//Overload Implemntation of Multiplication Assignment Operator for two complex numbers
Complex& Complex::operator*=(Complex& right)  {
	
	*this = *this * right;
	return *this;
}
//Overload Implemntation of Multiplication Assignment Operator for a complex number and an integer
Complex& Complex::operator*=(int right) 
{
	*this = *this * right;
	return *this;
}
//Overload Implemntation of Division Assignment Operator for a complex number and a complex number
Complex& Complex::operator/=(Complex& right) 
{
	if (right._real == 0 && right._imaginary == 0) {
		return *this;
	}
	else {
		*this = *this / right;
		return *this;
	}
}
//Overload Implemntation of Multiplication Assignment Operator for a complex number and an integer
Complex& Complex::operator/=(int right) 
{
	if (right == 0) {
		cout << "Zero division Error" << endl;
		return *this;
	}
	else {
		*this = *this / right;
		return *this;
	}
}
//Overloading the equal too operator to compare two complex numbers

bool Complex::operator== (Complex& right) const {
	if (getReal() == right.getReal() && getImaginary() == right.getImaginary()) {
		return true;
	}
	else {
		return false;
	}
}
//Overloading the equal too operator to compare two complex numbers
bool Complex::operator!= (Complex& right) const {
	if (getReal() != right.getReal() || getImaginary() != right.getImaginary()) {
		return true;
	}
	else {
		return false;
	}
}

#endif

