#pragma once
#include "shader.h"



namespace Render {


    class Window {
        public:
            Window(int width, int height, const char* title);
            ~Window();

            GLFWwindow* GetWindow() {return m_window;}

        private:
            GLFWwindow* m_window;
    };


};






inline int run() {
    
    Render::Window w = Render::Window(800, 600, "window");
    printf("%u\n", w.GetWindow());
    glViewport(0,0, 800, 600);



    const float verticies[] = {    
     // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };

    
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
    glEnableVertexArrayAttrib(VAO, 0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));
    glEnableVertexArrayAttrib(VAO, 1);

    Render::shader s1 = Render::CompileShader("shaders/standard.vert", "shaders/standard.frag");
    Render::shader s2 = Render::CompileShader("shaders/invert.vert", "shaders/invert.frag");

    glUseProgram(s2);
    float start = glfwGetTime();
    float accumulator = 0;
    bool current = false;
    while (!glfwWindowShouldClose(w.GetWindow())) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        accumulator += glfwGetTime() - start;
        start = glfwGetTime();
        if (accumulator > 2.0f) {
            accumulator = 0;

            if (current) {
                glUseProgram(s1);
            } else {
                glUseProgram(s2);
            }

            current = !current;
        }

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(w.GetWindow());
        glfwPollEvents();
    }


    return 0;
}

