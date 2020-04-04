#include "mesh.hpp"
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include "error_checking.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
: m_vertices(vertices), m_indices(indices)
{
    setupMesh();
}

void Mesh::setupMesh(void)
{
    GL_CALL(glGenVertexArrays(1, &m_vao));
    GL_CALL(glGenBuffers(1, &m_vbo));
    GL_CALL(glGenBuffers(1, &m_ibo));

    GL_CALL(glBindVertexArray(m_vao));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));

    GL_CALL(glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), 
                            &m_vertices[0], GL_STATIC_DRAW));

    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size()*sizeof(unsigned int),
                            &m_indices[0], GL_STATIC_DRAW));

    // Vertex positions
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0));
    // Vertex normals
    GL_CALL(glEnableVertexAttribArray(1));
    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Normal)));

    GL_CALL(glBindVertexArray(0));
}

void Mesh::Draw(Shader shader)
{
    GL_CALL(glBindVertexArray(m_vao));
    GL_CALL(glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0));
    GL_CALL(glBindVertexArray(0));  // Unbind vao
}
