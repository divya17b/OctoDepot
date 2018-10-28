#ifndef LOGGER_HPP
#define LOGGER_HPP

class Logger {

private:
	std::ofstream logWrite;
	std::ifstream logRead;
	std::string logFileLocation;
	std::vector<std::string> read_buffer;

	void openLogFileAsReading();
	void openLogFileAsWriting();
	void closeLog();

	std::string serialize(std::string timestamp, std::string type, int userid, std::string msg);

public:
	// std::string serialize(std::string timestamp, std::string type, int userid, std::string msg);

	Logger(std::string LogFile);
	int log(std::string timestamp, std::string type, int userid, std::string msg);
	std::vector<std::string> readLines();
	int writeLine(std::string line);
	int writeLines(std::vector<std::string> &lines);
};

#endif
