#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Core
{
    class ImGuiClass
    {
    public:
        static void init(GLFWwindow* window);
        static void shutdown();
        static void ImGuiNewFrame();
        static void ImGuiRenderFrame();
    };
};