#pragma once
#include <glad/glad.h>

#include <VBO/VBO.hpp>
#include <Logging/Logging.hpp>

namespace Core
{
	class VBOLayout;
	// Vertex Array Object: Stores the format of the vertex data and the buffer object
	class VAO
	{
	private:
		GLuint ID;
	public:
		// Initialize the VAO
		void init();
		// Destory the VAO
		~VAO();

		// Adds a VBO to the VAO
		// Offset to the first element ie - XYRGB - the offset for RGB is 8
		void AddBuffer(const VBO& vbo, VBOLayout& layout);

		// Binds the VAO for current use
		void Bind() const;
		// Unbind the VBO from current usage
		void Unbind() const;
	};
};