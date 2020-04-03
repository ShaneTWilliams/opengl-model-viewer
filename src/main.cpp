#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <csignal>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stbimage/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "GLFW/glfw3.h"

#include "error_checking.hpp"
#include "shader.hpp"
#include "camera.hpp"
#include "mesh.hpp"
#include "model.hpp"

void process_input(GLFWwindow *window, float deltaTime);
void mouse_callback(GLFWwindow *window, double x_pos, double y_pos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

Camera camera;

const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;
float last_x = SCR_WIDTH / 2.0f;
float last_y = SCR_HEIGHT / 2.0f;
bool first_mouse = true;
float explode_distance = 2.0;

int main(void)
{
    // Initialize glfw
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_SAMPLES, 4);

    #ifdef __APPLE__
        // We need to explicitly ask for a 4.1 context on OS X
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif

    // Create a windowed mode window and its OpenGL context
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int window_width = mode->width;
    int window_height = mode->height;
    GLFWwindow *window = glfwCreateWindow(window_width, window_height, "STL Model Viewer", monitor, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    GL_CALL(glEnable(GL_DEPTH_TEST));
    GL_CALL(glEnable(GL_CULL_FACE));  
    GL_CALL(glEnable(GL_MULTISAMPLE));  

    Shader shader("shaders/model/vertex.glsl", "shaders/model/fragment.glsl", "shaders/model/geometry.glsl");

    Model ourModel("alien.stl");

   

    float deltaTime,
    currentFrame, lastFrame = 0;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // time
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        GL_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
        GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

        // model/world matrices
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0, -1.0, 0.0));
        model = glm::scale(model, glm::vec3(0.05));
        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 projection = camera.getProjMatrix();

        // vertex shader uniforms
        shader.use();
        if (explode_distance > 0)
        {
            explode_distance -= 0.01;
        }
        shader.setFloat("distance", explode_distance);
        shader.setMat4("model", model);
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);
        // fragment shader uniforms
        shader.setVec3("material.ambient", glm::vec3(0.7, 0.7, 0.7));
        shader.setVec3("material.diffuse", glm::vec3(0.8, 0.8, 0.8));
        shader.setVec3("material.specular", glm::vec3(0.1, 0.1, 0.1));
        shader.setFloat("material.shininess", 32.0f);
        shader.setVec3("light.ambient",  glm::vec3(0.2, 0.2, 0.2));
        shader.setVec3("light.diffuse",  glm::vec3(0.5, 0.5, 0.5)); 
        shader.setVec3("light.specular", glm::vec3(0.8, 0.8, 0.8)); 
        shader.setVec3("light.position", glm::vec3(50.0, 50.0, 50.0));
        ourModel.Draw(shader);
        // model = glm::mat4(1.0f);
        // model = glm::translate(model, glm::vec3(5.0, 5.0, 5.0));
        // model = glm::scale(model, glm::vec3(0.05, 0.05, 0.05));
        // shader.setMat4("model", model);
        // ourModel.Draw(shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
        process_input(window, deltaTime);
    }

    GL_CALL(glDeleteProgram(shader.get_id()));
    glfwTerminate();
    return 0;
}

void process_input(GLFWwindow *window, float delta_time)
{
    bool slow = false;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        slow = true;
    }
    
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_BRACKET) == GLFW_PRESS)
    {
        camera.narrowFov();
    }

    if (glfwGetKey(window, GLFW_KEY_RIGHT_BRACKET) == GLFW_PRESS)
    {
        camera.widenFov();
    }
}

void mouse_callback(GLFWwindow *window, double x_pos, double y_pos)
{
    if (first_mouse)
    {
        last_x = x_pos;
        last_y = y_pos;
        first_mouse = false;
    }

    float x_offset = x_pos - last_x;
    float y_offset = last_y - y_pos; // reversed since y-coordinates go from bottom to top

    last_x = x_pos;
    last_y = y_pos;

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        camera.orbit(x_offset, y_offset);
    }
}

void scroll_callback(GLFWwindow *window, double x_offset, double y_offset)
{
    camera.zoom(y_offset);
}
