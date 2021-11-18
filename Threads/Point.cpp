#include "Point.h"

std::string Point::formatLogVal()
{
	std::string record = "Init time: " +
		_initTime + "\n" + std::to_string(_data) + "\n";

	makeDeletable();

	return record;
}
