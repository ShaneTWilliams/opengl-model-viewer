#pragma once

#include <string>
#include <vector>
#include "shader.hpp"
#include "mesh.hpp"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

class Model
{
private:
    /*  Model Data  */
    std::vector<Mesh> m_meshes;
    std::string m_directory;
    std::vector<Texture> m_textures_loaded;

    /*  Functions   */
    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                              std::string typeName);

public:
    Model(std::string path);
    void Draw(Shader shader);
};
