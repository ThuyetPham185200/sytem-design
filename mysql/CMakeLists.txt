# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(mysql)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source and header files
set(SOURCES
    main.cpp
)

set(HEADERS
    mysql.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link pthread library
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Find MySQL client library using mysql_config
execute_process(
    COMMAND mysql_config --cflags
    OUTPUT_VARIABLE MYSQL_CFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND mysql_config --libs
    OUTPUT_VARIABLE MYSQL_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Set the include directories and link libraries
target_include_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CFLAGS}) # MYSQL_CFLAGS = -I/usr/include/mysql 
target_link_libraries(${PROJECT_NAME} PRIVATE ${MYSQL_LIBS}) # MYSQL_LIBS = -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lzstd -lssl -lcrypto -lresolv -lm

# mysql_config --cflags --libs
# -I/usr/include/mysql 
# -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lzstd -lssl -lcrypto -lresolv -lm

# target_include_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CFLAGS}): Adds the include directories obtained from mysql_config --cflags to your project. 
# This ensures that the compiler knows where to find the MySQL header files when compiling your source code.