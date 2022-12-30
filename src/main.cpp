#include <stdio.h>
#include "window.h"
#include "shader.h"
#include "Renderer/unoptimized.h"


int main() {
     
    Render::Window w = Render::Window(800, 600, "window");
    printf("%u\n", w.GetWindow());
    glViewport(0,0, 800, 600);



    Render::shader s1 = Render::CompileShader("shaders/standard.vert", "shaders/standard.frag");
    //Render::shader s2 = Render::CompileShader("shaders/invert.vert", "shaders/invert.frag");

    Render::unopRenderer r(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s1, &w);
    Render::Sprite* s = r.AddSprite(100.0f, 100.0f, glm::vec4(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::vec4 rot(glm::vec4(1.0f));

    bool d = true;

    while (!glfwWindowShouldClose(w.GetWindow())) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        r.Draw();

       
        if ((glfwGetTime() > 5.0f) && d) {
            printf("bam\n");
            s->Delete();
            delete s;
            d = false;
        }


        glfwSwapBuffers(w.GetWindow());
        glfwPollEvents();
    }


    return 0;
   
}