#version 410 core
layout (location = 0) in vec4 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec2 aTex;
layout (location = 2) in float spriteindex;

out vec3 ourColor; // output a color to the fragment shader
out vec2 TexCoord;

uniform mat4 view; //projection matricies
uniform mat4 proj;


uniform ivec2 size; //size of texture in images


uniform sampler2D ourTexture;


void main()
{
    ivec2 textureRes = textureSize(ourTexture, 0);

    vec2 ioffset = vec2(float(spriteindex)/float(size.x), 1.0f/float(size.y));  //this is to find the center of the correct image
    vec2 outTex = vec2(aTex.x/size.x, aTex.y/size.y); //this rescales the uv coordinates

    gl_Position =  proj * view * aPos;
    ourColor = vec3(1.0f); // set ourColor to the input color we got from the vertex data
    TexCoord = ioffset + outTex;
}       
//proj * view *

//float(spriteindex) float(spriteindex)