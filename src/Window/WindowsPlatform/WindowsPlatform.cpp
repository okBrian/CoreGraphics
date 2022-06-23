#include "WindowsPlatform.hpp"

namespace Core
{
    WindowsPlatform::WindowsPlatform(std::string title/*="CoreApp"*/, int width/*=1280*/, int height/*=720*/)
        : Window(title, width, height)
    {
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
};