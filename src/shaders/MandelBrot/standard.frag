#version 410 core
out vec4 FragColor; 


in vec3 ourColor;
in vec2 Coord;

uniform sampler2D ourTexture;
uniform float opacity;

uniform float scale;
uniform vec2 origin;
const int iterations = 500;

precision highp float;


float dist(vec2 point) {
    return point.x*point.x + point.y*point.y;
}





float brot(vec2 point, vec2 C) {
    int count = 0;
    float real;
    float complex;
    vec2 z = point;


    while (count <= iterations) {
        real = (z.x * z.x) - (z.y * z.y);
        complex = z.x * z.y * 2.0f;

        z = vec2(real, complex) + C;

        if (dist(z) >= 4.0f) break;


        count++;
    }



    return (float(count) + 1) - log(log(sqrt(dist(z))))/log(2);
}



void main()
{
    ivec2 textureRes = textureSize(ourTexture, 0);
    vec2 center = vec2(textureRes);

    vec2 position = ((gl_FragCoord.xy/center - vec2(0.5f)) * scale) - origin;
    position.x *= 1920.0f/1080.0f;


    float color = (brot(position, position))/iterations; 
    
    FragColor = vec4(vec3(color), 1.0f);
   
}
//vec4(ourColor, 1.0f);//
