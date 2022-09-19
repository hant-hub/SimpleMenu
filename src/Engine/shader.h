#pragma once





namespace Render {

    typedef GLuint shader;



    shader CompileShader(const char* VertPath, const char* FragPath);




    void SetInt(shader s, int i);
    void SetFloat(shader s, float f);
    void SetBool(shader s, bool b);
    

};