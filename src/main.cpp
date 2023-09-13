//
// Created by Reagan Little on 9/11/23.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
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

}