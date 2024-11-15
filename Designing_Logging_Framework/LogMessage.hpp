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
    int threadNum;
    int logMessageNo;
public:
    LogMessage(LogLevel level, const std::string& message, int th_no, int log_msg_no)
        : logLevel(level), content(message) , threadNum(th_no), logMessageNo(log_msg_no) {
        timestamp = std::chrono::system_clock::now();
    }

    std::string formatMessage() const {
        std::stringstream ss;
        std::string s1 = "Thread " + std::to_string(threadNum) + " - Log message " + std::to_string(logMessageNo);
        auto now = std::chrono::system_clock::to_time_t(timestamp);
        ss << s1 << " <=> ";
        ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S")
           << " [" << getLogLevelString() << "] " << content;
        return ss.str();
    }

    std::string getLogLevelString() const{
        switch (static_cast<int>(logLevel)) {  // Cast LogLevel to int
            case static_cast<int>(LogLevel::DEBUG): return "DEBUG";
            case static_cast<int>(LogLevel::INFO): return "INFO";
            case static_cast<int>(LogLevel::WARNING): return "WARNING";
            case static_cast<int>(LogLevel::ERROR): return "ERROR";
            default: return "UNKNOWN";
        }
    }
};



#endif // LOGMESSAGE