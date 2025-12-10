//
// Created by Riccardo
//

#include <gtest/gtest.h>
#include "Task.h"
#include "ToDoList.h"
#include <cstdio> // Serve per rimuovere il file temporaneo (std::remove)

// Test lista vuota
TEST(ToDoListTest, StartsEmpty) {
    ToDoList list;
    EXPECT_EQ(list.getTaskCount(), 0);
}

// Test aggiunta file
TEST(ToDoListTest, AddTaskIncreasesCount) {
    ToDoList list;
    list.addTask("Pagare bollette");
    EXPECT_EQ(list.getTaskCount(), 1);
}

// Verifica che il nome venga salvato correttamente
TEST(ToDoListTest, AddedTaskHasCorrectName) {
    ToDoList list;
    list.addTask("Andare dal dottore");
    EXPECT_EQ(list.getTask(0).getName(), "Andare dal dottore");
}

// Verifica che una task sia segnata come completata
TEST(ToDoListTest, CompleteTaskMarksItCompleted) {
    ToDoList list;
    list.addTask("Fare sport");
    list.completeTask(0);
    EXPECT_TRUE(list.getTask(0).isCompleted());
}

// Test per vedere come si comporta il programma se chiedo di completare una task con indice fuori dal range
TEST(ToDoListTest, CompleteTaskOutOfBoundsDoesNothing) {
    ToDoList list;
    list.addTask("Andare al mare");
    list.completeTask(5); // indice non valido
    EXPECT_FALSE(list.getTask(0).isCompleted());
}

// Test per vedere come si comporta il programma se chiedo di stampare una task con indice fuori dal range
TEST(ToDoListTest, GetTaskThrowsWhenOutOfBounds) {
    ToDoList list;
    list.addTask("Provare eccezione");
    // Mi aspetto che venga lanciata un'eccezione
    EXPECT_THROW(list.getTask(10), std::out_of_range);
}

// Verifica che aggiungendo più task il programma funzioni correttamente
TEST(ToDoListTest, MultipleTasksAdded) {
    ToDoList list;
    list.addTask("Task1");
    list.addTask("Task2");
    list.addTask("Task3");
    EXPECT_EQ(list.getTaskCount(), 3);
    EXPECT_EQ(list.getTask(1).getName(), "Task2");
    EXPECT_FALSE(list.getTask(2).isCompleted());
}

// Verifica che la funzione showTask non crash mentre stampa o non vada in loop
TEST(ToDoListTest, ShowTasksRunsWithoutCrash) {
    ToDoList list;
    list.addTask("Test output");
    // Non verifica l'output ma solo che non crashi
    EXPECT_NO_THROW(list.showTasks());
}

// Salva su file, ricarica in una nuova lista e controlla i dati
TEST(ToDoListTest, SaveAndLoadFileWorkCorrectly) {
    ToDoList listOut;
    listOut.addTask("Task Completata", true); // Task già fatta (1)
    listOut.addTask("Task Da Fare", false);   // Task da fare (0)

    std::string filename = "test_save_load.txt";
    ASSERT_TRUE(listOut.saveToFile(filename)); // Salvo su file

    ToDoList listIn;
    ASSERT_TRUE(listIn.loadFromFile(filename)); // Carico lista da file
    EXPECT_EQ(listIn.getTaskCount(), 2); // Verifico che gli elementi siano 2

    // Controllo la prima task
    EXPECT_EQ(listIn.getTask(0).getName(), "Task Completata");
    EXPECT_TRUE(listIn.getTask(0).isCompleted());

    // Controllo la seconda task
    EXPECT_EQ(listIn.getTask(1).getName(), "Task Da Fare");
    EXPECT_FALSE(listIn.getTask(1).isCompleted());

    // Elimino il file creato
    std::remove(filename.c_str());
}

// Test caricamento file inesistente
TEST(ToDoListTest, LoadNonExistentFileReturnsFalse) {
    ToDoList list;
    bool result = list.loadFromFile("file_fantasma_inesistente.txt");
    EXPECT_FALSE(result);
}

// Test inserimento task caricata da file in coda alla lista in memoria
TEST(ToDoListTest, LoadAppendsTasksToExistingList) {
    std::string filename = "test_merge.txt";

    ToDoList listFile;
    listFile.addTask("Task Nel File");
    listFile.saveToFile(filename);

    ToDoList listMemory;
    listMemory.addTask("Task In Memoria");


    listMemory.loadFromFile(filename);

    // Mi aspetto di avere 2 task (quella in memoria + quella caricata)
    EXPECT_EQ(listMemory.getTaskCount(), 2);

    // Controllo che ci siano entrambe
    EXPECT_EQ(listMemory.getTask(0).getName(), "Task In Memoria");
    EXPECT_EQ(listMemory.getTask(1).getName(), "Task Nel File");   // È quella che è stata aggiunta

    // Pulizia
    std::remove(filename.c_str());
}

TEST(ToDoListTest, LoadAvoidsDuplicates) {
    std::string filename = "test_duplicates.txt";

    ToDoList listFile;
    listFile.addTask("Studiare");
    listFile.saveToFile(filename);


    ToDoList listMemory;
    listMemory.addTask("Studiare"); // Già presente
    listMemory.addTask("Mangiare"); // Altra task

    listMemory.loadFromFile(filename);

    // Mi aspetto 2 task totali ("Studiare" e "Mangiare"), NON 3.
    // "Studiare" non deve essere stata duplicata.
    EXPECT_EQ(listMemory.getTaskCount(), 2);

    // Verifico i nomi per sicurezza
    EXPECT_EQ(listMemory.getTask(0).getName(), "Studiare");
    EXPECT_EQ(listMemory.getTask(1).getName(), "Mangiare");

    // Pulizia
    std::remove(filename.c_str());
}
