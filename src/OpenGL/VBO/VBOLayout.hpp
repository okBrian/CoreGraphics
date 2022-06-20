#pragma once

#include <stdio.h>
#include <vector>

#include <glad/glad.h>

namespace Core
{

	// Vertex Buffer Element: Seperate the Buffer Object in to its type, count, and normilization
	struct VBE
	{
		GLuint type;
		GLuint count;
		GLboolean normalized;

		// Returns the size of the type ie - float, unsigned int, unsigned byte
		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
			}
			throw(errno);
			return 0;
		}
	};

	// Passes VBOs to the shader through different Layouts
	class VBOLayout
	{
	private:
		// vector that stores VBO with the same layout
		std::vector<VBE> elements;
		// Stride = Distance in bytes between vertex attributes 
		// ex. 1 XYZ or RGB and the next XYZRGB XYZRGB in this case stide for RGB is 12 
		GLuint stride;

	public:
		// Initializes stride to 0
		VBOLayout()
			: stride(0)
		{
		}

		// Template that pushes into elements of a certain type with count and adds to the stride
		template<typename T>
		void Push(GLuint count)
		{
			static_assert(false);
		}

		// Adds a vbo by type and the count also adds to the stride 
		template<>
		void Push<float>(GLuint count)
		{
			elements.push_back({ GL_FLOAT, count, GL_FALSE });
			stride += count * VBE::GetSizeOfType(GL_FLOAT);
		}
		template<>
		void Push<unsigned int>(GLuint count)
		{
			elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
			stride += count * VBE::GetSizeOfType(GL_UNSIGNED_INT);
		}
		template<>
		void Push<unsigned char>(GLuint count)
		{
			elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
			stride += count * VBE::GetSizeOfType(GL_UNSIGNED_BYTE);
		}

		// Gets the vector that holds vbo information
		inline const std::vector<VBE>& GetElements() const { return elements; }
		// Gets the stride of the vbo 
		inline unsigned int getStride() const { return stride; }

	};
};