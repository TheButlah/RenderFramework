#pragma once

#include <memory>

class Renderer {
  public:
    Renderer();
    ~Renderer();
  private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
