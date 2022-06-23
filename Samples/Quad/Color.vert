// Version of GLSL we are using
#version 450 core

// Layout help OpenGL read the vertex data it receives
layout(location = 0) in vec4 aPos;

void main()
{
   gl_Position =  aPos;
}