cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 17)

# ===== CODE PART =====

# add the executable
add_executable(Main main.cpp src/Equation.cpp src/Problem.cpp src/UniformMesh.cpp src/NonUniformMesh.cpp src/Variable.cpp)

add_compile_options(-Wall -Wextra -Wpedantic)

# Link librairie from sub cmake
#add_subdirectory(mylib_dir)

#Linking lib
#target_link_libraries(Main PUBLIC mylib)

#Include dirs
target_include_directories(Main PUBLIC
                          "${PROJECT_SOURCE_DIR}/Results"
                          inc/
                          src/)

# ===== TESTING PART =====

#Enable testing
enable_testing()

#Find Google test package
find_package(GTest REQUIRED)

#Add test executable
add_executable(Test src/test.cpp src/Equation.cpp src/Problem.cpp src/UniformMesh.cpp src/NonUniformMesh.cpp src/Variable.cpp)
add_test(myTest Test)
target_include_directories(Test PUBLIC
                          "${PROJECT_SOURCE_DIR}/Results"
                          inc/
                          src/)
#link lib
target_link_libraries(Test PUBLIC GTest::GTest GTest::Main)
#target_link_libraries(Test PUBLIC mylib)

#link dir
#target_include_directories(Test PUBLIC
#                           "${PROJECT_SOURCE_DIR}/mylib_dir")

gtest_discover_tests(Test)