#include "transparency.h"



namespace Render {

    
    void transSprite::SetPos(glm::vec3 pos) {
        this->pos = pos;
        model = glm::mat4(1.0f);

        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(rot.w), {rot.x, rot.y, rot.z});
        model = glm::scale(model, glm::vec3(glm::vec2(size.x), 1.0f));
    }
    void transSprite::SetRot(glm::vec4 rot) {
        this->rot = rot;
        model = glm::mat4(1.0f);

        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(rot.w), {rot.x, rot.y, rot.z});
        model = glm::scale(model, glm::vec3(glm::vec2(size.x), 1.0f));
    }
    void transSprite::SetSize(glm::ivec2 size) {
        this->size = size;
        model = glm::mat4(1.0f);

        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(rot.w), {rot.x, rot.y, rot.z});
        model = glm::scale(model, glm::vec3(glm::vec2(size.x), 1.0f));
    }
    void transSprite::SetOpacity(float opacity) {
        this->opacity = opacity;
    }



    transRenderer::transRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, shader s, Window* w) : s(s), w(w) {

        if (ortho) {
            proj = glm::ortho((float)w->GetWidth()/2, -(float)w->GetWidth()/2, -(float)w->GetHeight()/2, (float)w->GetHeight()/2, -100.0f, 100.0f);
            
        } else {
            proj = glm::perspective(glm::radians(45.0f), (float)w->GetWidth()/(float)w->GetHeight(), 0.1f, 100.0f);

        }

        Cam = glm::lookAt(campos, campos + viewdir, glm::vec3(0.0f, 1.0f, 0.0f));


        const float verticies[] = {
        // first triangle
              //pos             //uv
        0.5f,  0.5f, 0.0f,   1.0f, 1.0f,       // top right
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f,       // bottom right
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,       // top left 
        // second triangle
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f,       // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,       // bottom left
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f        // top left
        }; 


        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
        glEnableVertexArrayAttrib(VAO, 0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
        glEnableVertexArrayAttrib(VAO, 1);


    }

    transRenderer::~transRenderer() {

    }

    Sprite* transRenderer::AddSprite(float width, float height, glm::vec4 rot, glm::vec3 pos, GLuint texture) {
        
        Sprite *sprite = new transSprite(pos, rot, glm::ivec2(width, height), this, sprites.size(), texture);
        
        sprites.push_back(sprite);

        return sprite;
    }

    void transRenderer::Delete(int index) {
        printf("bam\n");
        sprites.erase(sprites.begin() + index);
        
        for (int i; i < sprites.size(); i++) {
            sprites[i]->index = i;
        }
    }

    void transRenderer::Draw() {
        s.Use();
        SetMat4(s, proj, "proj");
        SetMat4(s, Cam, "view");
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        std::vector<Sprite*> sorted(sprites);

        auto depthcomp = [](Sprite* a, Sprite* b) {return a->pos.z > b->pos.z;};


        std::sort(sorted.begin(), sorted.end(), depthcomp);


        for (Sprite* sprite : sorted) {
            
            glBindTexture(GL_TEXTURE_2D, sprite->texture);
            std::cout << sprite->opacity << std::endl;
            SetMat4(s, sprite->model, "model");
            SetFloat(s, sprite->opacity, "opacity");
            glDrawArrays(GL_TRIANGLES, 0, 6);
            
        }
        glBindVertexArray(0);

    }
}