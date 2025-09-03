//
// Created by alber on 03/09/2025.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include "Task.h"

class ToDoList {
private:
    std::vector<Task> tasks;
public:
    void addTask(const std::string& desc);
    void completeTask(int index);
    void showTasks() const;
    int getTaskCount() const;
    Task getTask(int index) const;
};


#endif //TODOLIST_TODOLIST_H