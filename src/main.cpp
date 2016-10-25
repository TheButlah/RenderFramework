#include <Renderer.hpp>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

int main() {
  try {
    Renderer renderer(800,800,"hello world!");
  } catch (std::exception ex) {
    cerr << "Exception in main():" << endl << ex.what() << endl;
    return 1;
  }
}