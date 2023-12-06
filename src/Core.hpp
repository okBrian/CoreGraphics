#pragma once
#include <CoreApp.hpp>

#include <stb_image.h>

#include <FBO/FBO.hpp>
#include <IBO/IBO.hpp>
#include <Renderer/Renderer.hpp>
#include <Shader/Shader.hpp>
#include <Texture/Texture.hpp>
#include <VAO/VAO.hpp>
#include <VBO/VBO.hpp>
#include <VBO/Layout.hpp>

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


// ENTRY POINT 
#include <Entrypoint.hpp>

bool LoadOpenGLContext()
{
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        CORE_CRITICAL("OpenGL context couldn't be loaded!");
        return false;
    }
    return true;
}

void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
    CORE_ERROR("GL CALLBACK: {0} type = 0x{1}, severity = 0x{2}, message = {3}", 
              ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
              type, 
              severity, 
              message 
              );
}

void EnableOpenGLDebug()
{
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);
}