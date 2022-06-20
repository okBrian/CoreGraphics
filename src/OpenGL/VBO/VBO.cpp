#include "VBO.hpp"

namespace Core
{
    // Add Data to be uploaded to the Graphics Card
    VBO::VBO(GLvoid* data, GLuint size, GLenum usage)
        : ID(0)
    {
        CORE_DEBUG("VBO initialized with size - {0} and usage - {1}", size, usage);
        // Generate a buffer
        glGenBuffers(1, &ID);
        // Bind it
        Bind();
        // Bind the vertex data to the buffer
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    // Delete the Object
    VBO::~VBO()
    {
        CORE_DEBUG("Deleted VBO");
        glDeleteBuffers(1, &ID);
    }

    // Bind the VBO for current usage
    void VBO::Bind() const
    {
        CORE_DEBUG("VBO Binded");
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    // Unbind the VBO from current usage
    void VBO::Unbind() const
    {
        CORE_DEBUG("VBO Unbinded");
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};