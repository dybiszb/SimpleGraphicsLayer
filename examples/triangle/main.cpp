#include "core.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "primitives.h"
#include "shaders.h"

GLFWwindow* window;
glm::vec4 backgroundColor(0.2f, 0.3f, 0.3f, 1.0f);
GLuint vao, vbo;
GLuint triangleShader;

void render() {
    // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
    glfwPollEvents();

    try {
        sgl::clearBuffers(backgroundColor, GL_COLOR_BUFFER_BIT);
        sgl::useProgram(triangleShader);
        sgl::drawTriangle(vao);
        sgl::unuseProgram();
    }catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    glfwSwapBuffers(window);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    try{
        sgl::initialize();
    }catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    sgl::createTriangle(vbo, vao);
    triangleShader = sgl::createPredefinedShaderProgram(sgl::ShaderType::Triangle);

    // Game loop
    while (!glfwWindowShouldClose(window)) render();

    sgl::deleteTriangle(vao, vbo);
    glfwTerminate();
    return 0;
}
