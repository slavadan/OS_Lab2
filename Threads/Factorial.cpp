#include "Factorial.h"

void Factorial::calculateFunction(long input_value)
{

	std::unique_lock<std::mutex> lock(_calcMutex);

	while (_currentArgumentVal <= input_value)
	{

		_currentFuncVal *= _currentArgumentVal;
		++_currentArgumentVal;


		time_t now = time(0);
		std::string currentTime = ctime(&now);

		_currentVal = std::shared_ptr<Point>(new Point(_currentFuncVal, currentTime));

		_calcCondVar.notify_all();
		_logCondVar.wait(lock);
	}

	_done = true;
	_calcCondVar.notify_all();
}
