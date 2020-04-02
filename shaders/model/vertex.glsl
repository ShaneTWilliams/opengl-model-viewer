#version 330
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 frag_pos;  
out vec3 frag_norm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    frag_pos = vec3(model * vec4(position, 1.0));
    frag_norm = mat3(transpose(inverse(model))) * normal;  
}
