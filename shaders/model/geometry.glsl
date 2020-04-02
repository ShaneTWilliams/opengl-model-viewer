#version 330

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in FragData {
    vec3 frag_pos;  
    vec3 frag_norm;
} gs_in[];

out FragData {
    vec3 frag_pos;  
    vec3 frag_norm;
} gs_out;
out vec2 TexCoords; 

uniform float distance;

vec3 GetNormal()
{
   vec3 surface_vec_1 = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
   vec3 surface_vec_2 = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
   return normalize(cross(surface_vec_1, surface_vec_2));
} 

void main() {    
    vec3 normal = GetNormal();

    gl_Position = gl_in[0].gl_Position + vec4(normal*distance, 1.0);
    gs_out.frag_pos = gs_in[0].frag_pos;
    gs_out.frag_norm = gs_in[0].frag_norm;
    EmitVertex();
    gl_Position = gl_in[1].gl_Position + vec4(normal*distance, 1.0);
    gs_out.frag_pos = gs_in[1].frag_pos;
    gs_out.frag_norm = gs_in[1].frag_norm;
    EmitVertex();
    gl_Position = gl_in[2].gl_Position + vec4(normal*distance, 1.0);
    gs_out.frag_pos = gs_in[2].frag_pos;
    gs_out.frag_norm = gs_in[2].frag_norm;
    EmitVertex();
    EndPrimitive();

    
}  
