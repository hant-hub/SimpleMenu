#pragma once


namespace Render {
namespace InputReader {


    





    // struct InputState {
    //     bool keys[120];
    //     bool mousebuttons[8];
    //     double mousePos[2];
    // };

    


    


    bool GetKeyState(GLFWwindow* w, int c);
    bool GetMouseState(GLFWwindow* w, int b);
    glm::vec2 GetMousePos(GLFWwindow* w);



    // const static std::map<int, uint> KeyMapper = {
    //     {GLFW_KEY_UNKNOWN, 0}, //unknown key
    //     {GLFW_KEY_SPACE, 1}, //space key
    //     {GLFW_KEY_APOSTROPHE, 2}, //apostrophe
    //     {GLFW_KEY_COMMA, 3}, //comma
    //     {GLFW_KEY_MINUS, 4}, //minus
    //     {GLFW_KEY_PERIOD, 5}, //period
    //     {GLFW_KEY_SLASH, 6}, //slash
    //     {GLFW_KEY_0,   7},
    //     {GLFW_KEY_1,   8},
    //     {GLFW_KEY_2,   9},
    //     {GLFW_KEY_3,   10},
    //     {GLFW_KEY_4,   11},
    //     {GLFW_KEY_5,   12},
    //     {GLFW_KEY_6,   13},
    //     {GLFW_KEY_7,   14},
    //     {GLFW_KEY_8,   15},
    //     {GLFW_KEY_9,   16},
    //     {GLFW_KEY_SEMICOLON,   17 /* ; */},
    //     {GLFW_KEY_EQUAL,   18 /* = */},
    //     {GLFW_KEY_A,   19},
    //     {GLFW_KEY_B,   20},
    //     {GLFW_KEY_C,   21},
    //     {GLFW_KEY_D,   22},
    //     {GLFW_KEY_E,   23},
    //     {GLFW_KEY_F,   24},
    //     {GLFW_KEY_G,   25},
    //     {GLFW_KEY_H,   26},
    //     {GLFW_KEY_I,   27},
    //     {GLFW_KEY_J,   28},
    //     {GLFW_KEY_K,   29},
    //     {GLFW_KEY_L,   30},
    //     {GLFW_KEY_M,   31},
    //     {GLFW_KEY_N,   32},
    //     {GLFW_KEY_O,   33},
    //     {GLFW_KEY_P,   34},
    //     {GLFW_KEY_Q,   35},
    //     {GLFW_KEY_R,   36},
    //     {GLFW_KEY_S,   37},
    //     {GLFW_KEY_T,   38},
    //     {GLFW_KEY_U,   39},
    //     {GLFW_KEY_V,   40},
    //     {GLFW_KEY_W,   41},
    //     {GLFW_KEY_X,   42},
    //     {GLFW_KEY_Y,   43},
    //     {GLFW_KEY_Z,   44},
    //     {GLFW_KEY_LEFT_BRACKET,   45 /* [ */},
    //     {GLFW_KEY_BACKSLASH,   46 /* \ */},
    //     {GLFW_KEY_RIGHT_BRACKET,   47 /* ] */},
    //     {GLFW_KEY_GRAVE_ACCENT,   48 /* ` */},
    //     {GLFW_KEY_WORLD_1,   49 /* non-US #1 */},
    //     {GLFW_KEY_WORLD_2,   50 /* non-US #2 */},
    //     {GLFW_KEY_ESCAPE,   51},
    //     {GLFW_KEY_ENTER,   52},
    //     {GLFW_KEY_TAB,   53},
    //     {GLFW_KEY_BACKSPACE,   54},
    //     {GLFW_KEY_INSERT,   55},
    //     {GLFW_KEY_DELETE,   56},
    //     {GLFW_KEY_RIGHT,   57},
    //     {GLFW_KEY_LEFT,   58},
    //     {GLFW_KEY_DOWN,   59},
    //     {GLFW_KEY_UP,   60},
    //     {GLFW_KEY_PAGE_UP,   61},
    //     {GLFW_KEY_PAGE_DOWN,   62},
    //     {GLFW_KEY_HOME,   63},
    //     {GLFW_KEY_END,   64},
    //     {GLFW_KEY_CAPS_LOCK,   65},
    //     {GLFW_KEY_SCROLL_LOCK,   66},
    //     {GLFW_KEY_NUM_LOCK,   67},
    //     {GLFW_KEY_PRINT_SCREEN,   68},
    //     {GLFW_KEY_PAUSE,   69},
    //     {GLFW_KEY_F1,   70},
    //     {GLFW_KEY_F2,   71},
    //     {GLFW_KEY_F3,   72},
    //     {GLFW_KEY_F4,   73},
    //     {GLFW_KEY_F5,   74},
    //     {GLFW_KEY_F6,   75},
    //     {GLFW_KEY_F7,   76},
    //     {GLFW_KEY_F8,   77},
    //     {GLFW_KEY_F9,   78},
    //     {GLFW_KEY_F10,   79},
    //     {GLFW_KEY_F11,   80},
    //     {GLFW_KEY_F12,   81},
    //     {GLFW_KEY_F13,   82},
    //     {GLFW_KEY_F14,   83},
    //     {GLFW_KEY_F15,   84},
    //     {GLFW_KEY_F16,   85},
    //     {GLFW_KEY_F17,   86},
    //     {GLFW_KEY_F18,   87},
    //     {GLFW_KEY_F19,   88},
    //     {GLFW_KEY_F20,   89},
    //     {GLFW_KEY_F21,   90},
    //     {GLFW_KEY_F22,   91},
    //     {GLFW_KEY_F23,   92},
    //     {GLFW_KEY_F24,   93},
    //     {GLFW_KEY_F25,   94},
    //     {GLFW_KEY_KP_0,   95},
    //     {GLFW_KEY_KP_1,   96},
    //     {GLFW_KEY_KP_2,   97},
    //     {GLFW_KEY_KP_3,   98},
    //     {GLFW_KEY_KP_4,   99},
    //     {GLFW_KEY_KP_5,   100},
    //     {GLFW_KEY_KP_6,   101},
    //     {GLFW_KEY_KP_7,   102},
    //     {GLFW_KEY_KP_8,   103},
    //     {GLFW_KEY_KP_9,   104},
    //     {GLFW_KEY_KP_DECIMAL,   105},
    //     {GLFW_KEY_KP_DIVIDE,   106},
    //     {GLFW_KEY_KP_MULTIPLY,   107},
    //     {GLFW_KEY_KP_SUBTRACT,   108},
    //     {GLFW_KEY_KP_ADD,   109},
    //     {GLFW_KEY_KP_ENTER,   110},
    //     {GLFW_KEY_KP_EQUAL,   111},
    //     {GLFW_KEY_LEFT_SHIFT,   112},
    //     {GLFW_KEY_LEFT_CONTROL,   113},
    //     {GLFW_KEY_LEFT_ALT,     114},
    //     {GLFW_KEY_LEFT_SUPER,   115},
    //     {GLFW_KEY_RIGHT_SHIFT,   116},
    //     {GLFW_KEY_RIGHT_CONTROL,   117},
    //     {GLFW_KEY_RIGHT_ALT,   118},
    //     {GLFW_KEY_RIGHT_SUPER,   119},
    //     {GLFW_KEY_MENU,   120}
 
    // };


}



}