#include<iostream>
#include"Math1.h"
double sum(double a, double b) 
{
	return a + b;
}
double diff(double a, double b) 
{
	return a - b;
}
double multiplication(double a, double b) 
{
	return a * b;
}
double division(double a, double b) 
{
	return static_cast<double>(a) / (b);
}
double exponenta(double a, double b)
{
	double x = a;
	for (int i = 1; i < static_cast<int>(b); i++) { a = a * x; }
	return a;
};