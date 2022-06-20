#pragma once
#include <glad/glad.h>
namespace Core
{
    // Basic CoreApp Class that holds the GLFW window and Renderer for CoreApp. It also holds basic utility for imgui
    class CoreApp
    {
    public:
        CoreApp()
        {
            gladLoadGL();
        }

        virtual void run() = 0;
    };

    // Defined by user
    CoreApp* CreateApp();
};