//
// Created by Riccardo on 03/09/2025.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <string>

class Task {
private:
    std::string name;
    bool completed;

public:
    Task(std::string name);
    std::string getName() const;
    bool isCompleted() const;
    void markCompleted();
};


#endif //TODOLIST_TASK_H