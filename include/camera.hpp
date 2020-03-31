#pragma once

#include "glm/glm.hpp"

enum class MovementDirection
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera
{
 private:
    // Camera position attributes
    float m_yaw   = -90.0f;
    float m_pitch =  0.0f;
    float m_fov   =  45.0f;
    glm::vec3 m_position_coords = glm::vec3(0.0, 0.0, 0.0);
    glm::vec3 m_front_vec       = glm::vec3(0.0, 0.0, -1.0);
    glm::vec3 m_up_vec          = glm::vec3(0.0, 1.0, 0.0);
    glm::vec3 m_right_vec       = glm::vec3(1.0, 0.0, 0.0);
    glm::vec3 m_world_up_vec    = glm::vec3(0.0, 1.0, 0.0);
    // Movement attributes
    float m_movement_speed    = 10.0;
    float m_mouse_sensitivity = 0.3;

    void updateCameraVectors(void);

public:
    void processKeyboard(MovementDirection direction, float delta_time, bool slow);
    void processMouseMovement(float x_offset, float y_offset);
    void processScroll(double y_offset);
    glm::mat4 getViewMatrix(void);
    glm::mat4 getProjMatrix(void);
    glm::vec3 getPosition(void) { return m_position_coords; }
};
