#ifndef TASK
#define TASK

#include <string>
#include <chrono>

#include "TaskStatus.hpp"
#include "User.hpp"

class Task{
private:
    const std::string id;
    std::string title;
    std::string description;
    std::chrono::system_clock::time_point dueDate;
    int priority;
    TaskStatus status;
    const User assignedUser;

public:
// Constructor
    Task(const std::string& id, const std::string& title, const std::string& description,
        std::chrono::system_clock::time_point taskDueDate, int priority, const User assignedUser)
        : id(id), title(title), description(description), dueDate(taskDueDate),
        priority(priority), status(TaskStatus::PENDING), assignedUser(assignedUser) {}

    // Getter for id (since it's immutable)
    const std::string& getId() const {
        return id;
    }

    // Getter and Setter for title
    const std::string& getTitle() const {
        return title;
    }

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    // Getter and Setter for description
    const std::string& getDescription() const {
        return description;
    }

    void setDescription(const std::string& newDescription) {
        description = newDescription;
    }

    // Getter and Setter for dueDate
    std::chrono::system_clock::time_point getDueDate() const { return dueDate; }

    void setDueDate(std::chrono::system_clock::time_point newDueDate) {
        dueDate = newDueDate;
    }

    // Getter and Setter for priority
    int getPriority() const {
        return priority;
    }

    void setPriority(int newPriority) {
        priority = newPriority;
    }

    // Getter and Setter for status
    TaskStatus getStatus() const {
        return status;
    }

    void setStatus(TaskStatus newStatus) {
        status = newStatus;
    }

    // Getter for assignedUser (since it's immutable)
    const User getAssignedUser() const {
        return assignedUser;
    }
};

#endif