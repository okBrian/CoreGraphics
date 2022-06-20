#include "VBO.hpp"

namespace Core
{
    // Add Data to be uploaded to the Graphics Card
    VBO::VBO(GLvoid* data, GLuint size, GLenum usage)
        : ID(0)
    {
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
        glDeleteBuffers(1, &ID);
    }

    // Bind the VBO for current usage
    void VBO::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    // Unbind the VBO from current usage
    void VBO::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};