#include <iostream>
#include "LogLevel.hpp"
#include "LogMessage.hpp"
#include "LogOutput.hpp"
#include <mutex>
using namespace std;


int main(){
    // LogMessage *logMessage1 = new LogMessage(LogLevel::INFO,"CLI command executed by user x");
    // cout << logMessage1->formatMessage() << endl;
    std::mutex fileMutex;
    LogMessage *LogMessage1 = new LogMessage(LogLevel::INFO, "CLI command is executed by user x.");
    

}

