#pragma once
#include "Renderer.h"



namespace Render {


class BatchRenderer {
    public:
        BatchRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, Window* w);
        ~BatchRenderer();

        void Draw();
        Sprite AddSprite();


    private:
        glm::mat4 Cam;
        glm::mat4 proj;
        Window* w;

        std::vector<Quad> geometry;
        std::vector<Sprite> sprites;
        

};





};