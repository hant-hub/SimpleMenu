#pragma once
#include "Renderer.h"




namespace Render{

class unopRenderer;


struct unopSprite {
    glm::mat4 model;
    unopRenderer* r;
};

class unopRenderer: public Renderer {
    public:
        unopRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, shader s, Window* w);
        ~unopRenderer();

        void Draw();

        void Delete(int index);

        Sprite* AddSprite(float width, float height, glm::vec4 rot, glm::vec3 pos);


    private:
        glm::mat4 Cam;
        glm::mat4 proj;
        Window* w;
        shader s;
        GLuint VAO;
        GLuint VBO;

        std::vector<Sprite*> sprites;




};





}