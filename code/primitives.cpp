#include "primitives.h"

void sgl::createTriangle(GLuint& vao, GLuint& vbo) {

    GLfloat triangleVertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    checkForErrors(__FUNCTION__);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
    checkForErrors(__FUNCTION__);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    checkForErrors(__FUNCTION__);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    checkForErrors(__FUNCTION__);
}

void sgl::drawTriangle(GLuint& vao) {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    checkForErrors(__FUNCTION__);
}

void sgl::deleteTriangle(GLuint& vao, GLuint& vbo) {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}