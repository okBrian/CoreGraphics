// Version of GLSL we are using
#version 450 core

// Layout help OpenGL read the vertex data it receives

layout(location = 0) out vec4 FragColor;

// Global Shader Variable that are defined with SetUniform
uniform vec4 aColor;

void main()
{
   FragColor = aColor;
}