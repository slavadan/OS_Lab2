#include "Logger.h"

void Logger::log(const std::string& log_value)
{
	_fileStream.open(_logFileName, std::ios_base::out | std::ios_base::app);
	
	_fileStream << log_value << "\n";

	time_t now = time(0);
	std::string recordTime = ctime(&now);

	_fileStream << "Record Time: " << recordTime << "\n";
	
	_fileStream.close();
}

void Logger::logResult(const std::string& log_value)
{

	_fileStream.open(_resFileName, std::ios_base::out | std::ios_base::app);
	
	_fileStream << log_value << "\n";

	_fileStream.close();

}
