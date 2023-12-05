#include "gtest/gtest.h"
#include <UniformMesh.h>
#include "Problem.h"
#include "Equation.h"

#include <iostream>
#include <string>
#include <vector>

TEST(UnitaryTest,MeshTest){
  // Construction et test d'une instance de UniformMesh
  UniformMesh UM{};
  ASSERT_EQ(UM.get_t_ini(), 0);
  ASSERT_EQ(UM.get_t_final(), 1);
  ASSERT_EQ(UM. get_dt(), 0.5);
  ASSERT_EQ(UM.get_x_min(), 0);
  ASSERT_EQ(UM.get_x_max(), 5);
  ASSERT_EQ(UM.get_dx(), 2);
}

TEST(UnitaryTest,ProblemTest){
  //Test avec IMesh = nullptr
  Equation A{};
  IMesh* Null = nullptr;
  Problem P_null{A, Null};
  //ASSERT_EQ(P_null.solve(), 0.0);

  // Construction et test d'une instance de Problem
  Equation E{}; 
  IMesh* IM = new UniformMesh{};
  Problem P {E, IM};

  ASSERT_EQ(P.get_Mesh()->get_t_ini(), IM->get_t_ini());
  ASSERT_EQ(P.get_Mesh()->get_t_final(), IM->get_t_final());
  ASSERT_EQ(P.get_Mesh()->get_dt(), IM->get_dt());
  ASSERT_EQ(P.get_Mesh()->get_x_min(), IM->get_x_min());
  ASSERT_EQ(P.get_Mesh()->get_x_max(), IM->get_x_max());
  ASSERT_EQ(P.get_Mesh()->get_dx(), IM->get_dx());
}

TEST(UnitaryTest,EquationTest){
  // Construction et test d'une instance de Problem
  Equation E{}; 
  ASSERT_EQ(E.get_speed(), 1);

  E.set_speed(30);
  ASSERT_EQ(E.get_speed(), 30);
}

TEST(MainFunctionTest,EquationTest){
  // Construction et test d'une instance de Equation
}
