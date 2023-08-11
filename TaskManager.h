#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <vector>
#include "Task.h"

class TaskManager {
public:
    TaskManager();
    void createTask(const std::string& name, const std::string& description, int priority);
    void displayTasks();
    bool markTaskAsCompleted(int index);
    void saveTasksToFile(const std::string& filename);
    void loadTasksFromFile(const std::string& filename);

private:
    std::vector<Task> tasks;
};

#endif // TASKMANAGER_H
