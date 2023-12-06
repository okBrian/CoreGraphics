#include "VBO.hpp"

namespace Core
{
    void VBO::init(GLvoid *data, GLuint size, GLenum usage)
    {
        CORE_DEBUG("VBO initialized with size - {0} and usage - {1}", size, usage);
        glGenBuffers(1, &ID);
        Bind();
        // Sends the vertex data to the buffer
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    // Delete the Object
    VBO::~VBO()
    {
        CORE_DEBUG("VBO Destroyed");
        // Deletes the Buffer
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