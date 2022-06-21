#include "WindowsPlatform.hpp"
#include <stb_image.h>

namespace Core
{
    WindowsPlatform::WindowsPlatform(std::string title/*="CoreApp"*/, int width/*=1280*/, int height/*=720*/)
        : Window(title, width, height)
    {
    }

    WindowsPlatform::~WindowsPlatform()
    {
    }

    void WindowsPlatform::onUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(getWindow());
        WindowRunning = !glfwWindowShouldClose(getWindow());
    }

    void WindowsPlatform::Close()
    {
        WindowRunning = false;
    }

    void WindowsPlatform::SetIcon(std::string filePath)
    {
        int width, height;
        int  BPP;
        stbi_set_flip_vertically_on_load(1);
		unsigned char* bytes = stbi_load(filePath.c_str(), &width, &height, &BPP, STBI_rgb);
        GLFWimage images[1];
        images[0].width = width;
        images[0].height = height;
        images[0].pixels = bytes;
        glfwSetWindowIcon(getWindow(), 0, images);

        if (bytes)
			stbi_image_free(bytes);
    }
};