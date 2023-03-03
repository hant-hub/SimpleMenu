#pragma once
#include "../transparency.h"



namespace Render {


    struct FrameStep {
        
        FrameStep(Window* w, shader s);
        ~FrameStep();

        void Begin();
        void Draw(GLuint target);
        

        Window* w;

        GLuint fbo;
        GLuint intermediate;
        GLuint rbo;
        GLuint intermediaterbo;
        GLuint texture;
        GLuint transfertexture;
        transRenderer* r;

    };





}