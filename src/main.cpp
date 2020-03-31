#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <csignal>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
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

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 750;
float last_x = SCR_WIDTH / 2.0f;
float last_y = SCR_HEIGHT / 2.0f;
bool first_mouse = true;

int main(void)
{
    GLFWwindow *window;

    // Initialize glfw
    if (!glfwInit())
        return -1;

    #ifdef __APPLE__
        // We need to explicitly ask for a 4.1 context on OS X
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Renderer", NULL, NULL);
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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    GL_CALL(glEnable(GL_DEPTH_TEST));

    // Shader shader("shaders/stl/vertex.glsl", "shaders/stl/fragment.glsl");

    // Model ourModel("res/models/hand.STL");

    glm::mat4 model = glm::mat4(1.0f);
    shader.use();
    shader.setMat4("model", model);

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

        // camera/world stuff
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 projection = camera.getProjMatrix();
        // vertex shader uniforms
        shader.use();
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);
        
        ourModel.Draw(shader);

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

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.processKeyboard(MovementDirection::FORWARD, delta_time, slow);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.processKeyboard(MovementDirection::BACKWARD, delta_time, slow);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.processKeyboard(MovementDirection::LEFT, delta_time, slow);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.processKeyboard(MovementDirection::RIGHT, delta_time, slow);
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

    camera.processMouseMovement(x_offset, y_offset);
}

void scroll_callback(GLFWwindow *window, double x_offset, double y_offset)
{
    camera.processScroll(y_offset);
}
