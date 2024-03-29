#include "FBO.hpp"

namespace Core
{

    FBO::FBO(int width, int height)
        : width(width), height(height)
    {
        glGenFramebuffers(1, &ID);
        CORE_TRACE("Initializing the FBO with ID - {}", ID);
        Bind();
    }   

    FBO::~FBO()
    {
        CORE_TRACE("Deleting FBO with ID - {}", ID);
        glDeleteFramebuffers(1, &ID);
    }

    void FBO::AttachColorBuffer() 
    {
        CORE_TRACE("Attaching Texture to FBO with ID {}", ID);
        glGenTextures(1, &TextureID);
        glBindTexture(GL_TEXTURE_2D, TextureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // Prevents edge bleeding
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Prevents edge bleeding
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, TextureID, 0);
    }

    void FBO::Bind() const
    {
        CORE_TRACE("Binding FBO with ID - {}", ID);
        glBindFramebuffer(GL_FRAMEBUFFER, ID);
    }

    void FBO::Unbind() const
    {
        CORE_TRACE("Unbinding FBO with ID - {}", ID);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

};
