#include "IBO.hpp"

namespace Core
{
	// Generates 1 IBO and gives it the data/indices from the vbo
	IBO::IBO(const GLuint* data, GLuint count)
		: count(count)
	{
		CORE_DEBUG("Created IBO with count - {}", count);
		// Generates 1 name for Index Buffer Object
		glGenBuffers(1, &ID);
		// Bind the buffer for your usage
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		// Set the data used for in GL_ELEMENT_ARRAY_BUFFER  
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	}

	// Deletes the IBO
	IBO::~IBO()
	{
		CORE_DEBUG("Deleting IBO");
		glDeleteBuffers(1, &ID);
	}

	// Binds the IBO for current use
	void IBO::Bind() const
	{
		CORE_DEBUG("Binding IBO");
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}
	// Unbind the IBO from current usage
	void IBO::Unbind() const
	{
		CORE_DEBUG("Unbinding IBO");
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
};