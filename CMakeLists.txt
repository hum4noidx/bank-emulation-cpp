cmake_minimum_required(VERSION 3.24)
project(untitled1)

set(CMAKE_CXX_STANDARD 23)

# Add source files
set(SOURCES
        sources/Account.cpp
        sources/Transaction.cpp
        sources/Bank.cpp
        )

# Add header files
set(HEADERS
        headers/Account.h
        headers/Transaction.h
        headers/Bank.h
        )

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} main.cpp )
