#include "Batched.h"


namespace Render {


    batchSprite::batchSprite(glm::vec3 pos, glm::vec4 rot, glm::ivec2 dim, Renderer* r, int index, GLuint texture) : Sprite::Sprite(pos, rot, dim, r, index, texture) {



        geo = {  
        // first triangle
              //pos                             //uv
        {model * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},       // top right
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},       // top left 
        // second triangle
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},       // bottom left
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)}        // top left
        };



    }

    void batchSprite::SetPos(glm::vec3 pos) {
        this->pos = pos;

        model = glm::mat4(1.0f);

        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(rot.w), {rot.x, rot.y, rot.z});
        model = glm::scale(model, glm::vec3(glm::vec2(size.x), 1.0f));

        geo = {  
        // first triangle
              //pos                             //uv
        {model * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},       // top right
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},       // top left 
        // second triangle
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},       // bottom left
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)}        // top left
        };

    }
    void batchSprite::SetRot(glm::vec4 rot) {
        this->rot = rot;

        model = glm::mat4(1.0f);

        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(rot.w), {rot.x, rot.y, rot.z});
        model = glm::scale(model, glm::vec3(glm::vec2(size.x), 1.0f));

        geo = {  
        // first triangle
              //pos                             //uv
        {model * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},       // top right
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},       // top left 
        // second triangle
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},       // bottom left
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)}        // top left
        };

    }
    void batchSprite::SetSize(glm::ivec2 size) {
        this->size = size;

        model = glm::mat4(1.0f);

        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(rot.w), {rot.x, rot.y, rot.z});
        model = glm::scale(model, glm::vec3(glm::vec2(size.x), 1.0f));

        geo = {  
        // first triangle
              //pos                             //uv
        {model * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},       // top right
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)},       // top left 
        // second triangle
        {model *  glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),   glm::vec2(1.0f, 0.0f)},       // bottom right
        {model *  glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 0.0f)},       // bottom left
        {model *  glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)}        // top left
        };

    }



    BatchRenderer::BatchRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, shader s, Window* w) : w(w), s(s) {

        if (ortho) {
            proj = glm::ortho((float)w->GetWidth()/2, -(float)w->GetWidth()/2, -(float)w->GetHeight()/2, (float)w->GetHeight()/2, -100.0f, 100.0f);
        } else {
            proj = glm::perspective(glm::radians(45.0f), (float)w->GetWidth()/(float)w->GetHeight(), 0.1f, 100.0f);
        }

        Cam = glm::lookAt(campos, campos + viewdir, glm::vec3(0.0f, 1.0f, 0.0f));

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
        glEnableVertexArrayAttrib(VAO, 0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
        glEnableVertexArrayAttrib(VAO, 1);



    }

    BatchRenderer::~BatchRenderer() {

    }

    Sprite* BatchRenderer::AddSprite(float width, float height, glm::vec4 rot, glm::vec3 pos, GLuint texture) {


        batchSprite *sprite = new batchSprite(pos, rot, glm::ivec2(width, height), this, sprites.size(), texture);
        
        sprites.push_back(sprite);

        return sprite;

    }

    void BatchRenderer::Delete(int index) {
        sprites.erase(sprites.begin() + index);
        
        for (int i; i < sprites.size(); i++) {
            sprites[i]->index = i;
        }
    }

    void BatchRenderer::Draw() {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        s.Use();
        SetMat4(s, proj, "proj");
        SetMat4(s, Cam, "view");

        geometry.clear();
        for (batchSprite* s: sprites) {
            geometry.push_back(s->geo);
            printf("%f, %f, %f, %f \n", s->geo.a.pos[0], s->geo.a.pos[1], s->geo.a.pos[2], s->geo.b.pos[0]);
        }

        

        glBufferData(GL_ARRAY_BUFFER, geometry.size() * sizeof(Quad), geometry.data(), GL_DYNAMIC_DRAW);
        
        glDrawArrays(GL_TRIANGLES, 0, geometry.size() * 6);
        std::cout << sizeof(Quad)/sizeof(float) << std::endl;
        glBindVertexArray(0);
        
    }





}