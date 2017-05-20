#ifndef SGL_CORE_H
#define SGL_CORE_H

#define GLEW_STATIC
#include "GL/glew.h"
#include <glm/glm.hpp>
#include <stdexcept>

namespace sgl {
    /**
     * Initializes Opengl/GLEW. In case of any error, std::runtime_error
     * is thrown.
     */
    void initialize();

    /**
     * Calls glClearColor and glClear procedures with provided parameters and
     * check for any errors. In case of an error, std::runtime_error is thrown.
     *
     * @param backgroundColor Color of cleaned color buffer.
     * @param buffersMask     Mask of buffers to clean.
     */
    void clearBuffers(glm::vec4 backgroundColor, GLbitfield buffersMask);

    /**
     * Checks for any errors related to OpenGL context and throws
     * std::runtime_error with appropriate message (error info + calling
     * function).
     *
     * @param callingFunction Name of the calling function.
     */
    void checkForErrors(const std::string& callingFunction = "unknown");
}


#endif
