#include "VBO.hpp"

namespace Core
{
    VBO::VBO(GLvoid *data, GLuint size, GLenum usage)
    {
        CORE_TRACE("VBO created with ID - {}", ID);
        glGenBuffers(1, &ID);
        Bind();
        // Sends the vertex data to the buffer
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    // Delete the Object
    VBO::~VBO()
    {
        CORE_TRACE("VBO deleted with ID - {}", ID);
        // Deletes the Buffer
        glDeleteBuffers(1, &ID);
    }
    // Bind the VBO for current usage
    void VBO::Bind() const
    {
        CORE_TRACE("VBO Binded with ID - {}", ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    // Unbind the VBO from current usage
    void VBO::Unbind() const
    {
        CORE_TRACE("VBO Unbinded with ID - {}", ID);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};