#include "RBO.hpp"

// Initialize the RBO & store it in depth buffer
RBO::RBO(int width, int height)
{
	glGenRenderbuffers(1, &ID);
    Bind();
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
}

// Delete the RBO
RBO::~RBO()
{
	glDeleteRenderbuffers(1, &ID);
}

// Binds the RBO for current use
void RBO::Bind() const
{
	glBindRenderbuffer(GL_RENDERBUFFER, ID);
}

// Unbind the RBO from current usage
void RBO::Unbind() const
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

// Attach the RBO to the FBO
void RBO::AttachRBO() const
{
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, ID);  
}