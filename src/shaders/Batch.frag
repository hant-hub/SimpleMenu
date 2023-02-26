#version 410 core
out vec4 FragColor; 


in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
  
void main()
{
    vec4 color = texture2D(ourTexture, TexCoord);
    if (color.a < 0.1f) discard;
    FragColor = color;
}
