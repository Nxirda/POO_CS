#ifndef ENUM_MESH_H_
#define ENUM_MESH_H_

#include <iostream> 
#include <string.h>
#include <map>

#include "IMesh.h"
#include "UniformMesh.h"
#include "NonUniformMesh.h"

enum class MeshType {
    UniformMesh,
    NonUniformMesh,
    Other
};

std::map<std::string, MeshType> MeshDictionnary = 
{
    {"uniform", MeshType::UniformMesh}, 
    {"non-uniform", MeshType::NonUniformMesh}
};

#endif