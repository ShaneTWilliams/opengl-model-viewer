#pragma once

#include <string>
#include <vector>
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "shader.hpp"
#include "mesh.hpp"

class Model
{
private:
    /*  Model Data  */
    std::vector<Mesh> m_meshes;
    std::string m_directory;

    /*  Functions   */
    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

public:
    Model(std::string path);
    void Draw(Shader shader);
};
