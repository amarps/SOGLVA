#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform vec4 in_Tint;

void main()
{    
    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}