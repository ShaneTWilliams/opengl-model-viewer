#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 position;
};

in vec3 frag_pos;  
in vec3 frag_norm;

out vec4 frag_color;  

uniform Material material;
uniform Light light;
uniform vec3 view_pos;

void main()
{
    vec3 ambient = light.ambient * material.ambient;

    vec3 unit_frag_norm = normalize(frag_norm);
    vec3 light_dir = normalize(light.position - frag_pos);  
    float diffuse_mag = max(dot(unit_frag_norm, light_dir), 0.0);
    vec3 diffuse = light.diffuse * (diffuse_mag * material.diffuse);

    vec3 view_dir = normalize(view_pos - frag_pos);
    vec3 reflect_dir = reflect(light_dir, unit_frag_norm);  
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);  
    
    vec3 result = ambient + diffuse + specular;

    frag_color = vec4(result, 1.0);
}
