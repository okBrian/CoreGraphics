#pragma once
#include <glObject.hpp>
#include <stb_image.h>

#include <Shader/Shader.hpp>
namespace Core
{
	class Texture : public glObject
	{
	private:
		GLuint slot;
		std::string filePath;
		int width, height, BPP;

	public:
		// Takes a texture and its parameter and converts it into unsigned char* and given to the shader
		void init(std::string filePath, GLenum slot, GLenum format, GLenum pixelType);
		// Destroy Texture
		~Texture();
		// Pass the texture to the shader
		void texUnit(Shader& shader, const char* uniform, GLuint unit);
		// Bind the texture for current usage
		void Bind() const override;
		// Unbind the texture for current usage
		void Unbind() const override;
		// Getters for Class Member Variables
		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }
		inline GLuint getID() const { return ID; }
	};
};