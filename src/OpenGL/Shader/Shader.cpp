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
			char* message = (char*)malloc(len * sizeof(char));
			glGetShaderInfoLog(id, len, &len, message);

			std::string typeOfShader = (type == GL_VERTEX_SHADER ? "vertex" : "fragment");
			CORE_ERROR("Failed to compile " + typeOfShader  + " shader\n" + message);

			glDeleteShader(id);
			return 0;
		}
		return id;
	}
};