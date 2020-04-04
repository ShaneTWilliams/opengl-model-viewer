#pragma once

#include <string>
#include <vector>
#include "assimp/scene.h"
#include "shader.hpp"
#include "mesh.hpp"

class Model
{
private:
    std::vector<Mesh> m_meshes;

    // Load model and call processNode
    void loadModel(std::string path);
    // Recursively process each Node by calling processMesh on each node's 
    // meshes and adding them to m_meshes vector
    void processNode(aiNode *node, const aiScene *scene);
    // Create mesh object with vertex and index daa
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

public:
    Model(std::string path);

    // Call draw function of all meshes in m_meshes
    void Draw(Shader shader);
};
