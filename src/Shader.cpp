#include "Shader.hpp"
#include <GL/glew.h>
#include <iostream>
#include <vector>

using std::cerr;
using std::endl;
using std::string;

Shader::Shader(int type, std::string shaderCode)
  : shaderType(type), shaderID(glCreateShader(type)){
  const char* str = shaderCode.c_str();
  glShaderSource(shaderID, 1, &str, nullptr);
  glCompileShader(shaderID);
  GLint success = 0;
  glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
  if (success != GL_TRUE) {
    GLint logSize = 0;
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logSize);
    std::vector<GLchar> errorLog(logSize);
    glGetShaderInfoLog(shaderID, logSize, nullptr, &errorLog[0]);
    glDeleteShader(shaderID);
    cerr << "Error: shader failed to compile!" << endl;
    cerr << "Error ID: " << success << endl;
    cerr << "Error message: " << endl;
    string msg(errorLog.data());
    cerr << msg << endl;
    throw std::exception();
  }
}

Shader::~Shader() {
  glDeleteShader(shaderID);
}