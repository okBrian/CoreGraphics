#pragma once
#include <fstream>
#include <unordered_map>
#include <string>

#include <glad/glad.h>
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

		template<typename T>
		inline void setUniform4(const std::string& name, T v0, T v1, T v2, T v3)
		{
			CORE_ERROR("Uniform4 Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform4<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
		{
			CORE_TRACE("Uniform4f {} set", name);
			glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
		}
		template<>
		inline void setUniform4<GLint>(const std::string& name, GLint v0, GLint v1, GLint v2, GLint v3)
		{
			CORE_TRACE("Uniform4i {} set", name);
			glUniform4i(getUniformLocation(name), v0, v1, v2, v3);
		}
		template<>
		inline void setUniform4<GLuint>(const std::string& name, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
		{
			CORE_TRACE("Uniform4ui {} set", name);
			glUniform4ui(getUniformLocation(name), v0, v1, v2, v3);
		}


		template<typename T>
		inline void setUniform4v(const std::string& name, T v0)
		{
			CORE_ERROR("Uniform4v Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform4v<GLfloat*>(const std::string& name, GLfloat* v0) 
		{
			CORE_TRACE("Uniform4fv {} set", name);
			glUniform4fv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform4v<GLint*>(const std::string& name, GLint* v0)
		{
			CORE_TRACE("Uniform4iv {} set", name);
			glUniform4iv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform4v<GLuint*>(const std::string& name, GLuint* v0)
		{
			CORE_TRACE("Uniform4uiv {} set", name);
			glUniform4uiv(getUniformLocation(name), 1, v0);
		}

		template<typename T>
		inline void setUniform3(const std::string& name, T v0, T v1, T v2)
		{
			CORE_ERROR("Uniform3 Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform3<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1, GLfloat v2)
		{
			CORE_TRACE("Uniform3f {} set", name);
			glUniform3f(getUniformLocation(name), v0, v1, v2);
		}
		template<>
		inline void setUniform3<GLint>(const std::string& name, GLint v0, GLint v1, GLint v2)
		{
			CORE_TRACE("Uniform3i {} set", name);
			glUniform3i(getUniformLocation(name), v0, v1, v2);
		}
		template<>
		inline void setUniform3<GLuint>(const std::string& name, GLuint v0, GLuint v1, GLuint v2)
		{
			CORE_TRACE("Uniform3ui {} set", name);
			glUniform3ui(getUniformLocation(name), v0, v1, v2);
		}

		template<typename T>
		inline void setUniform3v(const std::string& name, T v0)
		{
			CORE_ERROR("Uniform3v Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform3v<GLfloat*>(const std::string& name, GLfloat* v0) 
		{
			CORE_TRACE("Uniform3fv {} set", name);
			glUniform3fv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform3v<GLint*>(const std::string& name, GLint* v0)
		{
			CORE_TRACE("Uniform3iv {} set", name);
			glUniform3iv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform3v<GLuint*>(const std::string& name, GLuint* v0)
		{
			CORE_TRACE("Uniform4uiv {} set", name);
			glUniform3uiv(getUniformLocation(name), 1, v0);
		}

		template<typename T>
		inline void setUniform2(const std::string& name, T v0, T v1)
		{
			CORE_ERROR("Uniform2 Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform2<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1)
		{
			CORE_TRACE("Uniform2f {} set", name);
			glUniform2f(getUniformLocation(name), v0, v1);
		}
		template<>
		inline void setUniform2<GLint>(const std::string& name, GLint v0, GLint v1)
		{
			CORE_TRACE("Uniform2i {} set", name);
			glUniform2i(getUniformLocation(name), v0, v1);
		}
		template<>
		inline void setUniform2<GLuint>(const std::string& name, GLuint v0, GLuint v1)
		{
			CORE_TRACE("Uniform2ui {} set", name);
			glUniform2ui(getUniformLocation(name), v0, v1);
		}


		template<typename T>
		inline void setUniform2v(const std::string& name, T v0)
		{
			CORE_ERROR("Uniform2v Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform2v<GLfloat*>(const std::string& name, GLfloat* v0) 
		{
			CORE_TRACE("Uniform2fv {} set", name);
			glUniform2fv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform2v<GLint*>(const std::string& name, GLint* v0)
		{
			CORE_TRACE("Uniform2iv {} set", name);
			glUniform2iv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform2v<GLuint*>(const std::string& name, GLuint* v0)
		{
			CORE_TRACE("Uniform2uiv {} set", name);
			glUniform2uiv(getUniformLocation(name), 1, v0);
		}


		template<typename T>
		inline void setUniform1(const std::string& name, T v0)
		{
			CORE_ERROR("Uniform1 Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform1<GLfloat>(const std::string& name, GLfloat v0)
		{
			CORE_TRACE("Uniform1f {} set", name);
			glUniform1f(getUniformLocation(name), v0);
		}
		template<>
		inline void setUniform1<GLint>(const std::string& name, GLint v0)
		{
			CORE_TRACE("Uniform1i {} set", name);
			glUniform1i(getUniformLocation(name), v0);
		}
		template<>
		inline void setUniform1<GLuint>(const std::string& name, GLuint v0)
		{
			CORE_TRACE("Uniform1ui {} set", name);
			glUniform1ui(getUniformLocation(name), v0);
		}


		template<typename T>
		inline void setUniform1v(const std::string& name, T v0)
		{
			CORE_ERROR("Uniform1v Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniform1v<GLfloat*>(const std::string& name, GLfloat* v0) 
		{
			CORE_TRACE("Uniform1fv {} set", name);
			glUniform1fv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform1v<GLint*>(const std::string& name, GLint* v0)
		{
			CORE_TRACE("Uniform1iv {} set", name);
			glUniform1iv(getUniformLocation(name), 1, v0);
		}
		template<>
		inline void setUniform1v<GLuint*>(const std::string& name, GLuint* v0)
		{
			CORE_TRACE("Uniform1uiv {} set", name);
			glUniform1uiv(getUniformLocation(name), 1, v0);
		}


		template<typename T>
		inline void setUniformMatfv(const std::string& name, const T& matrix) 
		{
			CORE_ERROR("UniformMatfv Type not given");
			static_assert(false);
		}
		template<>
		inline void setUniformMatfv<glm::mat2>(const std::string& name, const glm::mat2& matrix)
		{
			CORE_TRACE("Uniform2x2Matfv {} set ", name);
			glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);	
		}
		template<>
		inline void setUniformMatfv<glm::mat3>(const std::string& name, const glm::mat3& matrix)
		{
			CORE_TRACE("Uniform2x2Matfv {} set ", name);
			glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);	
		}
		template<>
		inline void setUniformMatfv<glm::mat4>(const std::string& name, const glm::mat4& matrix) 
		{
			CORE_TRACE("Uniform2x2Matfv {} set ", name);
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);	
		}

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