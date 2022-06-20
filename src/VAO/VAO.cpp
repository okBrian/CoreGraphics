#include "VAO.hpp"
#include <VBO/VBOLayout.hpp>


namespace Core
{
	// Initialize the VAO
	VAO::VAO()
		: ID(0)
	{
		glGenVertexArrays(1, &ID);
	}

	// Destory the VAO
	VAO::~VAO()
	{
		glDeleteVertexArrays(1, &ID);
	}

	// Adds a VBO to the VAO
	// Offset to the first element ie - XYRGB - the offset for RGB is 8
	void VAO::AddBuffer(const VBO& vbo, VBOLayout& layout)
	{
		Bind();
		vbo.Bind();
		// Gets the vector storing the information about vbos
		const auto& elements = layout.GetElements();
		GLuint offset = 0;
		// Itterates through elements to access 
		for (int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			// Enables layout
			glEnableVertexAttribArray(i);
			// specify the location and data format of the array of vertex attributes at index
			glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset);
			// Goes forward the count * type to get to the next vertex attributes
			offset += element.count * VBE::GetSizeOfType(element.type);
		}
	}

	// Binds the VAO for current use
	void VAO::Bind() const
	{
		glBindVertexArray(ID);
	}


	// Unbind the VBO from current usage
	void VAO::Unbind() const
	{
		glBindVertexArray(0);
	}
};