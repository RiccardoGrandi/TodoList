cmake_minimum_required(VERSION 3.28)
project(TodoList)

set(CMAKE_CXX_STANDARD 20)

# ======================
# Eseguibile principale
# ======================
add_executable(TodoList
        main.cpp
        Task.cpp
        ToDoList.cpp
)

# ======================
# GoogleTest (fetch automatico)
# ======================
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)

set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest" FORCE)
set(INSTALL_GMOCK OFF CACHE BOOL "Disable installation of googlemock" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# ======================
# Eseguibile dei test
# ======================
add_executable(todolist_tests
        test/test_ToDoList.cpp   # file dei test
        test/test_Task.cpp
        Task.cpp
        ToDoList.cpp
)

target_include_directories(todolist_tests
        PRIVATE ${CMAKE_SOURCE_DIR}
)

target_link_libraries(todolist_tests
        gtest
        gtest_main
        pthread
)

add_test(NAME ToDoListTests COMMAND todolist_tests)