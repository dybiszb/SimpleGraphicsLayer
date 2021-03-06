#ifndef SGL_SHADERS_TYPES_H
#define SGL_SHADERS_TYPES_H

namespace sgl{
    enum class ShaderType{
        Cubemap,
        Triangle
    };

    const std::string cubemapVertexSource = "";
    const std::string cubemapFragmentSource = "";

    const std::string triangleVertexSource =
            "#version 330 core\n"
            "  \n"
            "layout (location = 0) in vec3 position;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
            "}";

    const std::string triangleFragmentSource = "#version 330 core\n"
            "\n"
            "out vec4 color;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "} ";
}

#endif
