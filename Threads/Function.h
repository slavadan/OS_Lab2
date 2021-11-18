#pragma once
#include <thread>
#include <condition_variable>
#include "Logger.h"
#include "Point.h"


class Function
{
public:

	Function() :
		_done(false), _currentArgumentVal(1), _currentFuncVal(1)
	{};

	~Function() {};

	int calculate(long input_value);

protected:

	std::shared_ptr<Point> _currentVal;

	std::mutex _calcMutex;

	std::condition_variable _calcCondVar, _resCondVar, _logCondVar;

	Logger _logger;

	bool _done;

	long _currentArgumentVal, _currentFuncVal;

	virtual void calculateFunction(long input_value) = 0;

	void resultFunction();
	void logFunction();
};

