#pragma once

#include <vector>
#include "glm/glm.hpp"
#include "shader.hpp"

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
};

class Mesh
{
private:
    void setupMesh();
    unsigned int m_vao, m_vbo, m_ibo;
    std::vector<Vertex> m_vertices;
    std::vector<unsigned int> m_indices;

public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    
    void Draw(Shader shader);
};
