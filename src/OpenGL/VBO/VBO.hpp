#pragma once 
#include <glObject.hpp>

namespace Core
{
    // Vertex Buffer Object: Uploading Vertex Data to the Graphics Card
    class VBO : public glObject
    {
    public:
        // Add Data to be uploaded to the Graphics Card
        void init(GLvoid* data, GLuint size, GLenum usage);
        // Delete the Object
        ~VBO();

        // Bind the VBO for current usage
        void Bind() const override;
        // Unbind the VBO from current usage
        void Unbind() const override;
    };
};