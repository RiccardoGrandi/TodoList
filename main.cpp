//
// Created by Riccardo
//

#include <iostream>
#include <limits>        // per numeric_limits e per pulire il buffer (cin.ignore)
#include <string>
#include "ToDoList.h"
using namespace std;

int main() {
    ToDoList list;
    int scelta;
    string filename = "lista_attivita.txt"; // Nome fisso del file
    do {
        cout << "\n--- TODO LIST ---\n";
        list.showTasks();
        cout << "\n 1. Aggiungi task\n";
        cout << " 2. Completa una task\n";
        cout << " 3. Salva (su " << filename << ")\n";
        cout << " 4. Carica (da " << filename << ")\n";
        cout << " 0. Esci\n";
        cout << "\nScelta: ";

        // Controllo se l'utente inserisce lettere invece di numeri)
        if (!(cin >> scelta)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Svuota buffer
            scelta = -1; // valore non valido
        }
        else
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // scarta eventuale newline (invio) rimasto

        switch(scelta) {
            case 1: {
                string nome;
                cout << "Inserisci nome task: ";
                getline(cin, nome);  // permette spazi
                    if (!nome.empty()) {
                        if (list.addTask(nome)) {
                            cout << "Task aggiunta con successo!\n";
                        } else {
                            cout << "ERRORE: La task '" << nome << "' esiste gia'!\n";
                        }
                    } else {
                        cout << "Nome task non valido!\n";
                    }
                break;
            }

            case 2: {
                if (list.getTaskCount() == 0) {
                    cout << "La lista e' vuota\n";
                }
                else {
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
                }
                break;
            }

            case 3: {
                if (list.getTaskCount() != 0) {
                    if (list.saveToFile(filename))
                        cout << "Salvaggio completato!\n";
                    else
                        cout << "Errore durante il salvataggio\n";
                }
                else
                    cout << "Non puoi salvare, la lista è vuota!\n";
                break;
            }

            case 4: {
                if (list.loadFromFile(filename))
                    cout << "Lista caricata correttamente da " << filename << "\n";
                else
                    cout << "Errore durante il caricamento\n";
                break;
            }

            case 0:
                cout << "Uscita...\n";
                break;

            default:
                cout << "Scelta non valida, riprova.\n";
                break;
        }

    } while (scelta != 0);

    return 0;
}
