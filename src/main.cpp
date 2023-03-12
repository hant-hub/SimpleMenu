#include <stdio.h>
#include "window.h"
#include "shader.h"
#include "inputs.h"
#include "Renderer/transparency.h"
#include "Renderer/Batched.h"
#include "Renderer/images/image.h"
#include "Renderer/postprocessor/renderStep.h"


glm::vec2 iter(glm::vec2 input, glm::vec2 c) {
    float real = input.x;
    float complex = input.y;

    return glm::vec2(real*real - complex*complex, 2.0f * real * complex) + c;
};



int main() {
     
    Render::Window w = Render::Window(1080, 1080, "window");
    printf("%u\n", w.GetWindow());
    glViewport(0,0, 1080, 1080);

    glfwWindowHint(GLFW_SAMPLES, 32);
    glEnable(GL_MULTISAMPLE);

    Render::shader s1 = Render::CompileShader("shaders/Default/Batch.vert", "shaders/Default/Batch.frag");
    Render::shader s2 = Render::CompileShader("shaders/Default/standard.vert", "shaders/Default/standard.frag");
    Render::shader s3 = Render::CompileShader("shaders/MandelBrot/standard.vert", "shaders/MandelBrot/standard.frag");


    Render::Image::texture t = Render::Image::downloadImage("images/sheet1.png");
    Render::Image::texture t1 = Render::Image::downloadImage("images/transparent.png");
    


    Render::transRenderer r(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s1, &w);
    
    Render::Sprite* s = r.AddSprite(w.GetWidth(), w.GetHeight(), glm::vec4(1.0f, 1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -10.0f), 0);
    
   
    bool d = true;

    Render::FrameStep f(&w, s3);

    float scale = 4.0f;
    int power = 1;
    float geo = 0.0015;
    glm::vec2 target(-1.907352157f, 0.001985254f);
    glm::vec2 origin(0,0);
    glm::vec2 constant(0,0);

    while (!glfwWindowShouldClose(w.GetWindow())) {
        s3.Use();
        glUniform1f(glGetUniformLocation(s3.ID, "scale"), scale);
        constant = Render::InputReader::GetMousePos(w.GetWindow());
        glUniform2f(glGetUniformLocation(s3.ID, "constant"), (constant.x), constant.y);
        glUniform2f(glGetUniformLocation(s3.ID, "origin"), (origin.x), origin.y);
        
        f.Draw(0);
        
        if (scale > 0.0005f && Render::InputReader::GetKeyState(w.GetWindow(), GLFW_KEY_A)){
        scale *= 0.997f;
        //origin += (1-0.996f) * (target - origin);
        }

        //origin = iter(origin, glm::vec2(0,0));

        glfwSwapBuffers(w.GetWindow());
        glfwPollEvents();
    }


    return 0;
   
}