//
// Created by Riccardo
//

#include "ToDoList.h"
#include <iostream>
#include <fstream> // Libreria per i file


bool ToDoList::addTask(const std::string& nome, bool isCompleted) {
    if (taskExists(nome))
        return false;

    Task t(nome);
    if (isCompleted)
        t.markCompleted();
    tasks.push_back(t);
    return true;
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
    return tasks.at(index);
}

// Salvataggio
bool ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open())
        return false;

    for (const auto& task : tasks) {
        // Scrivo 1 se completata, 0 se da fare
        file << (task.isCompleted() ?  1 : 0) << " " << task.getName() << std::endl;
    }
    file.close();
    return true;
}

bool ToDoList::taskExists(const std::string& name) const {
    for (const auto& task : tasks) {
        if (task.getName() == name) {
            return true; // Trovato un duplicato!
        }
    }
    return false; // Nessun duplicato trovato
}

// Caricamento
bool ToDoList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        return false;

    int status;
    std::string name;

    // Leggo: intero (stato della task) -> ignoro spazio -> leggo resto riga
    while (file >> status) {
        file.ignore(); // Salta lo spazio vuoto dopo il numero
        std::getline(file, name); // Legge tutto il resto della riga
        addTask(name, (status == 1));
    }
    file.close();
    return true;
}

