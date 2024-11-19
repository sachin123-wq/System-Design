#include<string>
#include<iostream>
// Include all required header file
#include "TaskManager.hpp"

TaskManager* TaskManager::instance = nullptr;
std::mutex TaskManager::instanceMutex;

int main(){
    TaskManager *taskManager = TaskManager::getInstance();
    User user1("12","Rohan Sharma","rohansharma321@gmil.com");
    User user2("13","Mohan Sharma","mohansharma654@gmil.com");
    auto task1 = std::make_shared<Task>("Task-id-1",
                                        "Implement Low Level Design for Task Management System.",
                                        "As part of this we will write code and will create flow diagram for the same.",
                                        std::chrono::system_clock::now(),
                                        1,
                                        user1);
    
    auto task2 = std::make_shared<Task>("Task-id-2",
                                        "Implement High Level Design for Task Management System.",
                                        "As part of this you will create flow diagram for the same.",
                                        std::chrono::system_clock::now(),
                                        2,
                                        user2);

    taskManager->createTask(task1);
    taskManager->createTask(task2);
    auto tasks = taskManager->searchTasks("Low Level Design");
    auto tasks1 = taskManager->searchTasks("High");
    for(const auto&t : tasks){
        std::cout << "Found Task: " << t->getId() << std::endl;
    }
    for(const auto&t : tasks1){
        std::cout << "Found Task: " << t->getId() << std::endl;
    }
    return 0;
}


// To run the program
// g++ -w -std=c++17 TaskManagementSystemDemo.cpp -o TaskManagementSystemDemo