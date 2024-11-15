#ifndef LOGGER
#define LOGGER

#include <memory>
#include "LogOutput.hpp"

class Logger{
    private:
    std::unique_ptr<LogOutput> output;

    public:
    Logger(std::unique_ptr<LogOutput> logOutput) : output(std::move(logOutput)){}
    void logMessage(const LogMessage& message){
        output->log(message);
    }
};

#endif