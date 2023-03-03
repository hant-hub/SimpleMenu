#include <stdio.h>
#include "window.h"
#include "shader.h"
#include "Renderer/transparency.h"
#include "Renderer/Batched.h"
#include "Renderer/images/image.h"
#include "Renderer/postprocessor/renderStep.h"


int main() {
     
    Render::Window w = Render::Window(1920, 1080, "window");
    printf("%u\n", w.GetWindow());
    glViewport(0,0, 1920, 1080);

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
    glm::vec2 origin(((1 - std::cos(1.5f))/2) * (std::cos(1.5f)) +0.25f, ((1 - std::cos(1.5f))/2) * std::sin(1.5f));

    while (!glfwWindowShouldClose(w.GetWindow())) {
        s3.Use();
        glUniform1f(glGetUniformLocation(s3.ID, "scale"), scale);
        glUniform2f(glGetUniformLocation(s3.ID, "origin"), -(origin.x), origin.y);
        
        f.Draw(0);
        
        scale *= 0.99f;
        for (int i; i<1; i++) {
            geo *= geo;
        }

        origin += geo * glm::vec2(-0.1f, 0.1f);
        power++;

        glfwSwapBuffers(w.GetWindow());
        glfwPollEvents();
    }


    return 0;
   
}