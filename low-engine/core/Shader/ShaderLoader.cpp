//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  ShaderLoader.cpp - 03/28/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "ShaderLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

//GLuint compileShader(const GLchar* source, GLenum type)
//{
//  auto id = glCreateShader(type);
//
//  glShaderSource(id, 1, &source, nullptr);
//  glCompileShader(id);
//
//  GLint isSuccess;
//  GLchar infoLog[512];
//
//  glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);
//
//  if (!isSuccess)
//  {
//    glGetShaderInfoLog(id, 512, nullptr, infoLog);
//    throw std::runtime_error("Error compiling shader: " + std::string(infoLog));
//  }
//
//  return id;
//}
//
//std::string getSource(const std::string& sourceFile, const std::string& type)
//{
//  std::ifstream inFile("Data/Shaders/" + sourceFile + "_" + type + ".glsl");
//  std::string source;
//  std::stringstream stringStream;
//
//  if (!inFile.is_open())
//  {
//    throw std::runtime_error("Could not open shader file: " + sourceFile);
//  }
//
//  stringStream << inFile.rdbuf();
//  source = stringStream.str();
//
//  return source;
//}
//
//GLuint createProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
//{
//  auto id = glCreateProgram();
//
//  glAttachShader(id, vertexShaderID);
//  glAttachShader(id, fragmentShaderID);
//
//  glLinkProgram(id);
//
//  return id;
//}

std::string lowengine::ShaderLoader::ReadShader(char * filename)
{
  std::string shaderCode;
  std::ifstream file(filename, std::ios::in);

  if (!file.good())
  {
    std::cout << "Can't read file " << filename << std::endl;
    std::terminate();
  }

  file.seekg(0, std::ios::end);
  shaderCode.resize((unsigned int)file.tellg());
  file.seekg(0, std::ios::beg);
  file.read(&shaderCode[0], shaderCode.size());
  file.close();

  return shaderCode;
}

GLuint lowengine::ShaderLoader::CreateShader(GLenum shaderType, std::string source, const char * shaderName)
{
  int compile_result = 0;

  GLuint shader = glCreateShader(shaderType);
  const char *shader_code_ptr = source.c_str();
  const int shader_code_size = source.size();

  glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
  glCompileShader(shader);
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);

  if (compile_result == GL_FALSE) {

    int info_log_length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);

    std::vector<char> shader_log(info_log_length);
    glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);

    std::cout << "ERROR compiling shader: " << shaderName << std::endl
      << &shader_log[0] << std::endl;

    return 0;
  }
  return shader;

}

GLuint lowengine::ShaderLoader::CreateProgram(char * VertexShaderFilename, char * FragmentShaderFilename)
{
  std::string vertex_shader_code = ReadShader(VertexShaderFilename);
  std::string fragment_shader_code = ReadShader(FragmentShaderFilename);

  GLuint vertex_shader =
    CreateShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
  GLuint fragment_shader =
    CreateShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

  int link_result = 0;

  GLuint program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &link_result);

  if (link_result == GL_FALSE) {
    int info_log_length = 0;

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
    std::vector<char> program_log(info_log_length);

    glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
    std::cout << "Shader Loader : LINK ERROR" << std::endl
      << &program_log[0] << std::endl;

    return 0;
  }
  return program;
}
