#include "Factorial.h"

using namespace std;

int main()
{

	long input_data;
	cout << "Input some val: ";
	cin >> input_data;

	Function* func = new Factorial();
	auto res = func->calculate(input_data);

	delete func;
	return 0;
}