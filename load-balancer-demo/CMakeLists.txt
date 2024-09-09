# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(load-balancer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source and header files
set(SOURCES
    LoadBalancer.cpp
    WebServer.cpp
    load_balancer.cpp
    main2.cpp
)

set(HEADERS
    LoadBalancer.h
    Request.h
    load_balancer.h
    WebServer.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link pthread library
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
