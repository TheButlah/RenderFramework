#pragma once

#include <memory>
#include <string>

class Renderer {
  public:
    Renderer(int width, int height, std::string title);
    ~Renderer();
  private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
