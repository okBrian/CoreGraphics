#pragma once
#include <glad/glad.h>

// Index Buffer Object: Takes an array of vertex buffers and orders them
class IBO
{
private:
	GLuint ID;
	GLuint count;
public:
	// Generates 1 IBO and gives it the data/indices from the vbo
	IBO(const GLuint* data, GLuint count);
	// Deletes the IBO
	~IBO();

	// Binds the IBO for current use
	void Bind() const;
	// Unbind the IBO from current usage
	void Unbind() const;
	// Returns the amount of data their is
	inline unsigned int getCount() const { return count; }
};