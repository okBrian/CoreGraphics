#pragma once
#include <glObject.hpp>
namespace Core
{

	// Index Buffer Object: Takes an array of vertex buffers and orders them
	class IBO : public glObject
	{
	private:
		GLuint count;
	public:
		// Generates 1 IBO and gives it the data/indices from the vbo
		void init(const GLuint* data, GLuint count);
		// Deletes the IBO
		~IBO();

		// Binds the IBO for current use
		void Bind() const override;
		// Unbind the IBO from current usage
		void Unbind() const override;
		// Returns the amount of data their is
		inline unsigned int getCount() const { return count; }
	};
};