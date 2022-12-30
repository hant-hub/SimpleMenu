#pragma once




namespace Render {


    class Window {
        public:
            Window(int width, int height, const char* title);
            ~Window();

            GLFWwindow* GetWindow() {return m_window;}
            
            const int GetWidth() const {return width;}
            const int GetHeight() const {return height;}

            void SetWidth(int w) {width = w;}
            void SetHeight(int h) {height = h;}
            
        private:
            GLFWwindow* m_window;
            int width;
            int height;
            
    };


};






