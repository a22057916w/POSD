cmake_minimum_required(VERSION 3.0)

project(LogicSimulator)

set(CMAKE_CXX_STANDARD 11)

# Set the source files
file(GLOB SOURCES "src/*.cpp" "main.cpp")

# Set the executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Define the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Add any necessary include directories
target_include_directories(LogicSimulator PRIVATE src)
