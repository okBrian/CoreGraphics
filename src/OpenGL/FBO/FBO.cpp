#include "FBO.hpp"

namespace Core
{

    void FBO::init(int width, int height)
    {
        FBO::width = width;
        FBO::height = height;
        CORE_DEBUG("Initializing the FBO with width - {1} and height - {2}", width, height);
        glGenFramebuffers(1, &ID);
        Bind(); 
    }

    FBO::~FBO()
    {
        CORE_DEBUG("Deleting FBO");
        glDeleteFramebuffers(1, &ID);
    }

    void FBO::AttachColorBuffer() 
    {
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
        CORE_DEBUG("Binding FBO");
        glBindFramebuffer(GL_FRAMEBUFFER, ID);
    }

    void FBO::Unbind() const
    {
        CORE_DEBUG("Unbinding FBO");
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

};
