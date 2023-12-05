#include <stdio.h>
#include <string.h>

#include "Equation.h"
#include "Problem.h"
#include "EnumMesh.h"

int main(int argc, char **argv)
{

    if(argc == 1)
    {
        Equation E{}; 
        IMesh* IM = new UniformMesh{};
        Problem P {E, IM};
        std::cout << "=== DEFAULT EQUATION === \n";
        std::cout <<"\n";
        P.solve();
        return 0;
    }
    else if(argc != 8 )
    {
        std::cout << "Usage is :\n./Main (for a hard coded Problem)\n";
        std::cout << "     OR\n"; 
        std::cout << "./Main [t_Initial] [t_Final] [pas de temps] " <<
                      "[x_min] [x_max] [pas d espace] [maillage] \n";
        std::cout << "(for a custom Problem)\n";
        return 1;
    }
    else{

        float t_init  = std::stof(argv[1]);
        float t_final = std::stof(argv[2]);
        float dt      = std::stof(argv[3]);
        float x_min   = std::stof(argv[4]);
        float x_max   = std::stof(argv[5]);
        float dx      = std::stof(argv[6]);

        IMesh* IM = nullptr;
        MeshType MT = MeshType::Other;

        if(MeshDictionnary.count(argv[7]))
        {
            MT = (MeshDictionnary.find(argv[7]))->second;
        }
        switch (MT)
        {
            case (MeshType::UniformMesh):
                IM = new UniformMesh{t_init, t_final, dt, x_min, x_max, dx};
                break;

            case (MeshType::NonUniformMesh):
                IM = new NonUniformMesh{t_init, t_final, dt, x_min, x_max, dx};
                break;
                
            default :
                std::cout <<"Maillage should be : uniform or non-uniform\n";
                break;

        }

        Equation E{};
        Problem P = {E, IM};
        P.solve();
    }
}