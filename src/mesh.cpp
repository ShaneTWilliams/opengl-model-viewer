#include "mesh.hpp"

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>

#include "error_checking.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
: m_vertices(vertices), m_indices(indices), m_textures(textures) 
{
    setupMesh();
}

void Mesh::setupMesh(void)
{
    GL_CALL(glGenVertexArrays(1, &m_VAO));
    GL_CALL(glGenBuffers(1, &m_VBO));
    GL_CALL(glGenBuffers(1, &m_EBO));

    GL_CALL(glBindVertexArray(m_VAO));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));

    GL_CALL(glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], 
                 GL_STATIC_DRAW));

    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int),
                 &m_indices[0], GL_STATIC_DRAW));

    // vertex positions
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0));
    // vertex normals
    GL_CALL(glEnableVertexAttribArray(1));
    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Normal)));
    // vertex texture coords
    GL_CALL(glEnableVertexAttribArray(2));
    GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, TexCoords)));

    GL_CALL(glBindVertexArray(0));
}

void Mesh::Draw(Shader shader)
{
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for (unsigned int i = 0; i < m_textures.size(); i++)
    {
        GL_CALL(glActiveTexture(GL_TEXTURE0 + i)); // activate proper texture unit before binding
        // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = m_textures[i].type;
        if (name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if (name == "texture_specular")
            number = std::to_string(specularNr++);

        shader.setFloat(("material." + name + number).c_str(), i);
        GL_CALL(glBindTexture(GL_TEXTURE_2D, m_textures[i].id));
    }
    GL_CALL(glActiveTexture(GL_TEXTURE0));

    // draw mesh
    GL_CALL(glBindVertexArray(m_VAO));
    GL_CALL(glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0));
    GL_CALL(glBindVertexArray(0));
}
