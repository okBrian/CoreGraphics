#include "FBO.hpp"
#include <VBO/VBOLayout.hpp>

namespace Core
{

    void FBO::init(VBOLayout layout, GLvoid* data, GLuint size, int width, int height)
    {
        FBO::layout = layout;
        CORE_DEBUG("Initializing the FBO with size - {0}, width - {1}, and height - {2}", size, width, height);
        glGenFramebuffers(1, &ID);
        Bind(); 
        glGenBuffers(GL_TEXTURE_2D, &TextureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, TextureID, 0);

        RBO rbo;
        rbo.init(width, height);
        rbo.AttachRBO();

        VAO vao;
        VBO vbo;
        vbo.init(data, size, GL_STATIC_DRAW);
        vao.AddBuffer(vbo, layout);

    }

    FBO::~FBO()
    {
        CORE_DEBUG("Deleting FBO");
        glDeleteFramebuffers(1, &ID);
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