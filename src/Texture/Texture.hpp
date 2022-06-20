#pragma once
#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "../Shader/Shader.hpp"

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
		Texture(std::string filePath, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
		~Texture();

		static void texUnits(Shader& shader, const char* uniform, GLint );
		void texUnit(Shader& shader, const char* uniform, GLuint unit);
		
		void Bind() const;
		void Unbind() const;

		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }
		inline GLuint getId() const { return ID; }
	};
};