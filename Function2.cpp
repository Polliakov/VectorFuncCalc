#include <iostream>
#include <math.h>

#include "FunctionContainer.cpp"

using namespace std;

class Function2 : public FunctionContainer
{
public:
	Function2(double a, double x, double b)
	{
		this->a = a;
		this->x = x;
		this->b = b;
	}

	double invoke() override
	{
		return a * pow(x, b);
	}
};