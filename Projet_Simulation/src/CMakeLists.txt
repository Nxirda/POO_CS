project(Source_Lib)

add_library(Source_Lib
            Solver/Equation.cpp 
            Solver/Problem.cpp
            Solver/Variable.cpp 
            Mesh/NonUniformMesh.cpp 
            Mesh/UniformMesh.cpp 
            Tools/Timer.cpp 
            Order/Upwind.cpp 
            Order/Lax_Wendroff.cpp
)

target_include_directories(Source_Lib 
        PUBLIC 
        ${CMAKE_SOURCE_DIR}/inc/Mesh/
        ${CMAKE_SOURCE_DIR}/inc/Order/
        ${CMAKE_SOURCE_DIR}/inc/Solver/
        ${CMAKE_SOURCE_DIR}/inc/Tools/
)
        