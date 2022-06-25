#include "Texture.hpp"
namespace Core
{
	// Takes a texture and its parameter and converts it into unsigned char* and given to the shader
	void Texture::init(std::string filePath, GLuint slot, GLenum internalFormat, GLenum format)
	{
		Texture::slot = slot;
		Texture::filePath = filePath;
		CORE_DEBUG("Image loaded from {0} at slot - {1}", filePath, slot);
		stbi_set_flip_vertically_on_load(1);
		unsigned char* bytes = stbi_load(filePath.c_str(), &width, &height, &BPP, STBI_rgb);
		
		glActiveTexture(GL_TEXTURE0 + slot);
		glCreateTextures(GL_TEXTURE_2D, 1, &ID);
		Bind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Specify a two-dimensional texture image
		// GL_RGB = jpeg
		// GL_RGBA = png
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, bytes);

		// Generates the same picture just in smaller resolutions
		glGenerateMipmap(GL_TEXTURE_2D);
		// Unbinds the texture to prevent accidental modification
		Unbind();

		if (bytes)
			stbi_image_free(bytes);
	}
	// Delete the Texture
	Texture::~Texture()
	{
		CORE_DEBUG("Deleted Texture");
		glDeleteTextures(1, &ID);
	}
	// Pass the texture to the shader
	void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
	{
		CORE_DEBUG("Binding Texture to be sent to shader");
		// Sets up the uniform or global shader variables
		GLuint texUni = glGetUniformLocation(shader.getID(), uniform);
		shader.Bind();
		glUniform1i(texUni, unit);
	}
	// Bind the texture for current usage
	void Texture::Bind() const
	{
		CORE_DEBUG("Binding image at slot - {}", slot);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
	// Unbind the texture for current usage
	void Texture::Unbind() const
	{
		CORE_DEBUG("Unbinding image at slot - {}", slot);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
};