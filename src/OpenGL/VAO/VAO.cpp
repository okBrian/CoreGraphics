#include "VAO.hpp"
#include <OpenGL/VBO/Layout.hpp>


namespace Core
{
	// Initialize the VAO
	VAO::VAO()
	{
		glGenVertexArrays(1, &ID);
		CORE_TRACE("VAO initialized with ID - {}", ID);
		Bind();
	}

	// Destory the VAO
	VAO::~VAO()
	{
		CORE_TRACE("VAO deleted");
		glDeleteVertexArrays(1, &ID);
	}

	// Adds a VBO to the VAO
	// Offset to the first element ie - XYRGB - the offset for RGB is 8
	void VAO::addBuffer(const VBO& vbo, Layout& layout)
	{
		Bind();
		vbo.Bind();
		// Gets the vector storing the information about vbos
		const auto& elements = layout.GetElements();
		uintptr_t  offset = 0;
		// Itterates through elements to access
		for (int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			CORE_TRACE("Adding element with count - {0}, type - {1}, normalized - {2} and stride of {3}", element.count, element.type, element.normalized, layout.getStride());
			// Enables layout
			glEnableVertexAttribArray(i);
			// specify the location and data format of the array of vertex attributes at index
			glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset);
			// Goes forward the count * type to get to the next vertex attributes
			offset += element.count * element.sizeOfType;
		}
	}

	// Binds the VAO for current use
	void VAO::Bind() const
	{
		CORE_TRACE("Binding the VAO");
		glBindVertexArray(ID);
	}


	// Unbind the VBO from current usage
	void VAO::Unbind() const
	{
		CORE_TRACE("Unbinding the VAO");
		glBindVertexArray(0);
	}
};