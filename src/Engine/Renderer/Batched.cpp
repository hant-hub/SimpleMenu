#include "Batched.h"


namespace Render {


    batchSprite::batchSprite(glm::vec3 pos, glm::vec4 rot, glm::ivec2 dim, Renderer* r, int index, GLuint texture = 0) : Sprite::Sprite(pos, rot, dim, r, index, texture) {

        geo = {  
        // first triangle
              //pos                             //uv
        {model * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},       // top right
        {model * glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},       // top left 
        // second triangle
        {model * glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},       // bottom left
        {model * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)}        // top left
        };



    }

    void batchSprite::SetPos(glm::vec3 pos) {}
    void batchSprite::SetRot(glm::vec4 rot) {}
    void batchSprite::SetSize(glm::ivec2 size) {}



    BatchRenderer::BatchRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, Window* w) : w(w) {

        if (ortho) {
            proj = glm::ortho(0.0f, (float)w->GetWidth(), 0.0f, (float)w->GetHeight(), 0.1f, 100.0f);
        } else {
            proj = glm::perspective(glm::radians(45.0f), (float)w->GetWidth()/(float)w->GetHeight(), 0.1f, 100.0f);
        }

        Cam = glm::lookAt(campos, campos + viewdir, glm::vec3(0.0f, 1.0f, 0.0f));

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
        glEnableVertexArrayAttrib(VAO, 0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
        glEnableVertexArrayAttrib(VAO, 1);



    }

    Sprite* BatchRenderer::AddSprite(float width, float height, glm::vec4 rot, glm::vec3 pos, GLuint texture) {


        Sprite *sprite = new batchSprite(pos, rot, glm::ivec2(width, height), this, sprites.size(), texture);
        
        sprites.push_back(sprite);

        return sprite;

    }





}