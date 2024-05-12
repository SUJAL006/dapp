#include <iostream>
#include <vector>
#include <string>


struct Task {
    std::string description;
    bool completed;
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back({description, false});
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void displayAllTasks() {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << i << "] ";
            if (tasks[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;


        std::cout << "Options:\n"
                     "1. Add Task\n"
                     "2. Mark Task as Completed\n"
                     "3. Delete Task\n"
                     "4. View All Tasks\n"
                     "5. Exit\n"
                     "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter task description: ";
            std::string description;
            std::cin.ignore();
            std::getline(std::cin, description);
            taskManager.addTask(description);
        } else if (choice == 2) {
            std::cout << "Enter task index: ";
            int index;
            std::cin >> index;
            taskManager.markTaskCompleted(index);
        } else if (choice == 3) {
            std::cout << "Enter task index: ";
            int index;
            std::cin >> index;
            taskManager.deleteTask(index);
        } else if (choice == 4) {
            taskManager.displayAllTasks();
        } else if (choice == 5) {
            
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }



