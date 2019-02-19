#include "FileReader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileReader(const std::string & path)
{
	std::ifstream inFile(path);

	if (!inFile.is_open())
	{
		throw std::runtime_error("Unable to open file: " + path);
	}

	std::stringstream stream;

	stream << inFile.rdbuf();
	return stream.str();
}
