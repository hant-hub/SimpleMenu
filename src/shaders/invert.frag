#version 410 core
out vec4 FragColor;  
in vec3 ourColor;
  
void main()
{
    FragColor = 1-vec4(ourColor, 1.0);
}