#include "window.h"



namespace Render {
    Window::Window(int width, int height, const char* title) {
        
        if (glfwInit() == GLFW_FALSE) {
            printf("the very first one\n");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


        m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (m_window == NULL) {
            printf("flopped here\n");
        }

        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            printf("failed here\n");
        }

        

    }

    Window::~Window() {

    }
}