#pragma once
#include "Renderer.h"



namespace Render {


struct batchSprite : public Sprite {
    batchSprite(glm::vec3 pos, glm::vec4 rot, glm::ivec2 dim, Renderer* r, int index, GLuint texture);

    Quad geo;
     

    
    void SetPos(glm::vec3 pos) override;
    void SetRot(glm::vec4 rot) override;
    void SetSize(glm::ivec2 size) override;
};

class BatchRenderer: public Renderer {
    public:
        BatchRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, shader s, Window* w);
        ~BatchRenderer();

        void Draw();
        Sprite* AddSprite(float width, float height, glm::vec4 rot, glm::vec3 pos, GLuint texture);
        //void Delete(int index) override;

        void Delete(int index) override;

    private:

        GLuint VAO;
        GLuint VBO;


        glm::mat4 Cam;
        glm::mat4 proj;
        Window* w;
        shader s;

        //flags for rebuilding/replacing geometry


        std::vector<Quad> geometry;
        std::vector<batchSprite*> sprites;
        

};





};