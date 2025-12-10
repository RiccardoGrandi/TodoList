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

    // Metodo privato di utilità: controlla se un nome esiste già
    bool taskExists(const std::string& name) const;
public:
    // Aggiunge task (con stato opzionale, default = false)
    void addTask(const std::string& desc, bool isCompleted = false);

    void completeTask(int index);
    void showTasks() const;
    int getTaskCount() const;
    // NECESSARIO PER I TEST: Restituisce una task per controllarla
    Task getTask(int index) const;

    // Salva e Carica (solo TXT)
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};


#endif //TODOLIST_TODOLIST_H