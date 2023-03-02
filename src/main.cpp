#include <stdio.h>
#include "window.h"
#include "shader.h"
#include "Renderer/transparency.h"
#include "Renderer/Batched.h"
#include "Renderer/images/image.h"
#include "Renderer/postprocessor/renderStep.h"


int main() {
     
    Render::Window w = Render::Window(800, 600, "window");
    printf("%u\n", w.GetWindow());
    glViewport(0,0, 800, 600);



    Render::shader s1 = Render::CompileShader("shaders/Default/Batch.vert", "shaders/Default/Batch.frag");
    Render::shader s2 = Render::CompileShader("shaders/Default/standard.vert", "shaders/Default/standard.frag");
    Render::shader s3 = Render::CompileShader("shaders/Sharpen/standard.vert", "shaders/Sharpen/standard.frag");
    Render::shader s4 = Render::CompileShader("shaders/Invert/standard.vert", "shaders/Invert/standard.frag");

    Render::Image::texture t = Render::Image::downloadImage("images/sheet1.png");
    Render::Image::texture t1 = Render::Image::downloadImage("images/transparent.png");
    


    Render::BatchRenderer r(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s1, &w, t1.id, glm::ivec2(1,1));
    Render::transRenderer r2(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s2, &w);
    
    Render::Sprite* s = r.AddSprite(300.0f, 300.0f, glm::vec4(0.0f, 0.0f, 1.0f, 100.0f), glm::vec3(0.0f, 0.0f, -10.0f), 0);
    Render::Sprite* sp2 = r2.AddSprite(1000.0f, 1000.0f, glm::vec4(1.0f, 1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), t.id);
   
    bool d = true;

    Render::FrameStep f(&w, s3);
    Render::FrameStep f2(&w, s4);

    
    

    while (!glfwWindowShouldClose(w.GetWindow())) {
        f.Begin();

        r.Draw();
        r2.Draw();

        f.Draw(0);
        //f2.Draw(0);
        


        glfwSwapBuffers(w.GetWindow());
        glfwPollEvents();
    }


    return 0;
   
}