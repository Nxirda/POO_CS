if(EXISTS "/home/nxirda/Desktop/POO_CS/Projet_Simulation/release/Test[1]_tests.cmake")
  include("/home/nxirda/Desktop/POO_CS/Projet_Simulation/release/Test[1]_tests.cmake")
else()
  add_test(Test_NOT_BUILT Test_NOT_BUILT)
endif()
