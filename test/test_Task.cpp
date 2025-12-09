//
// Created by Riccardo
//

#include <gtest/gtest.h>
#include "./Task.h"
#include "./ToDoList.h"

TEST(TaskTest, TaskStartNotCompleted) {
    Task t("Comprare il latte");
    EXPECT_FALSE(t.isCompleted());
}

TEST(TaskTest, GetNameReturnCorrectName) {
    Task t("Leggere un libro");
    EXPECT_EQ(t.getName(), "Leggere un libro");
}

TEST(TaskTest, MarkCompletedSetsFlagTrue) {
    Task t("Fare la spesa");
    t.markCompleted();
    EXPECT_TRUE(t.isCompleted());
}

