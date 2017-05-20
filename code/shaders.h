#ifndef SGL_SHADERS_H
#define SGL_SHADERS_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "GL/glew.h"
#include "core.h"
#include "shaders_types.h"

namespace sgl {

    /**
     * Creates shader program from vertex and fragment shader loaded from
     * specified paths. In case of any errors, std::runtime_error with
     * appropriate information is generated.
     *
     * @param vertexPath   Path to vertex shader.
     * @param fragmentPath Path to fragment shader.
     *
     * @return ID of initialized shader program.
     */
    GLuint
    createShaderProgramFromFiles(const std::string &vertexPath,
                                 const std::string &fragmentPath);

    /**
     * Creates shader program based on vertex and fragment sources passed to the
     * procedure. In case of any errors, std::runtime_error with appropriate
     * information is generated. Please note that sources can be obtain from
     * files using e.g loadShaderSourceCode procedure.
     *
     * @param vertexSource   String with source of vertex shader.
     * @param fragmentSource String with source of fragmebt shader.
     *
     * @return ID of initialized shader program.
     */
    GLuint
    createShaderProgramFromSrc(const std::string &vertexSource,
                               const std::string &fragmentSource);

    /**
     * Loads shader from a file.
     *
     * @param path Path to a shader.
     * @param type Auxiliary indicator of shader type in case of any error.
     *             It should be set to e.g. 'fragment' or 'vertex'.
     *
     * @return String with shader source.
     */
    std::string
    loadShaderSourceCode(const std::string &path, const std::string &type = "");

    /**
     * Removes program from OpenGL. In case of any error std:runtime_error will
     * be thrown.
     *
     * @param programId ID of program to delete.
     */
    void deleteProgram(GLuint programId);

    /**
     * Auxiliary function for tracing the error in shader program compilation.
     * If program is not compiled correctly its log is filled with information.
     * In such a case, the procedure will throw std::runtime_error with
     * message containing the log. If provide program's ID is not an id of
     * program existing within OpenGL context, std::runtime_error will be thrown
     * with appropriate message. Otherwise, nothing will happen.
     *
     * @param program ID of a shader program.
     */
    void printProgramLog(GLuint program);

    /**
     * Auxiliary function for tracing the error in shader compilation.
     * If a shader is not compiled correctly its log is filled with information.
     * In such a case, the procedure will throw std::runtime_error with
     * message containing the log. If provide shader's ID is not an id of
     * shader existing within OpenGL context, std::runtime_error will be thrown
     * with appropriate message. Otherwise, nothing will happen.
     *
     * @param shader ID of a shader.
     */
    void printShaderLog(GLuint shader);
}

#endif
