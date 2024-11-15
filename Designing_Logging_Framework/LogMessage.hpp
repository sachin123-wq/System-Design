#ifndef LOGMESSAGE
#define LOGMESSAGE

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

enum class LogLevel;

class LogMessage {
private:
	std::chrono::system_clock::time_point timestamp;
    LogLevel logLevel;
    std::string content;

public:
    LogMessage(LogLevel level, const std::string& message)
        : logLevel(level), content(message) {
        timestamp = std::chrono::system_clock::now();
    }

    std::string formatMessage() const {
        std::stringstream ss;
        auto now = std::chrono::system_clock::to_time_t(timestamp);
        ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S")
           << " [" << getLogLevelString() << "] " << content;
        return ss.str();
    }

    std::string getLogLevelString() const {
        switch (logLevel) {
            case LogLevel::DEBUG: return "DEBUG";
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR: return "ERROR";
            case LogLevel::FATAL: return "FATAL";
            default: return "UNKNOWN";
        }
    }
};



#endif // LOGMESSAGE