#include "Function.h"

int Function::calculate(long input_value)
{

	std::thread calcThread(&Function::calculateFunction, this, input_value);
	std::thread resThread(&Function::resultFunction, this);
	std::thread logThread(&Function::logFunction, this);
	
	calcThread.join();
	resThread.join();
	logThread.join();
	
	return 0;
}

void Function::resultFunction()
{
	std::unique_lock<std::mutex> lock(_calcMutex);


	while (!_done)
	{
		
		_logger.logResult(std::to_string(this->_currentFuncVal));

		_resCondVar.notify_all();
		_calcCondVar.wait(lock);
	}

	_resCondVar.notify_all();
}

void Function::logFunction()
{

	std::unique_lock<std::mutex> lock(_calcMutex);

	while (!_done)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));

		_logger.log(_currentVal->formatLogVal());

		_logCondVar.notify_all();
		_resCondVar.wait(lock);
	}

}
