#pragma once
#include "Renderer.h"




namespace Render{

class unopRenderer;


struct unopSprite: public Sprite {

using Sprite::Sprite;

void SetPos(glm::vec3 pos) override;
void SetRot(glm::vec4 rot) override;
void SetSize(glm::ivec2 size) override;
};



class unopRenderer: public Renderer {
    public:
        unopRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, shader s, Window* w);
        ~unopRenderer();

        void Draw();

        void Delete(int index);

        Sprite* AddSprite(float width, float height, glm::vec4 rot, glm::vec3 pos, GLuint texture);


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