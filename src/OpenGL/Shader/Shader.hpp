#pragma once
#include <fstream>
#include <unordered_map>
#include <string>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Logging/Logging.hpp>

namespace Core
{
	// Reads a text file and outputs a string with everything in the text file
	std::string get_file_contents(std::string filename);

	// Struct that stores the path to the Vertex and Fragment Shader
	struct ShaderSource
	{
		std::string VertexSource, FragmentSource;
	};

	// Shader: Used to read the shader to apply during the graphics pipeline
	class Shader
	{
	private:
		GLuint ID;
		// mutable so modifiable by a const function
		// Put the uniform in cache for easy access
		mutable std::unordered_map<std::string, GLint> UniformLocationCache;

	public:
		// Creates and Parses the Shaders
		void init(std::string vertexPath, std::string fragmentPath);
		// Deletes the ShaderProgram
		~Shader();

		// Binds it for current use
		void Bind() const;
		// Unbinds it so you can use different shaders
		void Unbind() const;

		// Sets uniforms for 4 float types
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		// Sets uniforms for 1 float types
		void SetUniform1f(const std::string& name, float value);
		// Sets uniforms for 1 integer types
		void SetUniform1i(const std::string& name, int value);
		// Sets uniforms for 4x4 float matrix
		void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
		// Return the shader ID/ or the shader program 
		inline GLuint getID() { return ID; }

	private:
		// Read the cache hash map and quickly return it
		GLint GetUniformLocation(const std::string& name) const;
		// Get the file contents of the shader
		ShaderSource ParseShader(std::string vertexPath, std::string fragmentPath);
		// Create the shader itself
		GLuint CreateShader(ShaderSource shaders);
		// Compile the shader for any possible errors 
		GLuint CompileShader(unsigned int type, const std::string& source);
	};
};