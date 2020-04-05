#include "camera.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(void)
{
    updateCameraVectors();
}

void Camera::updateCameraVectors(void)
{
    m_position_coords = glm::vec3(
        glm::cos(glm::radians(m_position_xangle)) * glm::cos(glm::radians(m_position_yangle)),
        glm::sin(glm::radians(m_position_yangle)),
        glm::sin(glm::radians(m_position_xangle)) * glm::cos(glm::radians(m_position_yangle))
    );
    m_position_coords *= glm::vec3(m_distance);
    glm::vec3 front_vec = glm::normalize(m_position_coords) * glm::vec3(-1.0);
    glm::vec3 right_vec = glm::normalize(glm::cross(front_vec, m_WORLD_UP_VEC));
    m_up_vec = glm::normalize(glm::cross(right_vec, front_vec));
}

void Camera::orbit(float x_offset, float y_offset)
{
    m_position_xangle += x_offset * m_mouse_sensitivity;
    m_position_yangle -= y_offset * m_mouse_sensitivity;

    while (m_position_xangle >= 360.0)
    {
        m_position_xangle -= 360.0;
    }
    while (m_position_xangle <= 0.0)
    {
        m_position_xangle += 360.0;
    }
    if (m_position_yangle >= 90.0)
    {
        m_position_yangle = 89.0;
    }
    if (m_position_yangle <= -90.0)
    {
        m_position_yangle = -89.0;
    }

    updateCameraVectors();
}

void Camera::zoom(double y_offset)
{
    m_distance -= y_offset * m_zoom_sensitivity;

    if (m_distance < 1.0)
    {
        m_distance = 1.0;
    }

    updateCameraVectors();
}

void Camera::widenFov(void)
{
    if (m_fov + m_fov_sensitivity <= 90.0f)
        m_fov += m_fov_sensitivity;
}

void Camera::narrowFov(void)
{
    if (m_fov - m_fov_sensitivity >= 30.0f)
        m_fov -= m_fov_sensitivity;
}

void Camera::setScreenDimensions(unsigned int width, unsigned int height)
{
    m_screen_width  = width;
    m_screen_height = height;
}

void Camera::setSensitivities(float mouse_sensitivity, float zoom_sensitivity, float fov_sensitivity){
    m_mouse_sensitivity = mouse_sensitivity;
    m_zoom_sensitivity  = zoom_sensitivity;
    m_fov_sensitivity   = fov_sensitivity;
}

glm::mat4 Camera::getViewMatrix(void)
{
    return glm::lookAt(m_position_coords, glm::vec3(0.0, 0.0, 0.0), m_up_vec);
}

glm::mat4 Camera::getProjMatrix(void)
{
    return glm::perspective(glm::radians(m_fov), (float)m_screen_width/(float)m_screen_height, 0.1f, 100.0f);
}

