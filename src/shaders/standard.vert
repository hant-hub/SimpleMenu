#version 410 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0

out vec3 ourColor; // output a color to the fragment shader


uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * model * vec4(aPos, 1.0);
    ourColor = (proj * view * model * vec4(aPos, 1.0)).xyz; // set ourColor to the input color we got from the vertex data
}       