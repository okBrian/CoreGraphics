#pragma once
#include <array>
#include <glad/gl.h>
#include <Logging/Logging.hpp>
#include <RBO/RBO.hpp>

namespace Core
{

    // FrameBuffer Object: Collection of multiple buffer that can allow for post proccessing effects
    class FBO
    {
    private:
        GLuint ID, TextureID;
        int width, height;
    public:
        // Creates the FBO, FBOTexture, and automatically connects the RBO to the FBO
        FBO(int width, int height);
        ~FBO();
        void AttachColorBuffer();
        void Bind() const;
        void Unbind() const;
        static bool isComplete() { return (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE); }
        void BindTexture() const { glBindTexture(GL_TEXTURE_2D, TextureID); }
    };
};