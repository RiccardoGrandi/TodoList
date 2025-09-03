//
// Created by Riccardo on 03/09/2025.
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

