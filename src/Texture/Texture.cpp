#include "Texture.hpp"

Texture::Texture(std::string filePath, GLenum texType, GLuint slot, GLenum format, GLenum pixelType)
	: type(texType), slot(slot), filePath(filePath),
	width(0), height(0), BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	unsigned char* bytes = stbi_load(filePath.c_str(), &width, &height, &BPP, STBI_rgb);

	glCreateTextures(type, 1, &ID);
	glBindTexture(type, ID);

	glTextureParameteri(ID, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTextureParameteri(ID, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Specify a two-dimensional texture image
	// GL_RGB = jpeg
	// GL_RGBA = png
	glTexImage2D(type, 0, format, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);

	// Generates the same picture just in smaller resolutions
	glGenerateMipmap(type);
	// Unbinds the texture to prevent accidental modification
	glBindTexture(type, 0);

	if (bytes)
		stbi_image_free(bytes);
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	// Sets up the uniform or global shader variables
	GLuint texUni = glGetUniformLocation(shader.getID(), uniform);
	shader.Bind();
	glUniform1i(texUni, unit);
}

void Texture::Bind()const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(type, ID);
}

void Texture::Unbind() const
{
	glBindTexture(type, 0);
}