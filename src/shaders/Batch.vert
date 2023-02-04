#version 410 core
layout (location = 0) in vec4 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec2 aTex;

out vec3 ourColor; // output a color to the fragment shader
out vec2 TexCoord;

uniform mat4 view;
uniform mat4 proj;



void main()
{
    gl_Position =  proj * view * aPos;
    ourColor = vec3(1.0f); // set ourColor to the input color we got from the vertex data
    TexCoord = aTex;
}       
//proj * view *