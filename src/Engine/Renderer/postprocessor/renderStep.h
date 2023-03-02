#pragma once
#include "../transparency.h"



namespace Render {


    struct FrameStep {
        
        FrameStep(Window* w, shader s);
        ~FrameStep();

        void Begin();
        void Draw(GLuint target);
        
        GLuint fbo;
        GLuint rbo;
        GLuint texture;
        transRenderer* r;

    };





}