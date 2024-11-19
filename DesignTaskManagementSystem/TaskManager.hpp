#ifndef TASK_MANAGER
#define TASK_MANAGER

#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <ctime>

#include "Task.hpp"


// TaskManager singleton class

class TaskManager{
private:
    static TaskManager *instance;
    static std::mutex instanceMutex;

    std::map<std::string, std::shared_ptr<Task>> tasks;
    std::map<std::string, std::vector<std::shared_ptr<Task>>> userTasks;
    std::shared_mutex taskMutex;

    TaskManager() {}

public:

    static TaskManager* getInstance(){
        std::lock_guard<std::mutex> lock(instanceMutex);
        if(!instance)
            instance = new TaskManager();
        return instance;
    }

    void createTask(const std::shared_ptr<Task> &task){
        std::unique_lock<std::shared_mutex> lock(taskMutex);
        tasks[task->getId()] = task;
        assignTaskToUser(task->getAssignedUser(),task);
    }

    // Updates an existing task with the details from the provided updated task.
    void updateTask(const std::shared_ptr<Task>& updatedTask){
        // Acquire a unique lock to ensure thread-safe access to the task map.
        std::unique_lock<std::shared_mutex> lock(taskMutex);

        // Find the existing task in the task map using the updated task's ID.
        auto it = tasks.find(updatedTask->getId());

        // If the task is found, proceed to update it.
        if(it != tasks.end()) {
            // Retrieve the existing task from the map.
            auto existingTask = it->second;
            // Update the title of the existing task.
            existingTask->setTitle(updatedTask->getTitle());
            // Update the description of the existing task.
            existingTask->setDescription(updatedTask->getDescription());
            // Update the due date of the existing task.
            existingTask->setDueDate(updatedTask->getDueDate());
            // Update the priority of the existing task.
            existingTask->setPriority(updatedTask->getPriority());
            // Update the status of the existing task.
            existingTask->setStatus(updatedTask->getStatus());

            // check if assigned user has changed
            if(existingTask->getAssignedUser().getId() != updatedTask->getAssignedUser().getId()){
                unassignTaskFromUser(existingTask->getAssignedUser(), existingTask);
            }
        }
    }

    // Delete the task
    void deleteTask(const std::string& taskId){
        std::unique_lock<std::shared_mutex> lock(taskMutex);
        auto it = tasks.find(taskId);
        if(it != tasks.end()){
            // Remove the entry from user specific taskslist
            unassignTaskFromUser(it->second->getAssignedUser(), it->second);
            // Remove the entry from tasks
            tasks.erase(it);
        }
    }

    // Search for the task
    std::vector<std::shared_ptr<Task>> searchTasks(const std::string& keyword){
        std::shared_lock<std::shared_mutex> lock(taskMutex);
        std::vector<std::shared_ptr<Task>> matchingTasks;

        for(const auto& pair : tasks){
            const auto& task = pair.second;
            if(task->getTitle().find(keyword) != std::string::npos || 
            task->getDescription().find(keyword) != std::string::npos){
                matchingTasks.push_back(task);
            }
        }
        return matchingTasks;
    }

    // filter task
    std::vector<std::shared_ptr<Task>> filterTasks(TaskStatus status,
                                                    std::chrono::system_clock::time_point startDate,
                                                    std::chrono::system_clock::time_point endDate,
                                                    int priority){

        std::shared_lock<std::shared_mutex> lock(taskMutex);
        std::vector<std::shared_ptr<Task>> filteredTasks;
        for(const auto& pair : tasks){
            const auto& task = pair.second;
            if( task->getStatus() == status &&
                task->getDueDate() >= startDate &&
                task->getDueDate() <= endDate &&
                task->getPriority() == priority
            ){
                filteredTasks.push_back(task);
            }
        }
        return filteredTasks;
    }

    void markTaskAsCompleted(const std::string& taskId){
        std::unique_lock<std::shared_mutex> lock(taskMutex);
        auto it = tasks.find(taskId);
        if(it != tasks.end()){
            it->second->setStatus(TaskStatus::COMPLETED);
        }
    }

    std::vector<std::shared_ptr<Task>> getTaskHistory(const User& user) {
        std::shared_lock<std::shared_mutex> lock(taskMutex);
        auto it = userTasks.find(user.getId());
        if (it != userTasks.end()) {
            return it->second;
        }
        return {};
    }

private:
    void assignTaskToUser(const User& user, const std::shared_ptr<Task>& task){
        userTasks[user.getId()].push_back(task);
    }
    void unassignTaskFromUser(const User &user, const std::shared_ptr<Task> &task){
        auto it = userTasks.find(user.getId());
        if(it != userTasks.end()){
            auto &taskList = it->second;
            taskList.erase(std::remove(taskList.begin(),taskList.end(), task));
        }
    }
};


#endif