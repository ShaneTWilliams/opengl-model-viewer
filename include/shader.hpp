#pragma once

#include <iostream>

#include "glm/glm.hpp"

class Shader
{
private:
    unsigned int m_id;

    unsigned int compile(unsigned int type, const std::string &source);

public:
    Shader(std::string vertex_path, std::string fragment_path, std::string geometry_path);

    // Bind shader program to opengl
    void use(void);
    // Uniform setting functions
    void setVec3(const std::string &var_name, glm::vec3 vector);
    void setMat4(const std::string &var_name, glm::mat4 matrix);
    void setFloat(const std::string &var_name, float value);
    
    unsigned int get_id(void) { return m_id; }
};
