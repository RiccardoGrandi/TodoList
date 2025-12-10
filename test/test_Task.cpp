//
// Created by Riccardo
//

#include <gtest/gtest.h>
#include "./Task.h"
#include "./ToDoList.h"

// Verifica che una task appena creata non sia completata
TEST(TaskTest, TaskStartNotCompleted) {
    Task t("Comprare il pane");
    EXPECT_FALSE(t.isCompleted()); // Mi aspetto FALSE
}

// Verifica che il nome venga salvato correttamente
TEST(TaskTest, GetNameReturnCorrectName) {
    Task t("Leggere un libro");
    EXPECT_EQ(t.getName(), "Leggere un libro"); // Mi aspetto che le stringhe siano uguali
}

// Verifica che markCompleted funzioni
TEST(TaskTest, MarkCompletedSetsFlagTrue) {
    Task t("Fare la spesa");
    t.markCompleted();
    EXPECT_TRUE(t.isCompleted()); // Ora mi aspetto TRUE
}

