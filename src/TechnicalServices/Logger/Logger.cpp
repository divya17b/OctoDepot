#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Logger.hpp"

Logger::Logger(std::string LogFileLocation) {
	// TODO - implement Logger::Logger
	logFileLocation = LogFileLocation;
}

void Logger::openLogFileAsReading() {
	logRead.open(logFileLocation);
}
void Logger::openLogFileAsWriting() {
	logWrite.open(logFileLocation, std::ofstream::app);
}

void Logger::closeLog() {
	if (logWrite)
		logWrite.close();
	if (logRead)
		logRead.close();
}

std::string Logger::serialize(std::string timestamp, std::string type, int userid, std::string msg) {
	std::string line = "[";

	line += timestamp;

	line += "|";

	line += type;

	line += "|";

	line += std::to_string(userid);

	line += "] ";
	line += msg;

	// std::cout << line << std::endl;

	return line;
}

// this is the actual part other models should call and use
// this will serialize params into a string and write into the file
// 1. call serialize
// 2. call write line
int Logger::log(std::string timestamp, std::string type, int userid, std::string msg) {
	std::string line = this->serialize(timestamp, type, userid, msg);
	// std::cout << line << std::endl;
	if (logRead)
		this->closeLog();
	if (!logWrite)
		this->openLogFileAsWriting();
	// std::cout << line << std::endl;
	this->logWrite << line << std::endl;
	return 1;
}

std::vector<std::string> Logger::readLines() {
	// 1. check the log file is opened is write mode or not
	// 2. if so, close and reopen it as read mode
	std::vector<std::string> result;
	if (logWrite)
		this->closeLog();
	if (!logRead)
		this->openLogFileAsReading();

	std::string lineBuffer;
	while (std::getline(logRead, lineBuffer))
		result.push_back(lineBuffer);

	return result;
}

int Logger::writeLine(std::string line) {
	// 1. check the log file is opened is read mode or not
	// 2. if so, close and reopen it as write mode
	// if the line to be written into the file is not empty we do write
	if (!line.empty()) {
		if (logRead)
			this->closeLog();
		if (!logWrite)
			this->openLogFileAsWriting();
		std::cout << line << std::endl;
		this->logWrite << line << std::endl;
		return 1;
	}
	// if the line is empty, we don't write into the file
	return 0;
}

int Logger::writeLines(std::vector<std::string> &lines) {
	// TODO - implement Logger::writeLines
	int linesWritten = 0;
	for (auto i : lines) {
		linesWritten += this->writeLine(i);
	}
	return linesWritten;
}
