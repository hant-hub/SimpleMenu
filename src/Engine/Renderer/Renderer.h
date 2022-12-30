#pragma once
#include "../shader.h"
#include "../window.h"


namespace Render {


    class Renderer 
    {
        public:
            virtual void Delete(int index) = 0;

    };
    class Window;


    struct Sprite {

        Sprite(glm::vec3 pos, glm::vec4 rot, glm::ivec2 dim, Renderer* r, int index);


        //positional information
        glm::mat4 model;
        glm::vec3 pos;
        glm::vec4 rot;
        glm::ivec2 dim;

        Renderer* r;
        int index;

        void Delete();
        
        void SetPos(glm::vec3 pos);
        void SetRot(glm::vec4 rot);
        void SetSize(glm::ivec2 size);
        

    };

    struct Vertex {
        glm::vec3 pos;
        //glm::vec2 uv;
    };


    struct Quad {
        Vertex a;
        Vertex b;
        Vertex c;
        Vertex d;
        //GLuint tex;
    };









};