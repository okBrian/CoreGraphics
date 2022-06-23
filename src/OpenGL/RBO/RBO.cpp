#include "RBO.hpp"

namespace Core
{

	// Initialize the RBO & store it in depth buffer
	void RBO::init(int width, int height)
	{
		CORE_DEBUG("Created a RBO with width - {0} and height - {1}", width, height);
		glGenRenderbuffers(1, &ID);
		Bind();
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	}

	// Delete the RBO
	RBO::~RBO()
	{
		CORE_DEBUG("Deleted RBO");
		glDeleteRenderbuffers(1, &ID);
	}

	// Binds the RBO for current use
	void RBO::Bind() const
	{
		CORE_DEBUG("Binding RBO");
		glBindRenderbuffer(GL_RENDERBUFFER, ID);
	}

	// Unbind the RBO from current usage
	void RBO::Unbind() const
	{
		CORE_DEBUG("Unbinding RBO");
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	// Attach the RBO to the FBO
	void RBO::AttachRBO() const
	{
		CORE_DEBUG("Attaching RBO to Framebuffer");
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, ID);  
	}
};