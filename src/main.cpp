#include <stdio.h>
#include "window.h"
#include "shader.h"
#include "Renderer/transparency.h"
#include "Renderer/Batched.h"
#include "Renderer/images/image.h"


int main() {
     
    Render::Window w = Render::Window(800, 600, "window");
    printf("%u\n", w.GetWindow());
    glViewport(0,0, 800, 600);



    Render::shader s1 = Render::CompileShader("shaders/Batch.vert", "shaders/Batch.frag");
    Render::shader s2 = Render::CompileShader("shaders/standard.vert", "shaders/standard.frag");

    Render::Image::texture t = Render::Image::downloadImage("images/sheet1.png");
    Render::Image::texture t1 = Render::Image::downloadImage("images/transparent.png");
    


    Render::BatchRenderer r(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s1, &w, t1.id, glm::ivec2(1,1));
    Render::transRenderer r2(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s2, &w);
    
    
    Render::Sprite* s = r.AddSprite(300.0f, 300.0f, glm::vec4(0.0f, 0.0f, 1.0f, 100.0f), glm::vec3(0.0f, 0.0f, -10.0f), 0);
    Render::Sprite* sp2 = r2.AddSprite(1000.0f, 1000.0f, glm::vec4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f), t.id);
   
    bool d = true;

    while (!glfwWindowShouldClose(w.GetWindow())) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        r.Draw();
        r2.Draw();
       
       if (glfwGetTime() > 5.0f) {
            s->SetOpacity(s->opacity - 0.01f);
       }



        glfwSwapBuffers(w.GetWindow());
        glfwPollEvents();
    }


    return 0;
   
}