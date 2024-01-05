#include "RBO.hpp"

namespace Core
{

	// Initialize the RBO & store it in depth buffer
	RBO::RBO(int width, int height)
	{
		glGenRenderbuffers(1, &ID);
		CORE_TRACE("Created a RBO with ID - {}", ID);
		Bind();
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	}

	// Delete the RBO
	RBO::~RBO()
	{
		CORE_TRACE("Deleted RBO with ID - {}", ID);
		glDeleteRenderbuffers(1, &ID);
	}

	// Binds the RBO for current use
	void RBO::Bind() const
	{
		CORE_TRACE("Binding RBO with ID - {}", ID);
		glBindRenderbuffer(GL_RENDERBUFFER, ID);
	}

	// Unbind the RBO from current usage
	void RBO::Unbind() const
	{
		CORE_TRACE("Unbinding RBO with ID - {}", ID);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	// Attach the RBO to the FBO
	void RBO::AttachRBO() const
	{
		CORE_TRACE("Attaching RBO with ID - {} to Framebuffer", ID);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, ID);  
	}
};