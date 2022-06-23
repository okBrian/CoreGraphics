#pragma once
#include <Window/Window.hpp>

#include <stb_image.h>

namespace Core
{
    class WindowsPlatform : public Window
    {
    public:
        WindowsPlatform(std::string title="CoreApp", int width=1280, int height=720);
        ~WindowsPlatform();
        void onUpdate() override;
        void Close();
    };
};