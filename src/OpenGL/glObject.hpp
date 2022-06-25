#pragma once
#include <Logging/Logging.hpp>
#include <glad/glad.h>

class glObject
{
	protected:
		GLuint ID;
	public:
		glObject(): ID(0) {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
};