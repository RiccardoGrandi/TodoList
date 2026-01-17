# 📝 ToDoList in C++

Un progetto didattico in **C++ orientato agli oggetti** che implementa una semplice **ToDo List** da console.  
L’obiettivo è mostrare i concetti di OOP, gestione di collezioni (`std::vector`) e test automatici con **GoogleTest**.

---

## ✨ Funzionalità

- ➕ **Aggiungi Task**
- ✅ **Completamento**: Segnare un'attività come completata.
- 💾 **Gestione lista con file**: Salvataggio e caricamento su file `.txt`.
- 📋 **Visualizzazione su console**: Elenco chiaro (`✓` completato / `✗` da fare).

---

## 💾 Formato File

I dati vengono salvati in un file di testo semplice.
Ogni riga inizia con un numero intero che rappresenta lo stato, seguito dal nome.
* `0` = Da fare
* `1` = Completato

**Esempio `lista_attivita.txt`:**
```text
1 Comprare il pane
0 Andare in palestra
1 Fare la spesa
```
---

## 📋 Formato console

**Esempio `console`:**

```cpp
=== TODO LIST ===
0 - Comprare il latte [✗]
1 - Studiare C++ [✓]


 1. Aggiungi task
 2. Completa una task
 3. Salva su file
 4. Carica da file
 0. Esci

Scelta: 
```
