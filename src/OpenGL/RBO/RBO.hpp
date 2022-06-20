#pragma once
#include <glad/glad.h>

namespace Core
{

    // Render Buffer Object: Stores an image to be used with the FBO can't be accesed in shader
    class RBO
    {
    private:
        GLuint ID;
    public:
        // Initialize the RBO & store it in depth buffer
        RBO(int width, int height);
        // Delete the RBO
        ~RBO();

        // Binds the RBO for current use
        void Bind() const;
        // Unbind the RBO from current usage
        void Unbind() const;
        // Attach the RBO to the FBO
        void AttachRBO() const;
    };
};