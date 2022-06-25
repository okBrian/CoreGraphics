#include "WindowsPlatform.hpp"

namespace Core
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    WindowsPlatform::WindowsPlatform(std::string title/*="CoreApp"*/, int width/*=1280*/, int height/*=720*/)
        : Window(title, width, height)
    {
        glfwSetFramebufferSizeCallback(getWindow(), framebuffer_size_callback);
    }

    WindowsPlatform::~WindowsPlatform()
    {
    }

    void WindowsPlatform::onUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(getWindow());
        WindowRunning = !glfwWindowShouldClose(getWindow());
    }

    void WindowsPlatform::Close()
    {
        WindowRunning = false;
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        (void)window;
        glViewport(0, 0, width, height);
    }
};