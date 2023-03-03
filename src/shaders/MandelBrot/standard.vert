#version 410 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec2 aTex;

out vec3 ourColor; // output a color to the fragment shader
out vec2 Coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;



void main()
{
    gl_Position = proj * view * model * vec4(aPos, 1.0);
    ourColor = vec3(gl_Position.xy, 1.0f); // set ourColor to the input color we got from the vertex data
    Coord = aTex;
}       