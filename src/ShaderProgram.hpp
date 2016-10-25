#pragma once
#include <vector>
#include "Shader.hpp"

class ShaderProgram {
  public:
    const int programID;

    ShaderProgram(std::vector<Shader> shaders);
    ~ShaderProgram();
    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram&operator=(const ShaderProgram&) = delete;
};


