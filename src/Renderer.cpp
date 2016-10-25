#include "Renderer.hpp"

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ShaderProgram.hpp"
#include "Camera.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Renderer::Impl {
  public:
    Impl(int width, int height, string title);
    ~Impl();
  private:
    const int WIDTH, HEIGHT;
    const string TITLE;

    const Camera camera;
    //ShaderProgram shaderProgram;
    glm::mat4 viewProjectionMatrix;
    glm::mat4 projectionMatrix;
};

Renderer::Impl::Impl(int width, int height, string title)
  : WIDTH(width), HEIGHT(height), TITLE(title),
    camera(Camera(50.0f,30.0f,50.0f,-45.0f,135.0f,0.0f)) {
  if (!glfwInit()) {
    cerr << "Failed to initialize GLFW!" << endl;
    throw std::exception();
  }
  glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //To make Macs happy, this should not be needed (?)
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  //We don't want the old OpenGL
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window;
  window = glfwCreateWindow(WIDTH, HEIGHT, TITLE.c_str(), nullptr, nullptr);
  if (window == nullptr) {
    cerr << "Failed to open GLFW window!" << endl;
    glfwTerminate();
    throw std::exception();
  }
  glfwMakeContextCurrent(window); //Initialize GLEW (?)
  glewExperimental=true; //Needed in core profile (?)
  if (glewInit() != GLEW_OK) {
    cerr << "Failed to initialize GLEW!" << endl;
    throw std::exception();
  }

  //Ensure we can capture the key press (?)
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  do {
    //Draw nothing for now

    //Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0) ;
}

Renderer::Impl::~Impl() = default;

Renderer::Renderer(int width, int height, string title)
  : impl(new Impl(width, height, title)) {}

Renderer::~Renderer() = default;
