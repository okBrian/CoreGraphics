#pragma once
#include <array>

#include <glObject.hpp>
#include <RBO/RBO.hpp>

namespace Core
{

    // FrameBuffer Object: Collection of multiple buffer that can allow for post proccessing effects
    class FBO : public glObject
    {
    private:
        GLuint TextureID;
        int width, height;
    public:
        // Creates the FBO, FBOTexture, and automatically connects the RBO to the FBO
        void init(int width, int height);
        ~FBO();
        void AttachColorBuffer();
        void Bind() const override;
        void Unbind() const override;
        static bool isComplete() { return (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE); }
        void BindTexture() const { glBindTexture(GL_TEXTURE_2D, TextureID); }
    };
};