#pragma once
#include "Function.h"

class Factorial: public Function
{
public:

	Factorial() {};

private:

	void calculateFunction(long input_value) override;

};

