#include "shader.hpp"

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <fstream>
#include <sstream>
#include <string>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "error_checking.hpp"

Shader::Shader(std::string vertex_path, std::string fragment_path, std::string geometry_path)
{
    GL_CALL(unsigned int program = glCreateProgram());
    unsigned int vertex_shader = compile(GL_VERTEX_SHADER, vertex_path);
    unsigned int fragment_shader = compile(GL_FRAGMENT_SHADER, fragment_path);
    unsigned int geometry_shader = compile(GL_GEOMETRY_SHADER, geometry_path);

    GL_CALL(glAttachShader(program, vertex_shader));
    GL_CALL(glAttachShader(program, fragment_shader));
    GL_CALL(glAttachShader(program, geometry_shader));
    GL_CALL(glLinkProgram(program));
    int result;
    char error_log[512];
    GL_CALL(glGetProgramiv(program, GL_LINK_STATUS, &result));
    if (result == GL_FALSE)
    {
        glGetProgramInfoLog(program, 512, nullptr, error_log);
        std::cout << "FAILED TO LINK SHADERS: " << error_log << std::endl;
    }
    GL_CALL(glValidateProgram(program));

    GL_CALL(glDeleteShader(vertex_shader));
    GL_CALL(glDeleteShader(fragment_shader));
    GL_CALL(glDeleteShader(geometry_shader));

    m_ID = program;
}

unsigned int Shader::compile(unsigned int type, const std::string &path)
{
    std::ifstream shader_source(path);
    std::stringstream shader_buf;
    shader_buf << shader_source.rdbuf();
    std::string shader_str = shader_buf.str();
    const char *shader_cstr = shader_str.c_str();
    GL_CALL(unsigned int id = glCreateShader(type));
    GL_CALL(glShaderSource(id, 1, &shader_cstr, nullptr));
    GL_CALL(glCompileShader(id));

    int result;
    GL_CALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

    if (result == GL_FALSE)
    {
        char error_log[512];
        GL_CALL(glGetShaderInfoLog(id, 512, nullptr, error_log));
        GL_CALL(glDeleteShader(id));
        std::cout << "FAILED TO COMPILE SHADER: " << error_log << std::endl;
        return 0;
    }
    return id;
}

void Shader::use(void)
{
    GL_CALL(glUseProgram(m_ID));
}

void Shader::setVec3(const std::string &var_name, glm::vec3 vector)
{   
    GL_CALL(int location = glGetUniformLocation(m_ID, var_name.c_str()));
    GL_CALL(glUniform3f(location, vector.x, vector.y, vector.z));
}

void Shader::setMat4(const std::string &var_name, glm::mat4 matrix)
{   
    GL_CALL(int location = glGetUniformLocation(m_ID, var_name.c_str()));
    GL_CALL(glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix)));
}

void Shader::setFloat(const std::string &var_name, float value)
{
    GL_CALL(int location = glGetUniformLocation(m_ID, var_name.c_str()));
    GL_CALL(glUniform1f(location, value));
}
