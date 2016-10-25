set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

#Tell cmake where to put the executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

#Dont build the unneeded stuff from glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)

add_library(glew STATIC external/glew/src/glew.c)
include_directories(external/glew/include)

#Add the include directory to the compiler's include locations
include_directories(include)

#Add glm include directory
include_directories(external/glm)

set(SOURCE_FILES main.cpp Renderer.cpp Camera.cpp Shader.cpp ShaderProgram.cpp ShaderProgram.hpp)
add_executable(RenderFramework ${SOURCE_FILES})

target_link_libraries(RenderFramework glfw glew)