#pragma once
#include <glad/glad.h>
#include <Window/Window.hpp>

#include <stb_image.h>

namespace Core
{
    class WindowsPlatform : public Window
    {
    public:
        WindowsPlatform(std::string title="CoreApp", int width=1280, int height=720);
        ~WindowsPlatform();
        static void onUpdate();
        void Close();
    };
};