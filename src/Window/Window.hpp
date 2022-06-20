#pragma once
#include <GLFW/glfw3.h>

#include <string>

#include <Logging/Logging.hpp>

namespace Core
{
    // Base Window Class for the window of the app
    class Window
    {
    public:
        bool WindowRunning;
    private:
        GLFWwindow* window;
        std::string title;
        const int width;
        const int height;
    public:
        Window(std::string title="CoreApp", int width=1280, int height=720);
        virtual ~Window();
        virtual void onUpdate() = 0;
        
        int getWidth() const { return width; }
        int getHeight() const { return height; }
        GLFWwindow* getWindow() const { return window; }

        void setVSync(bool set);
    };
};