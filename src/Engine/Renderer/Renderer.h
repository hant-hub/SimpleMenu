#pragma once
#include "images/image.h"
#include "../shader.h"
#include "../window.h"


namespace Render {


    class Renderer 
    {
        public:
            virtual void Delete(int index) = 0;

        private:
            shader s;
            
    };
    class Window;


    struct Sprite {

        Sprite(glm::vec3 pos, glm::vec4 rot, glm::ivec2 dim, Renderer* r, int index, GLuint texture = 0);


        //positional information
        glm::mat4 model;
        glm::vec3 pos;
        glm::vec4 rot;
        glm::ivec2 size;

        //opacity
        float opacity;


        //memory management
        Renderer* r;
        int index;

        //texture stuff
        GLuint texture;

        void Delete();
        
        virtual void SetPos(glm::vec3 pos) = 0;
        virtual void SetRot(glm::vec4 rot) = 0;
        virtual void SetSize(glm::ivec2 size) = 0;
        virtual void SetOpacity(float opacity) = 0;
        

    };

    struct Vertex {
        glm::vec4 pos;
        glm::vec2 uv;
        int index;
    };


    struct Quad {
        //not using index stuff
        Vertex a;
        Vertex b;
        Vertex c;
        Vertex d;
        Vertex e;
        Vertex f;
        //GLuint tex;
    };









};