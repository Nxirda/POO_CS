cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 17)

# ===== CODE PART =====

# add the executable
add_executable(Main main.cpp src/Equation.cpp src/Problem.cpp src/UniformMesh.cpp 
                             src/NonUniformMesh.cpp src/Variable.cpp src/Timer.cpp)

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


#Find Google test package
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
find_package(TBB REQUIRED)

#link lib
target_link_libraries(Main PUBLIC GTest::GTest GTest::Main)
target_link_libraries(Main PUBLIC Threads::Threads)
target_link_libraries(Main PUBLIC TBB::tbb)

# ===== TESTING PART =====

#Enable testing
enable_testing()

#Add test executable
add_executable(Test src/test.cpp src/Equation.cpp src/Problem.cpp src/UniformMesh.cpp 
                    src/NonUniformMesh.cpp src/Variable.cpp src/Timer.cpp)

add_test(myTest Test)
target_include_directories(Test PUBLIC
                          "${PROJECT_SOURCE_DIR}/Results"
                          inc/
                          src/)

target_link_libraries(Test PUBLIC GTest::GTest GTest::Main)
target_link_libraries(Test PUBLIC Threads::Threads)
target_link_libraries(Test PUBLIC TBB::tbb)
#target_link_libraries(Test PUBLIC mylib)

#link dir
#target_include_directories(Test PUBLIC
#                           "${PROJECT_SOURCE_DIR}/mylib_dir")

gtest_discover_tests(Test)