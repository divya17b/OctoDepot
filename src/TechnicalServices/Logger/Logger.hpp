#ifndef LOGGER_HPP
#define LOGGER_HPP

class Logger {


public:
	Logger();

	void readLines(int startTime, int endTime);

	void writeLine(int line);

	void writeLines(int lines);
};

#endif
