#include "shaders.h"

GLuint sgl::createPredefinedShaderProgram(ShaderType type) {
    switch (type){
        case ShaderType::Triangle:
            return createShaderProgramFromSrc(triangleVertexSource,
                                              triangleFragmentSource);
        default:
            throw std::logic_error("Uknown shader type.");
    }

}

GLuint sgl::createShaderProgramFromFiles(const std::string& vertexPath,
                                         const std::string& fragmentPath)
{
    std::string vertexShaderCode = loadShaderSourceCode(vertexPath, "vertex");
    std::string fragmentShaderCode = loadShaderSourceCode(fragmentPath, "fragment");
    return createShaderProgramFromSrc(vertexShaderCode, fragmentShaderCode);
}

GLuint sgl::createShaderProgramFromSrc(const std::string& vertexSource,
                                       const std::string& fragmentSource)
{
    GLuint programId = glCreateProgram();

    /* ----- Vertex Shader ----- */
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vertexShaderSource = vertexSource.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

    glCompileShader(vertexShader);

    GLint vShaderCompiled = GL_FALSE;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vShaderCompiled);
    if (vShaderCompiled != GL_TRUE)
    {
        printShaderLog(vertexShader);
    }
    glAttachShader(programId, vertexShader);
    checkForErrors(__FUNCTION__);

    /* ----- Fragment Shader ----- */
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fragmentShaderSource = fragmentSource.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    glCompileShader(fragmentShader);

    GLint fShaderCompiled = GL_FALSE;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled);
    if (fShaderCompiled != GL_TRUE)
    {
        printShaderLog(fragmentShader);
    }
    glAttachShader(programId, fragmentShader);
    checkForErrors(__FUNCTION__);

    /* ----- Program ----- */
    glLinkProgram(programId);

    GLint programSuccess = GL_TRUE;
    glGetProgramiv(programId, GL_LINK_STATUS, &programSuccess);
    if (programSuccess != GL_TRUE)
    {
        printProgramLog(programId);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    checkForErrors(__FUNCTION__);

    return programId;
}

std::string sgl::loadShaderSourceCode(const std::string& path,
                                      const std::string& type)
{
    std::string shaderCode;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::badbit);

    try
    {
        shaderFile.open(path.c_str());
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        throw std::runtime_error("Error: " + type + " shader file not loaded.");
    }

    return shaderCode;
}

void sgl::useProgram(GLuint program) {
    glUseProgram(program);
    checkForErrors(__FUNCTION__);
}

void sgl::unuseProgram() {
    glUseProgram(0);
    checkForErrors(__FUNCTION__);
}

void sgl::deleteProgram(GLuint programId) {
    glDeleteProgram(programId);
    checkForErrors(__FUNCTION__);
}

void sgl::printProgramLog(GLuint program)
{
    if (glIsProgram(program))
    {
        int infoLogLength = 0;
        int maxLength = infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
        char* infoLog = new char[maxLength];
        glGetProgramInfoLog(program, maxLength, &infoLogLength, infoLog);
        if (infoLogLength > 0)
        {
            throw std::runtime_error(infoLog);
        }
        delete[] infoLog;
    }
    else
    {
        std::string errInfo = "Name ";
        std::ostringstream stm ;
        stm << program ;
        errInfo += stm.str() + " is not a program.";
        throw std::runtime_error(errInfo);
    }
}

void sgl::printShaderLog(GLuint shader)
{
    if (glIsShader(shader))
    {
        int infoLogLength = 0;
        int maxLength = infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
        char* infoLog = new char[maxLength];
        glGetShaderInfoLog(shader, maxLength, &infoLogLength, infoLog);
        if (infoLogLength > 0)
        {
            throw std::runtime_error(infoLog);
        }
        delete[] infoLog;
    }
    else
    {
        std::string errInfo = "Name ";
        std::ostringstream stm ;
        stm << shader ;
        errInfo += stm.str() + " is not a shader.";
        throw std::runtime_error(errInfo);
    }
}

