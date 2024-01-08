#pragma once
#include <Logging/Logging.hpp>
#include <glad/gl.h>

namespace Core
{
    // Vertex Buffer Object: Uploading Vertex Data to the Graphics Card
    class VBO
    {
    private:
        GLuint ID;
    public:
        // Add Data to be uploaded to the Graphics Card
        VBO(GLvoid* data, GLuint size, GLenum usage);
        // Delete the Object
        ~VBO();

        // Bind the VBO for current usage
        void Bind() const;
        // Unbind the VBO from current usage
        void Unbind() const;
    };
};