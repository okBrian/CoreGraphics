#pragma once
#include <fstream>
#include <unordered_map>
#include <string>

#include <glad/gl.h>
#include <Logging/Logging.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


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
		// Put the uniform in cache for easy access
		mutable std::unordered_map<std::string, GLint> UniformLocationCache;

	public:
		// Creates and Parses the Shaders
		Shader(std::string vertexPath, std::string fragmentPath);
		// Deletes the ShaderProgram
		~Shader();

		// Binds it for current use
		void Bind() const;
		// Unbinds it so you can use different shaders
		void Unbind() const;

		// Generic Uniform for 4 floats, ints, or uints
		template<typename T>
		void setUniform4(const std::string& name, T v0, T v1, T v2, T v3);
		template<>
		void setUniform4<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
		template<>
		void setUniform4<GLint>(const std::string& name, GLint v0, GLint v1, GLint v2, GLint v3);
		template<>
		void setUniform4<GLuint>(const std::string& name, GLuint v0, GLuint v1, GLuint v2, GLuint v3);

		// Generic Uniform for 4 floats*, ints*, or uints*
		template<typename T>
		void setUniform4v(const std::string& name, T v0);
		template<>
		void setUniform4v<GLfloat*>(const std::string& name, GLfloat* v0);
		template<>
		void setUniform4v<GLint*>(const std::string& name, GLint* v0);
		template<>
		void setUniform4v<GLuint*>(const std::string& name, GLuint* v0);

		// Generic Uniform for 3 floats, ints, or uints
		template<typename T>
		void setUniform3(const std::string& name, T v0, T v1, T v2);
		template<>
		void setUniform3<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1, GLfloat v2);
		template<>
		void setUniform3<GLint>(const std::string& name, GLint v0, GLint v1, GLint v2);
		template<>
		void setUniform3<GLuint>(const std::string& name, GLuint v0, GLuint v1, GLuint v2);

		// Generic Uniform for 3 floats*, ints*, or uints*
		template<typename T>
		void setUniform3v(const std::string& name, T v0);
		template<>
		void setUniform3v<GLfloat*>(const std::string& name, GLfloat* v0);
		template<>
		void setUniform3v<GLint*>(const std::string& name, GLint* v0);
		template<>
		void setUniform3v<GLuint*>(const std::string& name, GLuint* v0);

		// Generic Uniform for 2 floats, ints, or uints
		template<typename T>
		void setUniform2(const std::string& name, T v0, T v1);
		template<>
		void setUniform2<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1);
		template<>
		void setUniform2<GLint>(const std::string& name, GLint v0, GLint v1);
		template<>
		void setUniform2<GLuint>(const std::string& name, GLuint v0, GLuint v1);

		// Generic Uniform for 2 floats*, ints*, or uints*
		template<typename T>
		void setUniform2v(const std::string& name, T v0);
		template<>
		void setUniform2v<GLfloat*>(const std::string& name, GLfloat* v0);
		template<>
		void setUniform2v<GLint*>(const std::string& name, GLint* v0);
		template<>
		void setUniform2v<GLuint*>(const std::string& name, GLuint* v0);

		// Generic Uniform for 1 floats, ints, or uints
		template<typename T>
		void setUniform1(const std::string& name, T v0);
		template<>
		void setUniform1<GLfloat>(const std::string& name, GLfloat v0);
		template<>
		void setUniform1<GLint>(const std::string& name, GLint v0);
		template<>
		void setUniform1<GLuint>(const std::string& name, GLuint v0);

		// Generic Uniform for 1 floats*, ints*, or uints*
		template<typename T>
		void setUniform1v(const std::string& name, T v0);
		template<>
		void setUniform1v<GLfloat*>(const std::string& name, GLfloat* v0);
		template<>
		void setUniform1v<GLint*>(const std::string& name, GLint* v0);
		template<>
		void setUniform1v<GLuint*>(const std::string& name, GLuint* v0);
		
		// Generic Uniforms for matrices of 4x4, 3x3, and 2x2
		template<typename T>
		void setUniformMatfv(const std::string& name, const T& matrix);
		template<>
		void setUniformMatfv<glm::mat2>(const std::string& name, const glm::mat2& matrix);
		template<>
		void setUniformMatfv<glm::mat3>(const std::string& name, const glm::mat3& matrix);
		template<>
		void setUniformMatfv<glm::mat4>(const std::string& name, const glm::mat4& matrix);

		// Return the shader ID/ or the shader program
		inline GLuint getID() { return ID; }

	private:
		// Read the cache hash map and quickly return it
		GLint getUniformLocation(const std::string& name) const;
		// Get the file contents of the shader
		ShaderSource parseShader(std::string vertexPath, std::string fragmentPath);
		// Create the shader itself
		GLuint createShader(ShaderSource shaders);
		// Compile the shader for any possible errors 
		GLuint compileShader(unsigned int type, const std::string& source);
	};
}