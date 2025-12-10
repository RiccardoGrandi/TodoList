//
// Created by Riccardo
//

#include <gtest/gtest.h>
#include "Task.h"
#include "ToDoList.h"

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

// Verifica che una task si segnata come completata
TEST(ToDoListTest, CompleteTaskMarksItCompleted) {
    ToDoList list;
    list.addTask("Fare sport");
    list.completeTask(0);
    EXPECT_TRUE(list.getTask(0).isCompleted());
}

// Test per vedere come si comporta il porgramma se chiedo di completare una task con indice fuori dal range
TEST(ToDoListTest, CompleteTaskOutOfBoundsDoesNothing) {
    ToDoList list;
    list.addTask("Andare al m");
    list.completeTask(5); // indice non valido
    EXPECT_FALSE(list.getTask(0).isCompleted());
}

// Test per vedere come si comporta il porgramma se chiedo di stampare una task con indice fuori dal range
TEST(ToDoListTest, GetTaskThrowsWhenOutOfBounds) {
    ToDoList list;
    list.addTask("Provare eccezione");
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


