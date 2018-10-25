#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Logger.hpp"

Logger::Logger(std::string LogFile) {
	// TODO - implement Logger::Logger
	Log.open(LogFile, std::ios_base::app);
}

std::vector<std::string> Logger::readLines(float startTime, float endTime) {
	// TODO - implement Logger::readLines
	throw "Not yet implemented";
}

int Logger::writeLine(std::string line) {
	// TODO - implement Logger::writeLine
	Log << line << std::endl;
	return 1;
}

int Logger::writeLines(std::vector<std::string> lines) {
	// TODO - implement Logger::writeLines
	int linesWritten = 0;
	for (auto i : lines) {
		linesWritten += this->writeLine(i);
	}
	return linesWritten;
}
