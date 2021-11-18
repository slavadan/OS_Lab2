#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>

class Logger
{
public:

	Logger() 
	{

	};

	void log(const std::string& log_value);
	void logResult(const std::string& log_value);

	~Logger() {};

private:

	std::string _logFileName = "log";
	std::string _resFileName = "result";

	std::fstream _fileStream;
};

