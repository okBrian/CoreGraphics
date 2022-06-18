#include "Shader.hpp"

// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(std::string filename)
{
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

	Logging::error("Could not open file " + filename);
	throw(errno);
}

// Creates and Parses the Shaders
Shader::Shader(std::string vertexPath, std::string fragmentPath)
	: ID(0)
{
	ID = CreateShader(ParseShader(vertexPath, fragmentPath));
}

// Deletes the ShaderProgram
Shader::~Shader()
{
	glDeleteProgram(ID);
}

// Binds it for current use
void Shader::Bind() const
{
	glUseProgram(ID);
}

// Unbinds it so you can use different shaders
void Shader::Unbind() const
{
	glUseProgram(0);
}

// Sets uniforms for 4 float types
void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

// Sets uniforms for 1 float types
void Shader::SetUniform1f(const std::string& name, float value)
{
	glUniform1f(GetUniformLocation(name), value);
}

// Sets uniforms for 1 integer types
void Shader::SetUniform1i(const std::string& name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

// Sets uniforms for 4x4 float matrix
void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

// Read the cache hash map and quickly return it
GLint Shader::GetUniformLocation(const std::string& name) const
{
	// If the location and name already exist in the hash map just return the location
	if (UniformLocationCache.find(name) != UniformLocationCache.end())
		return UniformLocationCache[name];
	GLint location = glGetUniformLocation(ID, name.c_str());
	UniformLocationCache[name] = location;
	return location;

	UniformLocationCache[name] = location;
	return location;
}

// Get the file contents of the shader
ShaderSource Shader::ParseShader(std::string vertexPath, std::string fragmentPath)
{
	// Vertex Shader - Proccess and Interprets indivudal verticies
	// Fragment Shader - Gives color to the rasteurized individual cells

	// Read vertexFile and fragmentFile and store the strings
	return { get_file_contents(vertexPath), get_file_contents(fragmentPath) };
}

// Create the shader itself
GLuint Shader::CreateShader(ShaderSource shaders)
{
	GLuint program = glCreateProgram();
	GLuint vs = CompileShader(GL_VERTEX_SHADER, shaders.VertexSource);
	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, shaders.FragmentSource);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

// Compile the shader for any possible errors 
GLuint Shader::CompileShader(unsigned int type, const std::string& source)
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
		Logging::error("Failed to compile " + typeOfShader  + " shader\n" + message);

		glDeleteShader(id);
		return 0;
	}
	return id;
}