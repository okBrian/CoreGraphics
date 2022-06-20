#include "Window.hpp"

namespace Core
{
    Window::Window(std::string title/*="CoreApp"*/, int width/*=1280*/, int height/*=720*/)
        :  title(title), width(width), height(height)
    {
        if (!glfwInit())
        {
            Logging::error("GLFW could not be initialized");
            WindowRunning = false;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if(!window)
        {
            Logging::error("Window could not be created");
            WindowRunning = false;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::setVSync(bool set)
    {
        glfwSwapInterval(set);
    }
};