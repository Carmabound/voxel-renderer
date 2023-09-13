//
// Created by Reagan Little on 9/11/23.
//
#include <GLFW/glfw3.h>
//#include <glad/glad.h>
#include <iostream>

void contextClues() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

/*int main() {
    std::cout << "hi";
    return 0;
}*/


int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    contextClues();

    //glfwCreateWindow(640, 480, "Hello World", NULL, NULL );
    // Create a GLFW window (even though we won't render to it)
    GLFWwindow *window = glfwCreateWindow(1, 1, "OpenGL Test", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Initialize and print OpenGL version
    const char *glVersion = reinterpret_cast<const char *>(glGetString(GL_VERSION));
    if (glVersion) {
        std::cout << "OpenGL Version: " << glVersion << std::endl;
    } else {
        std::cerr << "Failed to retrieve OpenGL version" << std::endl;
    }

    // Terminate GLFW

}