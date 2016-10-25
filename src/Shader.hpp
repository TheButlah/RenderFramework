#pragma once

#include <string>

class Shader {
  public:
    const int shaderID;
    const int shaderType;

    /**
     * Creates a new GLSL shader and stores its id.
     * This id can then be used in OpenGL calls.
     * @param type       The type of shader, such as GLES20.GL_VERTEX_SHADER
     *                   or GLES20.GL_FRAGMENT_SHADER
     * @param shaderCode The code of the shader, with newline characters.
     */
    Shader(int type, std::string shaderCode);
    ~Shader();
    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
};


