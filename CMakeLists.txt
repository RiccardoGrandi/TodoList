cmake_minimum_required(VERSION 3.28)
project(TodoList)

set(CMAKE_CXX_STANDARD 20)

add_executable(TodoList
        main.cpp
        Task.cpp
        ToDoList.cpp
)

