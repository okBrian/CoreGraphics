#include "CoreApp.hpp"

namespace Core
{
    CoreApp::CoreApp(std::string name, int width, int height)
        : c_Window(nullptr), c_Name(name), c_Width(width), c_Height(height), isRunning(true)
    {    
    }

    void CoreApp::CoreAppShutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow(c_Window);
        glfwTerminate();
    }


    bool CoreApp::init()
    {
        if (!glfwInit())
        {
            Logging::error("GLFW could not be initialized");
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

        c_Window = glfwCreateWindow(c_Width, c_Height, c_Name.c_str(), NULL, NULL);
        if(!c_Window)
        {
            Logging::error("Window could not be created");
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(c_Window);
        /* VSync -  Synchornizes Framerate to monitors framerate */
        glfwSwapInterval(1);

        IMGUI_CHECKVERSION();

        // Initiates GLAD
        gladLoadGL();

        glViewport(0, 0, c_Width, c_Height);

        //Setup IMGUI
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(c_Window, true);
        ImGui_ImplOpenGL3_Init("#version 450");
        return true;
    }

    void CoreApp::Close()
    {
        isRunning = false;
        CoreAppShutdown();
    }
};