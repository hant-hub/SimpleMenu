#version 410 core
out vec4 FragColor; 


in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform float opacity;
  
void main()
{
    ivec2 textureRes = textureSize(ourTexture, 0);

    vec2 offset = vec2(textureRes);
    vec2 offsetx = vec2(1.0f, 0.0f)/offset;
    vec2 offsety = vec2(0.0f, 1.0f)/offset;

    vec4 color0 = texture(ourTexture, TexCoord - offsetx + offsety);
    vec4 color1 = texture(ourTexture, TexCoord + offsety);
    vec4 color2 = texture(ourTexture, TexCoord + offsetx + offsety);
    vec4 color3 = texture(ourTexture, TexCoord - offsetx);
    vec4 color4 = texture(ourTexture, TexCoord);
    vec4 color5 = texture(ourTexture, TexCoord + offsetx);
    vec4 color6 = texture(ourTexture, TexCoord - offsetx - offsety);
    vec4 color7 = texture(ourTexture, TexCoord - offsety);
    vec4 color8 = texture(ourTexture, TexCoord + offsetx - offsety);

    float kernal[9] = float[](
        -1, -1, -1,
        -1,  9, -1,
        -1, -1, -1
    );



    vec4 color = vec4(color0.rgb*kernal[0], 1.0f);
    color += (vec4(color1.rgb*kernal[1], 1.0f));
    color += (vec4(color2.rgb*kernal[2], 1.0f));
    color += (vec4(color3.rgb*kernal[3], 1.0f));
    color += (vec4(color4.rgb*kernal[4], 1.0f));
    color += (vec4(color5.rgb*kernal[5], 1.0f));
    color += (vec4(color6.rgb*kernal[6], 1.0f));
    color += (vec4(color7.rgb*kernal[7], 1.0f));
    color += (vec4(color8.rgb*kernal[8], 1.0f));
    
    FragColor = color;
}

//vec4(ourColor, 1.0f);
