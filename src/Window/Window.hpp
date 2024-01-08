#include <string>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <Logging/Logging.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Core
{
    // Base Window Class for the window of the app
    class Window
    {
    public:
        static bool WindowRunning;
    private:
        static GLFWwindow* window;
        std::string title;
        const int width;
        const int height;
        static bool isGUIInit;
    public:
        Window(std::string title="CoreApp", int width=1280, int height=720);
        ~Window();
        static void onUpdate();

        static void ImGuiInit();
        static void ImGuiShutdown();
        static void ImGuiNewFrame();
        static void ImGuiRenderFrame();

        inline int getWidth() const { return width; }
        inline int getHeight() const { return height; }
        static GLFWwindow* getWindow() { return window; }
        void Close() { WindowRunning = false; }
        void setVSync(bool set) { glfwSwapInterval(set); };
    };
};