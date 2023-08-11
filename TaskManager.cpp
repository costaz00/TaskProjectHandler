#include "TaskManager.h"
#include <fstream>

TaskManager::TaskManager() {}

void TaskManager::createTask(const std::string& name, const std::string& description, int priority) {
    Task task(name, description, priority);
    tasks.push_back(task);
}

void TaskManager::displayTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
    } else {
        std::cout << "Task List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "Index: " << i << std::endl;
            std::cout << "Name: " << tasks[i].getName() << std::endl;
            std::cout << "Description: " << tasks[i].getDescription() << std::endl;
            std::cout << "Priority: " << tasks[i].getPriority() << std::endl;
            std::cout << "Status: " << (tasks[i].isCompleted() ? "Completed" : "Incomplete") << std::endl;
            std::cout << std::endl;
        }
    }
}

bool TaskManager::markTaskAsCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].setCompleted(true);
        return true;
    }
    return false;
}

void TaskManager::saveTasksToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Task& task : tasks) {
            file << task.getName() << "\n";
            file << task.getDescription() << "\n";
            file << task.getPriority() << "\n";
            file << task.isCompleted() << "\n";
        }
        file.close();
    } else {
        std::cout << "Error opening the file." << std::endl;
    }
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        tasks.clear();
        std::string name, description, priorityStr, completedStr;
        int priority;
        bool completed;

        while (std::getline(file, name) && std::getline(file, description) &&
               std::getline(file, priorityStr) && std::getline(file, completedStr)) {
            priority = std::stoi(priorityStr);
            completed = (completedStr == "1");
            Task task(name, description, priority, completed);
            tasks.push_back(task);
        }

        file.close();
    } else {
        std::cout << "Error opening the file." << std::endl;
    }
}
