#pragma once
#include <CoreApp.hpp>

#include <stb_image.h>
#include <Logging/Logging.hpp>
#include <ImGui/ImGuiClass.hpp>
#include <WindowsPlatform/WindowsPlatform.hpp>

#include <FBO/FBO.hpp>
#include <IBO/IBO.hpp>
#include <Renderer/Renderer.hpp>
#include <Shader/Shader.hpp>
#include <Texture/Texture.hpp>
#include <VAO/VAO.hpp>
#include <VBO/VBO.hpp>

#include <glad/glad.h>
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