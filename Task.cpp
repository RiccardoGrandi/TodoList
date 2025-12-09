//
// Created by Riccardo
//

#include "Task.h"

Task::Task(std::string n) : name(n), completed(false) {}

bool Task::isCompleted() const {
    return completed;
}

std::string Task::getName() const {
    return name;
}

void Task::markCompleted() {
    completed = true;
}

