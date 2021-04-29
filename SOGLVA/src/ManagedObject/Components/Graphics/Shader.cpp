#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath, bool _uselib) :use_lib(_uselib)
{
    this->setPath(vertexPath, fragmentPath);

    // will error if not check because glew shader default arg
    if (!glewInit())
        this->compile();
};

void Shader::setPath(const char* vertexPath, const char* fragmentPath)
{
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // Add aditiontional shader before the actual shader code
    std::ifstream libvShaderFile;
    std::ifstream libfShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    libvShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    libfShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        //
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        libvShaderFile.open("resources/shaders/lib.vs");
        libfShaderFile.open("resources/shaders/lib.fs");
        std::stringstream vShaderStream, fShaderStream, libvShaderStream, libfShaderStream;
        //
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        libvShaderStream << libvShaderFile.rdbuf();
        libfShaderStream << libfShaderFile.rdbuf();
        //
        vShaderFile.close();
        fShaderFile.close();
        libvShaderFile.close();
        libfShaderFile.close();
        //
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        libvertexCode = libvShaderStream.str();
        libfragmentCode = libfShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
}

void Shader::compile()
{
    if (use_lib)
    {
        vertexCode.insert(0, libvertexCode);
        fragmentCode.insert(0, libfragmentCode);
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    //
    unsigned int vertex, fragment;
    //
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    //
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    // shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");
    // delete the shaders as they're linked
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- ------------------------------ --" << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << "\n" << infoLog << "\n -- --------------------------------- --" << std::endl;
        }
    }
}
