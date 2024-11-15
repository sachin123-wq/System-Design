// LogOutput.hpp

#ifndef LOGOUTPUT_HPP
#define LOGOUTPUT_HPP

#include <iostream>
#include <fstream>
#include <mutex>
#include "LogMessage.hpp"

enum class LogLevel;
class LogMessage;


class LogOutput {
public:
    virtual void log(const LogMessage& message) = 0;
    virtual ~LogOutput() {}
};

class ConsoleOutput : public LogOutput {
public:
    void log(const LogMessage& message) override {
        std::cout << message.formatMessage() << std::endl;
    }
};

class FileOutput : public LogOutput {
private:
    std::ofstream outFile;
    // std::mutex fileMutex;

public:
    FileOutput(const std::string& fileName) {
        outFile.open(fileName, std::ios::app);
        if (!outFile.is_open()) {
            throw std::runtime_error("Unable to open log file");
        }
    }

    void log(const LogMessage& message) override {
        // std::lock_guard<std::mutex> lock(fileMutex);
        outFile << message.formatMessage() << std::endl;
    }

    ~FileOutput() {
        if (outFile.is_open()) {
            outFile.close();
        }
    }
};

class DatabaseOutput : public LogOutput {
public:
    void log(const LogMessage& message) override {
        // Assume this method connects to a database and logs the message
        // Placeholder implementation
        std::cout << "Logging to database: " << message.formatMessage() << std::endl;
    }
};



#endif // LOGOUTPUT_HPP