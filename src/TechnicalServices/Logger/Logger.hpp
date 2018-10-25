#ifndef LOGGER_HPP
#define LOGGER_HPP

class Logger {

private:
	std::ofstream Log;
	std::vector<std::string> read_buffer;
public:
	Logger(std::string LogFile);
	std::vector<std::string> readLines(float startTime, float endTime);
	int writeLine(std::string line);
	int writeLines(std::vector<std::string> lines);
};

#endif
