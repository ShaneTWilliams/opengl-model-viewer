#include "camera.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>

void Camera::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front_vec = glm::normalize(front);
    // Also re-calculate the Right and Up vector
    m_right_vec = glm::normalize(glm::cross(m_front_vec, m_world_up_vec)); // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_up_vec = glm::normalize(glm::cross(m_right_vec, m_front_vec));
}

void Camera::processKeyboard(MovementDirection direction, float delta_time, bool slow)
{
    float velocity = m_movement_speed * delta_time;
    if (slow)
    {
        velocity *= 0.3;
    }
    if (direction == MovementDirection::FORWARD)
    {
        m_position_coords += m_front_vec * velocity;
    }
    if (direction == MovementDirection::BACKWARD)
    {
        m_position_coords -= m_front_vec * velocity;
    }
    if (direction == MovementDirection::LEFT)
    {
        m_position_coords -= m_right_vec * velocity;
    }
    if (direction == MovementDirection::RIGHT)
    {
        m_position_coords += m_right_vec * velocity;
    }
}

void Camera::processMouseMovement(float x_offset, float y_offset)
{
    m_yaw += x_offset * m_mouse_sensitivity;
    m_pitch += y_offset * m_mouse_sensitivity;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (m_pitch > 89.0f)
        m_pitch = 89.0f;
    if (m_pitch < -89.0f)
        m_pitch = -89.0f;

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::processScroll(double y_offset)
{
    if (m_fov - y_offset >= 30.0f && m_fov - y_offset <= 90.0f)
        m_fov -= y_offset;
}

glm::mat4 Camera::getViewMatrix(void)
{
    return glm::lookAt(m_position_coords, m_position_coords + m_front_vec, m_up_vec);
}

glm::mat4 Camera::getProjMatrix(void)
{
    return glm::perspective(glm::radians(m_fov), 800.0f / 600.0f, 0.1f, 100.0f);
    ;
}

