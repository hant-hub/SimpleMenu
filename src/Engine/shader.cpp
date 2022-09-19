#include "shader.h"


namespace Render {
    
    
    shader CompileShader(const char* VertPath, const char* FragPath) {
        std::string VertCode;
        std::string FragCode;

        std::ifstream VertFile;
        std::ifstream FragFile;

        VertFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        FragFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            VertFile.open(VertPath);
            FragFile.open(FragPath);

            std::stringstream VertBuf, FragBuf;
            VertBuf << VertFile.rdbuf();
            FragBuf << FragFile.rdbuf();

            VertFile.close();
            FragFile.close();

            VertCode = VertBuf.str();
            FragCode = FragBuf.str();

        } catch(std::ifstream::failure e) {
            std::cout << "Error: Failed to read shaders \n" << e.what() << std::endl;
        }

        const char* RVertCode = VertCode.c_str();
        const char* RFragCode = FragCode.c_str();

        unsigned int vertex, fragment;
        int success;
        char infolog[512];

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &RVertCode, NULL);
        glCompileShader(vertex);

        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertex, 512, NULL, infolog);
            std::cout << "Error: Vertex Shader failed to compile\n" << infolog << std::endl;
        }

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &RFragCode, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragment, 512, NULL, infolog);
            std::cout << "Error: Fragment Shader failed to compile\n" << infolog << std::endl;
        }


        unsigned int ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(ID, 512, NULL, infolog);
            std::cout << "Error: Program Linking Failed\n" << infolog << std::endl;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);


        return ID;
    }


}