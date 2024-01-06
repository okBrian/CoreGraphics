#include "Shader.hpp"

namespace Core
{

	// Reads a text file and outputs a string with everything in the text file
	std::string get_file_contents(std::string filename)
	{
		CORE_TRACE("Reading File contents from {}", filename);
		std::ifstream in(filename, std::ios::binary);
		if (in)
		{
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();
			return(contents);
		}

		CORE_ERROR("Could not open file " + filename);
		throw(errno);
	}

	// Creates and Parses the Shaders
	Shader::Shader(std::string vertexPath, std::string fragmentPath)
	{
		CORE_TRACE("Creating Shader from vertex - {} & fragment - {}", vertexPath, fragmentPath);
		ID = createShader(parseShader(vertexPath, fragmentPath));
	}

	// Deletes the ShaderProgram
	Shader::~Shader()
	{
		CORE_TRACE("Deleating ShaderProgram with ID - {}", ID);
		glDeleteProgram(ID);
	}

	// Binds it for current use
	void Shader::Bind() const
	{
		CORE_TRACE("Binding ShaderProgram with ID - {}", ID);
		glUseProgram(ID);
	}

	// Unbinds it so you can use different shaders
	void Shader::Unbind() const
	{
		CORE_TRACE("Unbinding ShaderProgram with ID - {}", ID);
		glUseProgram(0);
	}

	GLint getUniformLocation(const std::string& name);

	template<typename T>
	void setUniform4(const std::string& name, T v0, T v1, T v2, T v3)
	{
		CORE_ERROR("Uniform4 Type not given");
		static_assert(false);
	}
	template<>
	void setUniform4<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{
		CORE_TRACE("Uniform4f {} set", name);
		glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
	}
	template<>
	void setUniform4<GLint>(const std::string& name, GLint v0, GLint v1, GLint v2, GLint v3)
	{
		CORE_TRACE("Uniform4i {} set", name);
		glUniform4i(getUniformLocation(name), v0, v1, v2, v3);
	}
	template<>
	void setUniform4<GLuint>(const std::string& name, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	{
		CORE_TRACE("Uniform4ui {} set", name);
		glUniform4ui(getUniformLocation(name), v0, v1, v2, v3);
	}


	template<typename T>
	void setUniform4v(const std::string& name, T v0)
	{
		CORE_ERROR("Uniform4v Type not given");
		static_assert(false);
	}
	template<>
	void setUniform4v<GLfloat*>(const std::string& name, GLfloat* v0) 
	{
		CORE_TRACE("Uniform4fv {} set", name);
		glUniform4fv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform4v<GLint*>(const std::string& name, GLint* v0)
	{
		CORE_TRACE("Uniform4iv {} set", name);
		glUniform4iv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform4v<GLuint*>(const std::string& name, GLuint* v0)
	{
		CORE_TRACE("Uniform4uiv {} set", name);
		glUniform4uiv(getUniformLocation(name), 1, v0);
	}

	template<typename T>
	void setUniform3(const std::string& name, T v0, T v1, T v2)
	{
		CORE_ERROR("Uniform3 Type not given");
		static_assert(false);
	}
	template<>
	void setUniform3<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1, GLfloat v2)
	{
		CORE_TRACE("Uniform3f {} set", name);
		glUniform3f(getUniformLocation(name), v0, v1, v2);
	}
	template<>
	void setUniform3<GLint>(const std::string& name, GLint v0, GLint v1, GLint v2)
	{
		CORE_TRACE("Uniform3i {} set", name);
		glUniform3i(getUniformLocation(name), v0, v1, v2);
	}
	template<>
	void setUniform3<GLuint>(const std::string& name, GLuint v0, GLuint v1, GLuint v2)
	{
		CORE_TRACE("Uniform3ui {} set", name);
		glUniform3ui(getUniformLocation(name), v0, v1, v2);
	}

	template<typename T>
	void setUniform3v(const std::string& name, T v0)
	{
		CORE_ERROR("Uniform3v Type not given");
		static_assert(false);
	}
	template<>
	void setUniform3v<GLfloat*>(const std::string& name, GLfloat* v0) 
	{
		CORE_TRACE("Uniform3fv {} set", name);
		glUniform3fv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform3v<GLint*>(const std::string& name, GLint* v0)
	{
		CORE_TRACE("Uniform3iv {} set", name);
		glUniform3iv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform3v<GLuint*>(const std::string& name, GLuint* v0)
	{
		CORE_TRACE("Uniform4uiv {} set", name);
		glUniform3uiv(getUniformLocation(name), 1, v0);
	}

	template<typename T>
	void setUniform2(const std::string& name, T v0, T v1)
	{
		CORE_ERROR("Uniform2 Type not given");
		static_assert(false);
	}
	template<>
	void setUniform2<GLfloat>(const std::string& name, GLfloat v0, GLfloat v1)
	{
		CORE_TRACE("Uniform2f {} set", name);
		glUniform2f(getUniformLocation(name), v0, v1);
	}
	template<>
	void setUniform2<GLint>(const std::string& name, GLint v0, GLint v1)
	{
		CORE_TRACE("Uniform2i {} set", name);
		glUniform2i(getUniformLocation(name), v0, v1);
	}
	template<>
	void setUniform2<GLuint>(const std::string& name, GLuint v0, GLuint v1)
	{
		CORE_TRACE("Uniform2ui {} set", name);
		glUniform2ui(getUniformLocation(name), v0, v1);
	}


	template<typename T>
	void setUniform2v(const std::string& name, T v0)
	{
		CORE_ERROR("Uniform2v Type not given");
		static_assert(false);
	}
	template<>
	void setUniform2v<GLfloat*>(const std::string& name, GLfloat* v0) 
	{
		CORE_TRACE("Uniform2fv {} set", name);
		glUniform2fv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform2v<GLint*>(const std::string& name, GLint* v0)
	{
		CORE_TRACE("Uniform2iv {} set", name);
		glUniform2iv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform2v<GLuint*>(const std::string& name, GLuint* v0)
	{
		CORE_TRACE("Uniform2uiv {} set", name);
		glUniform2uiv(getUniformLocation(name), 1, v0);
	}


	template<typename T>
	void setUniform1(const std::string& name, T v0)
	{
		CORE_ERROR("Uniform1 Type not given");
		static_assert(false);
	}
	template<>
	void setUniform1<GLfloat>(const std::string& name, GLfloat v0)
	{
		CORE_TRACE("Uniform1f {} set", name);
		glUniform1f(getUniformLocation(name), v0);
	}
	template<>
	void setUniform1<GLint>(const std::string& name, GLint v0)
	{
		CORE_TRACE("Uniform1i {} set", name);
		glUniform1i(getUniformLocation(name), v0);
	}
	template<>
	void setUniform1<GLuint>(const std::string& name, GLuint v0)
	{
		CORE_TRACE("Uniform1ui {} set", name);
		glUniform1ui(getUniformLocation(name), v0);
	}


	template<typename T>
	void setUniform1v(const std::string& name, T v0)
	{
		CORE_ERROR("Uniform1v Type not given");
		static_assert(false);
	}
	template<>
	void setUniform1v<GLfloat*>(const std::string& name, GLfloat* v0) 
	{
		CORE_TRACE("Uniform1fv {} set", name);
		glUniform1fv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform1v<GLint*>(const std::string& name, GLint* v0)
	{
		CORE_TRACE("Uniform1iv {} set", name);
		glUniform1iv(getUniformLocation(name), 1, v0);
	}
	template<>
	void setUniform1v<GLuint*>(const std::string& name, GLuint* v0)
	{
		CORE_TRACE("Uniform1uiv {} set", name);
		glUniform1uiv(getUniformLocation(name), 1, v0);
	}


	template<typename T>
	void setUniformMatfv(const std::string& name, const T& matrix) 
	{
		CORE_ERROR("UniformMatfv Type not given");
		static_assert(false);
	}
	template<>
	void setUniformMatfv<glm::mat2>(const std::string& name, const glm::mat2& matrix)
	{
		CORE_TRACE("Uniform2x2Matfv {} set ", name);
		glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);	
	}
	template<>
	void setUniformMatfv<glm::mat3>(const std::string& name, const glm::mat3& matrix)
	{
		CORE_TRACE("Uniform2x2Matfv {} set ", name);
		glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);	
	}
	template<>
	void setUniformMatfv<glm::mat4>(const std::string& name, const glm::mat4& matrix) 
	{
		CORE_TRACE("Uniform2x2Matfv {} set ", name);
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);	
	}

	// Read the cache hash map and quickly return it
	GLint Shader::getUniformLocation(const std::string& name) const
	{
		// If the location and name already exist in the hash map just return the location
		if (UniformLocationCache.find(name) != UniformLocationCache.end())
		{
			CORE_TRACE("Found {} in cache", name);
			return UniformLocationCache[name];
		}
		GLint location = glGetUniformLocation(ID, name.c_str());
		UniformLocationCache[name] = location;
		CORE_TRACE("Adding {} to cache", name);
		return location;
	}

	// Get the file contents of the shader
	ShaderSource Shader::parseShader(std::string vertexPath, std::string fragmentPath)
	{
		// Vertex Shader - Proccess and Interprets indivudal verticies
		// Fragment Shader - Gives color to the rasteurized individual cells

		// Read vertexFile and fragmentFile and store the strings
		return { get_file_contents(vertexPath), get_file_contents(fragmentPath) };
	}

	// Create the shader itself
	GLuint Shader::createShader(ShaderSource shaders)
	{
		CORE_DEBUG("Creating Shader from Vertex Source {0} and Fragment Source {1}", shaders.VertexSource, shaders.FragmentSource);
		GLuint program = glCreateProgram();
		GLuint vs = compileShader(GL_VERTEX_SHADER, shaders.VertexSource);
		GLuint fs = compileShader(GL_FRAGMENT_SHADER, shaders.FragmentSource);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	// Compile the shader for any possible errors
	GLuint Shader::compileShader(unsigned int type, const std::string& source)
	{
		GLuint id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int len;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
			char* message = (char*)_malloca(len * sizeof(char));
			glGetShaderInfoLog(id, len, &len, message);

			std::string typeOfShader = (type == GL_VERTEX_SHADER ? "vertex" : "fragment");
			CORE_ERROR("Failed to compile " + typeOfShader  + " shader\n" + message);

			glDeleteShader(id);
			return 0;
		}
		return id;
	}
};