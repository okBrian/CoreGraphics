#include "Window.hpp"
namespace Core
{
    bool Window::WindowRunning;
    bool Window::isGUIInit = false;
    GLFWwindow* Window::window;

    Window::Window(std::string title/*="CoreApp"*/, int width/*=1280*/, int height/*=720*/)
        :  title(title), width(width), height(height)
    {
        WindowRunning = true;

        if (!glfwInit())
        {
            CORE_CRITICAL("GLFW could not be initialized");
            WindowRunning = false;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if(!window)
        {
            CORE_ERROR("Window could not be created");
            WindowRunning = false;
            glfwTerminate();
            return;
        }
        #if WIN32
            glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
                glViewport(0, 0, width, height);
            });
        #endif
        glfwMakeContextCurrent(window);
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();

        if (isGUIInit) {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        }
    }

    void Window::onUpdate() {
        #if WIN32
            glfwPollEvents();
            glfwSwapBuffers(getWindow());
            WindowRunning = !glfwWindowShouldClose(getWindow());
        #endif
    }

    //Setup IMGUI
    void Window::ImGuiInit() {
        isGUIInit = true;
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
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 450");
    }

    void Window::ImGuiNewFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void Window::ImGuiRenderFrame()
    {
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        ImGui::Render();
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