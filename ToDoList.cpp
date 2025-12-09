//
// Created by Riccardo
//

#include "ToDoList.h"
#include <iostream>
#include <fstream> // Libreria per i file


void ToDoList::addTask(const std::string& desc, bool isCompleted) {
    Task t(desc);
    if (isCompleted) t.markCompleted();
    tasks.push_back(t);
}

void ToDoList::completeTask(int index) {
    if (index >= 0 && index < tasks.size())
        tasks[index].markCompleted();
}

void ToDoList::showTasks() const {
    if (tasks.empty()) {
        std::cout << "Lista vuota.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++)
        std::cout << i << " - " << tasks[i].getName() << " [" << (tasks[i].isCompleted() ? "✓" : "✗") << "]" << std::endl;
}

int ToDoList::getTaskCount() const {
    return tasks.size();
}

Task ToDoList::getTask(int index) const {
    // .at() lancia un'eccezione se l'indice è sbagliato, ottimo per i test
    return tasks.at(index);
}

bool ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open())
        return false;

    for (const auto& task : tasks) {
        // Scrivo: 1 NomeTask
        file << (task.isCompleted() ?  1 : 0) << " " << task.getName() << std::endl;
    }
    file.close();
    return true;
}

bool ToDoList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        return false;

    tasks.clear(); // Resetto la lista
    int status;
    std::string name;

    // Leggo: Intero -> ignoro spazio -> Leggo resto riga
    while (file >> status) {
        file.ignore();
        std::getline(file, name);
        addTask(name, (status == 1));
    }
    file.close();
    return true;
}

