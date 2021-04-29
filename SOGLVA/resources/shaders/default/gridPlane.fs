#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

void main()
{
    vec2 uv = TexCoords;
    float size = 1.0/1600.0;   // size of the tile
    float edge = size/64.0; // size of the edge
    uv = (mod(uv, size) - mod(uv - edge, size) - edge) * 1.0/size;
    
    vec4 color = vec4(0.8 - length(uv) * 0.5);

    color = vec4(1) - color;
    // 0.9 controls the brighness of the face of the tile
    // 0.5 controls the darkness of the edge

    if(color.a < 0.1)
        discard;

    FragColor = color;
}