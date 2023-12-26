cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Find Google test package
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
find_package(TBB REQUIRED)

# Link librairie from sub cmake
add_subdirectory(src)

add_compile_options(-std=c++20 -Wall -Wextra -Wpedantic)

# ===== CODE PART =====

# add the executable
add_executable(Main main.cpp)

#Linking lib
target_link_libraries(Main PUBLIC Source_Lib)

#link lib
target_link_libraries(Main PUBLIC Threads::Threads)
target_link_libraries(Main PUBLIC TBB::tbb)

# ===== TESTING PART =====

#Enable testing
enable_testing()

#Add test executable
add_executable(Test src/Tools/test.cpp)

#Linking lib
target_link_libraries(Test PUBLIC Source_Lib)

add_test(myTest Test)

target_link_libraries(Test PUBLIC GTest::GTest GTest::Main)
target_link_libraries(Test PUBLIC Threads::Threads)
target_link_libraries(Test PUBLIC TBB::tbb)

gtest_discover_tests(Test)