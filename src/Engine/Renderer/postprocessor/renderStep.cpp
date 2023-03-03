#include "renderStep.h"



namespace Render {

    FrameStep::FrameStep(Window* w, shader s) : w(w){

        r = new transRenderer(true, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), s, w);


        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);


        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture);
        glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 32, GL_RGBA, w->GetWidth(), w->GetHeight(), GL_TRUE);
        glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, texture, 0);


        glGenRenderbuffers(1, &rbo);
        glBindRenderbuffer(GL_RENDERBUFFER, rbo);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, w->GetWidth(), w->GetHeight());
        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);



        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE) {
            printf("framebuffer complete\n");
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);


        glGenFramebuffers(1, &intermediate);
        glBindFramebuffer(GL_FRAMEBUFFER, intermediate);


        glGenTextures(1, &transfertexture);
        glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, transfertexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w->GetWidth(), w->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, transfertexture, 0);


        glGenRenderbuffers(1, &intermediaterbo);
        glBindRenderbuffer(GL_RENDERBUFFER, intermediaterbo);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, w->GetWidth(), w->GetHeight());
        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, intermediaterbo);



        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE) {
            printf("framebuffer complete\n");
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);


        Render::Sprite* sp3 = r->AddSprite(w->GetWidth(), w->GetHeight(), glm::vec4(1.0f, 1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), texture);

    }

    FrameStep::~FrameStep() {}

    void FrameStep::Begin() {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }

    void FrameStep::Draw(GLuint target) {
        glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, intermediate);
        glBlitFramebuffer(0, 0, w->GetWidth(), w->GetHeight(), 0, 0, w->GetWidth(), w->GetHeight(), GL_COLOR_BUFFER_BIT, GL_NEAREST);
        glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

        glBindFramebuffer(GL_FRAMEBUFFER, target);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        r->Draw();
    }


}