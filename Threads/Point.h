#pragma once
#include <string>
#include <iostream>


class Point
{
public:

	Point(long input_data, std::string init_time):
	_data(input_data), _initTime(init_time), _deletable(false)
	{};

	~Point() 
	{
		if (!_deletable)
			std::cout << "Point didnt log" << std::endl;
	};

	std::string formatLogVal();

private:

	long _data;

	bool _deletable;

	std::string _initTime;

	void makeDeletable() { this->_deletable = true; }

};

