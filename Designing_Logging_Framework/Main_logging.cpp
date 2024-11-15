#include <iostream>
#include "LogLevel.hpp"
#include "LogMessage.hpp"
#include "LogOutput.hpp"
#include "Logger.hpp"
#include <mutex>
#include <thread>
#include <vector>
#include <memory>
using namespace std;



void logFromThread(std::unique_ptr<Logger> logger, int threadNum){
    for(int i = 1; i <= 5; i++){
        LogMessage *LogMessage1 = new LogMessage(LogLevel::INFO, "CLI command is executed by user x.", threadNum, i);
        logger->logMessage(*LogMessage1);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate time delay
    }
}


int main(){
    // LogMessage *logMessage1 = new LogMessage(LogLevel::INFO,"CLI command executed by user x");
    // cout << logMessage1->formatMessage() << endl;
    std::mutex fileMutex;
    // LogMessage *LogMessage1 = new LogMessage(LogLevel::INFO, "CLI command is executed by user x.", 1, 1);
    // string formatted_msg = LogMessage1->formatMessage();
    // cout << formatted_msg << endl;

    // LogOutput *log_output = new FileOutput("./messages.log");
    // log_output->log(*LogMessage1);

    // log_output = new DatabaseOutput();
    // log_output->log(*LogMessage1);

    std::vector<std::thread> threads;

    // Create Console Logger
    threads.emplace_back(logFromThread, std::make_unique<Logger>(std::make_unique<ConsoleOutput>()), 1);

    // Create File Logger
    threads.emplace_back(logFromThread, std::make_unique<Logger>(std::make_unique<FileOutput>("./logs.txt")), 2);

    // Create Database Logger
    threads.emplace_back(logFromThread, std::make_unique<Logger>(std::make_unique<DatabaseOutput>()), 3);

    // Wait for all threads to finish
    for (auto& th : threads) {
        th.join();
    }

    std::cout << "All threads have completed logging." << std::endl;
    return 0;

    

}

