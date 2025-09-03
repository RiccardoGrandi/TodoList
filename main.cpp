#include <iostream>
#include "ToDoList.h"
using namespace std;

int main() {
    ToDoList list;
    int scelta;

    do {
        cout << "\n--- TODO LIST ---\n";
        list.showTasks();
        cout << "\n 1. Aggiungi task\n";
        cout << "\n 2. Completa una task\n";
        cout << "\n 3. Esci\n";
        cout << "\n\n Scelta: ";
        cin >> scelta;

        if (scelta == 1) {
            std::string nome;
            cout << "Inserisci nome task";
            cin >> nome;
            list.addTask(nome);
        } else if (scelta == 2) {
            int index;
            cout << "Inserisci index task";
            cin >> index;
            list.completeTask(index);
        }
    } while (scelta !=3);

    return 0;
}
