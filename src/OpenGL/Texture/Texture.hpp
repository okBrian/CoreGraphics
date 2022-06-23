#pragma once
#include <glad/glad.h>

#include <stb_image.h>

#include <Shader/Shader.hpp>
#include <Logging/Logging.hpp>
namespace Core
{
	class Texture
	{
	private:
		GLuint ID;
		GLenum type;
		GLuint slot;
		std::string filePath;
		int width, height, BPP;

	public:
		// Takes a texture and its parameter and converts it into unsigned char* and given to the shader
		void init(std::string filePath, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
		// Destroy Texture
		~Texture();
		// Pass the texture to the shader
		void texUnit(Shader& shader, const char* uniform, GLuint unit);
		// Bind the texture for current usage
		void Bind() const;
		// Unbind the texture for current usage
		void Unbind() const;
		// Getters for Class Member Variables
		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }
		inline GLuint getID() const { return ID; }
	};
};