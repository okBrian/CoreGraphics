#pragma once

#include <glad/glad.h>
#include <Logging/Logging.hpp>

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <string>


namespace Core
{
    // Basic CoreApp Class that holds the GLFW window and Renderer for CoreApp. It also holds basic utility for imgui
    class CoreApp
    {
    private:
        GLFWwindow* c_Window;
        std::string c_Name;
        int c_Width, c_Height;
        bool isRunning;
    public:
        CoreApp(std::string name, int width, int height);
        virtual ~CoreApp();
        void CoreAppShutdown();

        bool init();   
        virtual void run();
        void Close();

        inline GLFWwindow* getWindow() { return c_Window; }
        inline std::string getName() { return c_Name; }
        inline int getWidth() { return c_Width; }
        inline int getHeight() { return c_Height; }
        inline bool getIsRunning() { return isRunning; }


        inline void ImGuiNewFrame() 
        { 
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
        }

        inline void ImGuiRenderFrame()
        {
            ImGuiIO& io = ImGui::GetIO(); (void)io;
            ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(c_Window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            
            // Update and Render additional Platform Windows
            // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
            //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                GLFWwindow* backup_current_context = glfwGetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                glfwMakeContextCurrent(backup_current_context);
            }
        }
    };

    // Defined by user
    CoreApp* Core::CreateApp()
    {
    }
};