#include "FBO.hpp"
#include <VBO/VBOLayout.hpp>

FBO::FBO(VBOLayout layout, GLvoid* data, GLuint size, int width, int height)
{
    glGenFramebuffers(1, &ID);
    Bind(); 
    glGenBuffers(GL_TEXTURE_2D, &TextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, TextureID, 0);

    RBO rbo(width, height);
    rbo.AttachRBO();

    VAO vao;
    VBO vbo(data, size, GL_STATIC_DRAW);
    vao.AddBuffer(vbo, layout);

}

FBO::~FBO()
{
    glDeleteFramebuffers(1, &ID);
}

void FBO::Bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, ID);
}

void FBO::Unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}