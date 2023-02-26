#version 410 core
out vec4 FragColor; 


in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform float opacity;
  
void main()
{
    vec4 color = texture(ourTexture, TexCoord);
    // if (color.a < 0.1){
    //     discard;
    // }
    FragColor = vec4(color.rgb, color.a * opacity);
}

//vec4(ourColor, 1.0f);