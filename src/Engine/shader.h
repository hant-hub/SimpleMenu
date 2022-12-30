#pragma once





namespace Render {

    struct shader {
        GLuint ID;

        void Use() { glUseProgram(ID); }
    };



    shader CompileShader(const char* VertPath, const char* FragPath);




    void SetInt(shader s, int i, const char* name);
    void SetFloat(shader s, float f, const char* name);
    void SetBool(shader s, bool b, const char* name);
    void SetMat4(shader s, glm::mat4 m, const char* name);
    

};