#pragma once

#include "glm/glm.hpp"

enum class MovementDirection
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum class MouseState
{
    PRESSED,
    NOT_PRESSED
};

class Camera
{
 private:
    const glm::vec3 m_WORLD_UP_VEC = glm::vec3(0.0, 1.0, 0.0);
    float m_fov = 45.0f;
    float m_distance = 10.0;
    float m_position_xangle = 315.0;
    float m_position_yangle = 45.0;
    glm::vec3 m_position_coords = glm::vec3(0.0, 0.0, 0.0);
    glm::vec3 m_front_vec = glm::vec3(0.0, 0.0, -1.0);
    glm::vec3 m_up_vec = glm::vec3(0.0, 1.0, 0.0);
    glm::vec3 m_right_vec = glm::vec3(1.0, 0.0, 0.0);
    float m_movement_speed = 10.0;
    float m_mouse_sensitivity = 0.3;
    float m_zoom_sensitivity = 0.5;
    float m_fov_sensitivity = 0.4;
    void updateCameraVectors(void);

 public:
    Camera(void);

    //void orbit(MovementDirection direction, float delta_time, bool slow);
    void orbit(float x_offset, float y_offset);
    void zoom(double y_offset);
    void widenFov();
    void narrowFov();

    glm::mat4 getViewMatrix(void);
    glm::mat4 getProjMatrix(void);
    glm::vec3 getPosition(void) { return m_position_coords; }
};
