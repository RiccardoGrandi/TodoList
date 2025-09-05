#include <iostream>
#include <limits>        // per numeric_limits
#include <string>
#include "ToDoList.h"
using namespace std;

int main() {
    ToDoList list;
    int scelta;

    do {
        cout << "\n--- TODO LIST ---\n";
        list.showTasks();
        cout << "\n 1. Aggiungi task\n";
        cout << " 2. Completa una task\n";
        cout << " 3. Esci\n";
        cout << "\nScelta: ";

        // ===== Controllo input menu =====
        if (!(cin >> scelta)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            scelta = 0; // valore non valido
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // scarta eventuale newline rimasto

        switch(scelta) {
            case 1: {
                string nome;
                cout << "Inserisci nome task: ";
                getline(cin, nome);  // permette spazi
                if (!nome.empty()) {
                    list.addTask(nome);
                } else {
                    cout << "Nome task non valido!\n";
                }
                break;
            }

            case 2: {
                int index;
                cout << "Inserisci index task: ";
                if (!(cin >> index)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input non valido!\n";
                    break;
                }
                if (index < 0 || index >= list.getTaskCount()) {
                    cout << "Index fuori range!\n";
                } else {
                    list.completeTask(index);
                    cout << "Task completata!\n";
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // scarta newline
                break;
            }

            case 3:
                cout << "Uscita...\n";
                break;

            default:
                cout << "Scelta non valida, riprova.\n";
                break;
        }

    } while (scelta != 3);

    return 0;
}
