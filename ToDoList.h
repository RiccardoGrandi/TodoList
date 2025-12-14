//
// Created by Riccardo
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include "Task.h"

class ToDoList {
private:
    std::vector<Task> tasks; // Vettore dinamico

public:
    bool addTask(const std::string& nome);

    void completeTask(int index);
    void showTasks() const;
    int getTaskCount() const;
    // NECESSARIO PER I TEST: Restituisce una task per controllarla
    Task getTask(int index) const;

    bool taskExists(const std::string& name) const;

    // Salva e Carica (solo TXT)
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};


#endif //TODOLIST_TODOLIST_H