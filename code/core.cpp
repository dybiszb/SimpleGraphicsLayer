#include "core.h"

void sgl::initialize() {
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("Failed to initialize GLEW");
    }

    checkForErrors(__FUNCTION__);
}

void sgl::clearBuffers(glm::vec4 bcColor, GLbitfield buffersMask) {
    glClearColor(bcColor.r, bcColor.g, bcColor.b, bcColor.a);
    glClear(buffersMask);
    checkForErrors(__FUNCTION__);
}

void sgl::checkForErrors(const std::string& callingFunction) {
    GLenum errCode;
    std::string errString;
    if ((errCode = glGetError()) != GL_NO_ERROR) {
        errString = "Error Message: ";
        errString.append((const char *) gluErrorString(errCode));
        errString.append(" | Calling function: " + callingFunction);
        throw std::runtime_error(errString);
    }
}