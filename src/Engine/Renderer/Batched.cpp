#include "Batched.h"


namespace Render {

    BatchRenderer::BatchRenderer(bool ortho, glm::vec3 campos, glm::vec3 viewdir, Window* w) : w(w) {

        if (ortho) {
            proj = glm::ortho(0.0f, (float)w->GetWidth(), 0.0f, (float)w->GetHeight(), 0.1f, 100.0f);
        } else {
            proj = glm::perspective(glm::radians(45.0f), (float)w->GetWidth()/(float)w->GetHeight(), 0.1f, 100.0f);
        }

        Cam = glm::lookAt(campos, campos + viewdir, glm::vec3(0.0f, 1.0f, 0.0f));


    }





}