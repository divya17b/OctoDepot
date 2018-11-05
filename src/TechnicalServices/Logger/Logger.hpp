#ifndef LOGGER_HPP
#define LOGGER_HPP

// this is the interface class of access to the log file
class Logger {

private:
	// opened log file as write mode
	std::ofstream logWrite;
	// opened log file as read mode
	std::ifstream logRead;
	// location of the log file
	std::string logFileLocation;
	// store read lines from log file
	std::vector<std::string> read_buffer;

	// open log file as reading
	void openLogFileAsReading();
	// open log file as writing
	void openLogFileAsWriting();
	// close the file
	void closeLog();

	// serialize information into one line
	std::string serialize(std::string timestamp, std::string type, int userid, std::string msg);
	// get current timestamp
	std::string getTimestamp();

public:
	// std::string serialize(std::string timestamp, std::string type, int userid, std::string msg);

	Logger(std::string LogFile);
	// take information, serialize, then write one line into log file
	int log(std::string type, int userid, std::string msg);
	// read the log file into buffer
	std::vector<std::string> readLines();
	// write 1 prepared line
	int writeLine(std::string line);
	// write many prepared lines, not used
	int writeLines(std::vector<std::string> &lines);
};

#endif
