#include <string>
#include <GLFW/glfw3.h>
#include <Logging/Logging.hpp>
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
    public:
        Window(std::string title="CoreApp", int width=1280, int height=720);
        virtual ~Window();
        
        inline int getWidth() const { return width; }
        inline int getHeight() const { return height; }
        static GLFWwindow* getWindow() { return window; }

        void setVSync(bool set);
    };
};