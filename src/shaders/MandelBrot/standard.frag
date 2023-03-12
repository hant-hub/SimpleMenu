#version 410 core
out vec4 FragColor; 


in vec3 ourColor;
in vec2 Coord;

uniform sampler2D ourTexture;
uniform float opacity;

uniform float scale;
uniform vec2 origin;
uniform vec2 constant;
const int iterations = 5100;

precision highp float;


float dist(vec2 point) {
    return point.x*point.x + point.y*point.y;
}





double brot(vec2 point, vec2 C) {
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



    return (double(count) + 1) - log(log(sqrt(dist(z))))/log(2);
}

const vec3 colors[16] = vec3[16](
        vec3(66, 30, 15),
        vec3(25, 7, 26),
        vec3(9, 1, 47),
        vec3(4, 4, 73),
        vec3(0, 7, 100),
        vec3(12, 44, 138),
        vec3(24, 82, 177),
        vec3(57, 125, 209),
        vec3(134, 181, 229),
        vec3(211, 236, 248),
        vec3(241, 233, 191),
        vec3(248, 201, 95),
        vec3(255, 170, 0),
        vec3(204, 128, 0),
        vec3(153, 87, 0),
        vec3(106, 52, 3));

void main()
{
    ivec2 textureRes = textureSize(ourTexture, 0);
    vec2 center = vec2(textureRes);

    vec2 position;
    position.x = ((gl_FragCoord.x/center.x - 0.5f) * scale) + origin.x;
    position.y = ((gl_FragCoord.y/center.y - 0.5f) * scale) + origin.y;
    
    //position.x *= 1920.0f/1080.0f;

    vec2 adjustedconstant;
    adjustedconstant.x = ((constant.x/center.x - 0.5f) * scale) + origin.x;
    adjustedconstant.y = ((constant.y/center.y - 0.5f) * scale) + origin.y;

    double color = (brot(position, adjustedconstant)); 
    
    FragColor = vec4(colors[int(color)%16]/255, 1.0f);
   
}
//vec4(ourColor, 1.0f);//
