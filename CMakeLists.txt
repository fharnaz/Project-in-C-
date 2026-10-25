cmake_minimum_required(VERSION 3.20)

project(ExpenseTracker VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(expense_core
    src/ExpenseManager.cpp
)

target_include_directories(expense_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(expense_core PRIVATE /W4)
else()
    target_compile_options(expense_core PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

add_executable(expense-tracker
    src/main.cpp
)

target_link_libraries(expense-tracker PRIVATE expense_core)

add_executable(expense-tests
    tests/ExpenseTests.cpp
)

target_link_libraries(expense-tests PRIVATE expense_core)

add_executable(expense-manager-tests
    tests/ExpenseManagerTests.cpp
)

target_link_libraries(expense-manager-tests PRIVATE expense_core)

enable_testing()

add_test(NAME ExpenseTests COMMAND expense-tests)
add_test(NAME ExpenseManagerTests COMMAND expense-manager-tests)
