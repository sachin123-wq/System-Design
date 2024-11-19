
#ifndef TASK_STATUS
#define TASK_STATUS

enum class TaskStatus{
    PENDING,
    INPROGRESS,
    COMPLETED
};

#endif



// // Using `enum class`
// enum class TaskStatus {
//     PENDING,
//     INPROGRESS,
//     COMPLETED
// };

// TaskStatus status = TaskStatus::PENDING; // Safe and scoped
// int val = status;                        // Error: Cannot convert directly to int

// // Using `enum`
// enum TaskState {
//     PENDING,
//     INPROGRESS,
//     COMPLETED
// };

// TaskState state = PENDING;   // Accessible without qualifying the scope
// int value = state;           // Implicitly converts to int
