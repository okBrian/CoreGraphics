#pragma once

#include <stdio.h>
#include <exception>
#include <vector>

#include <glad/glad.h>

#include <Logging/Logging.hpp>

#define SIZE_FLOAT 4
#define SIZE_UINT 4
#define SIZE_UBYTE 1

namespace Core
{

	// Vertex Buffer Element: Seperate the Buffer Object in to its type, count, and normilization
	struct VBE
	{
		GLuint type;
		GLuint sizeOfType;
		GLuint count;
		GLboolean normalized;
	};

	// Passes VBOs to the shader through different Layouts
	class Layout
	{
	private:
		// vector that stores VBO with the same layout
		std::vector<VBE> elements;
		// Stride = Distance in bytes between vertex attributes 
		// ex. 1 XYZ or RGB and the next XYZRGB XYZRGB in this case stide for RGB is 12 
		GLuint stride;

	public:
		Layout()
			: stride(0)
		{
		}

		// Template that pushes into elements of a certain type with count and adds to the stride
		template<typename T>
		void Push(GLuint count)
		{
			CORE_ERROR("Push type not given");
			throw std::runtime_error("Push type not given");
		}

		// Adds a vbo by type and the count also adds to the stride
		template<>
		void Push<GLfloat>(GLuint count)
		{
			CORE_DEBUG("Pushing GL_FLOATS, count - {0}", count);
			elements.push_back({ GL_FLOAT, SIZE_FLOAT, count, GL_FALSE });
			stride += count * SIZE_FLOAT;
		}
		template<>
		void Push<GLuint>(GLuint count)
		{
			CORE_DEBUG("Pushing GL_UNSIGNED_INT, count - {0}", count);
			elements.push_back({ GL_UNSIGNED_INT, SIZE_UINT, count, GL_FALSE });
			stride += count * SIZE_UINT;
		}
		template<>
		void Push<GLubyte>(GLuint count)
		{
			CORE_DEBUG("Pushing GL_UNSIGNED_BYTE, count - {0}", count);
			elements.push_back({ GL_UNSIGNED_BYTE, SIZE_UBYTE, count, GL_TRUE });
			stride += count * SIZE_UBYTE;
		}

		// Gets the vector that holds vbo information
		inline const std::vector<VBE>& GetElements() const { return elements; }
		// Gets the stride of the vbo
		inline unsigned int getStride() const { return stride; }

	};
};