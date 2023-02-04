#include <stdio.h>
#include "window.h"
#include "shader.h"
#include "Renderer/unoptimized.h"
#include "Renderer/Batched.h"
#include "Renderer/images/image.h"


int main() {
     
    Render::Window w = Render::Window(800, 600, "window");
    printf("%u\n", w.GetWindow());
    glViewport(0,0, 800, 600);



    Render::shader s1 = Render::CompileShader("shaders/Batch.vert", "shaders/Batch.frag");
    //Render::shader s2 = Render::CompileShader("shaders/invert.vert", "shaders/invert.frag");

    Render::BatchRenderer r(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s1, &w);

    Render::Image::texture t = Render::Image::downloadImage("images/test.png");

    Render::Sprite* s = r.AddSprite(100.0f, 100.0f, glm::vec4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f), t.id);


    bool d = true;

    while (!glfwWindowShouldClose(w.GetWindow())) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        r.Draw();

        if (d) {
            s->SetPos(s->pos + glm::vec3(1.0f, 0.0f, 0.0f));
            s->SetRot(s->rot + glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
            std::cout << glm::to_string(s->pos) << std::endl;
        }

        if ((glfwGetTime() > 5.0f) && (d)) {
            d = false;
            s->Delete();
        }



        glfwSwapBuffers(w.GetWindow());
        glfwPollEvents();
    }


    return 0;
   
}