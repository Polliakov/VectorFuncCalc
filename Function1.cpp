#include <iostream>
#include <math.h>

#include "FunctionContainer.cpp"

using namespace std;

class Function1 : public FunctionContainer
{
public:
	Function1(double a, double x, double b, double c)
	{
		this->a = a;
		this->x = x;
		this->b = b;
		this->c = c;
	}

	double invoke() override
	{
		return a * cos(b * x) + c;
	}
};