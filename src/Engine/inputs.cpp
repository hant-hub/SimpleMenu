#include "inputs.h"
#include "window.h"

namespace Render {
namespace InputReader {

bool GetKeyState(GLFWwindow* w, int c) {
    return glfwGetKey(w, c);
}

bool GetMouseState(GLFWwindow* w, int b) {
    return glfwGetMouseButton(w, b);
}

glm::vec2 GetMousePos(GLFWwindow* w) {
    double x;
    double y;
    glfwGetCursorPos(w, &x, &y);
    return glm::vec2(x, y);
}



}
}