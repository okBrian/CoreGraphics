#pragma once
#include <glad/glad.h>
#include <Logging/Logging.hpp>
#include <ImGui/ImGuiClass.hpp>
#include <Window/WindowsPlatform/WindowsPlatform.hpp>
namespace Core
{
    // Base class that is to be super class for client class
    class CoreApp
    {
    public:
        CoreApp()
        {
            Logging::init();
            CORE_INFO("Core Engine Initiated!");
        }

        virtual ~CoreApp() {}
        virtual void onUpdate() {}
        virtual void onImGuiRenderer() {} 

        void run()
        {
            while(Window::WindowRunning)
            {
                onUpdate();
                ImGuiClass::ImGuiNewFrame();
                onImGuiRenderer();
                ImGuiClass::ImGuiRenderFrame();
                #if WIN32
                    WindowsPlatform::onUpdate();
                #endif
            }
        }

    };

    // Defined by user
    CoreApp* CreateApp();
};