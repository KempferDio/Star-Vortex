#version 330 core
layout (location = 0) in vec4 vertex;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main() {
    gl_Position = model * vec4(vertex.xy, -1.0, 1.0);
    TexCoords = vertex.zw;  
}