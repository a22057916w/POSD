cmake_minimum_required(VERSION 3.0)

project(HelloWindows)

set(CMAKE_CXX_STANDARD 11)

# Set the source files
set(SOURCES
    src/main.cpp
)

# Set the executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Define the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Add WinMain entry point
set_target_properties(${PROJECT_NAME} PROPERTIES
    LINK_FLAGS "/ENTRY:WinMainCRTStartup"
)
