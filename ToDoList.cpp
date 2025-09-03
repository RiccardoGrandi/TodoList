//
// Created by alber on 03/09/2025.
//

#include "ToDoList.h"

#include <iostream>
#include <ostream>

void ToDoList::addTask(const std::string& desc) {
    tasks.emplace_back(desc);
}

void ToDoList::completeTask(int index) {
    if (index >= 0 && index < tasks.size())
        tasks[index].markCompleted();
}

void ToDoList::showTasks() const {
    for (int i = 0; i < tasks.size(); i++)
        std::cout << i << " - " << tasks[i].getName() << " [" << (tasks[i].isCompleted() ? "✓" : "✗") << "]" << std::endl;
}

int ToDoList::getTaskCount() const {
    return tasks.size();
}

Task ToDoList::getTask(int index) const {
    return tasks.at(index);
}
