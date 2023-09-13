cmake_minimum_required(VERSION 3.15)
project(voxel-renderer)

set(CMAKE_CXX_STANDARD 17) # Set your preferred C++ standard

# Add your source files
add_executable(voxel-renderer src/main.cpp
        src/main.cpp
)

# Add any external libraries or dependencies (e.g., OpenGL, GLFW)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Link your project with the libraries
target_link_libraries(voxel-renderer OpenGL::GL glfw)

target_include_directories(voxel-renderer PRIVATE include)

