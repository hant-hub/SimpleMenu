#include "Renderer.h"


namespace Render {

    Sprite::Sprite(glm::vec3 pos, glm::vec4 rot, glm::ivec2 dim, Renderer* r, int index, GLuint texture) : r(r), pos(pos), rot(rot), size(dim), index(index), texture(texture) {
        model = glm::mat4(1.0f);

        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(rot.w), {rot.x, rot.y, rot.z});
        model = glm::scale(model, glm::vec3(glm::vec2(size.x), 1.0f));
        
    }

    void Sprite::Delete() {
        printf("bam\n");
        r->Delete(index);
    }


}