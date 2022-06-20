#pragma once
#include <array>

#include <glad/glad.h>

#include <VBO/VBO.hpp>
#include <VAO/VAO.hpp>
#include <RBO/RBO.hpp>
#include <VBO/VBOLayout.hpp>

namespace Core
{

    // FrameBuffer Object: Collection of multiple buffer that can allow for post proccessing effects
    class FBO
    {
    private:
        GLuint ID;
        GLuint TextureID;
        VBOLayout layout;
    public:
        // Creates the FBO, FBOTexture, and automatically connects the RBO to the FBO
        FBO(VBOLayout layout, GLvoid* data, GLuint size, int width, int height);
        ~FBO();

        void Bind() const;
        void Unbind() const;
        static inline bool isComplete() { return (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE); }
    };
};