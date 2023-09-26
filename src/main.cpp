//
// Created by Reagan Little on 9/11/23.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// can resize the viewport if the user resizes the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    //initialize glfw and give hints about version and profile
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //if the os is apple it runs this line
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    //create window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //makes the window the current context
    glfwMakeContextCurrent(window);

    //We register the callback functions after we've created the window and before the render loop is initiated.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //loads the address of opengl func pointers
    // glfwGetProcAddress is os-specific and it gets the correct one
    if (!gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    // RENDER LOOP!!
    // glfwWindowShouldClose checks if glfw has been told to close
    // glfwPollEvents checks if any events are triggered, updates the window state, and calls corresponding funcs
    // glfwSwapBuffers swaps the color buffer that is used to render the colors, and shows it as output
    // this is what double buffering is!
    while (!glfwWindowShouldClose(window)) {

        //input
        processInput(window);

        //rendering commands here
        glClearColor(0.5f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // properly clean/delete all of glfw's allocated resources
    glfwTerminate();


    return 0;
}

// can resize the viewport if the user resizes the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    // when esc pressed, closes window
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
