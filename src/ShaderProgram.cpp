#include "ShaderProgram.hpp"

#include <GL/glew.h>
#include <iostream>
#include <array>

using std::cerr;
using std::endl;
using std::string;

ShaderProgram::ShaderProgram(std::vector<Shader> shaders)
  : programID(glCreateProgram()){
  if (shaders.size() == 0) {
    cerr<< "Tried to initialize a shader program without any shaders!" << endl;
    glDeleteProgram(programID);
    throw std::exception();
  }
  for (Shader& shader : shaders) {
    glAttachShader(programID,shader.shaderID);
  }
  glLinkProgram(programID);
  GLint linkStatus = 0;
  glGetProgramiv(programID,GL_LINK_STATUS,&linkStatus);
  if (linkStatus != GL_TRUE) {
    GLint logSize = 0;
    glGetProgramiv(programID,GL_INFO_LOG_LENGTH,&logSize);
    std::array<GLchar,logSize> infoLog;
    glGetProgramInfoLog(programID, logSize, nullptr, &infoLog[0]);

    //We don't need the program anymore
    glDeleteProgram(programID);
    //Don't leak shaders
    for (Shader& shader : shaders) {
      glDeleteShader(shader.shaderID);
    }

    cerr << "Error: shader program failed to link!" << endl;
    cerr << "Error ID: " << linkStatus << endl;
    cerr << "Error message: " << endl;
    string msg(infoLog.data());
    cerr << msg << endl;

    throw std::exception();
  }

  //Detach shaders after a sucessful link
  for (Shader& shader : shaders) {
    glDetachShader(programID,shader.shaderID);
  }
}

ShaderProgram::~ShaderProgram() {
  glDeleteProgram(programID);
}
