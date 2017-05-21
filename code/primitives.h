#ifndef SGL_PRIMITIVES_H
#define SGL_PRIMITIVES_H

#include "GL/glew.h"
#include "core.h"

namespace sgl {

    void createTriangle(GLuint& vao, GLuint& vbo);

    void drawTriangle(GLuint& vao);

    void deleteTriangle(GLuint& vao, GLuint& vbo);




}


#endif