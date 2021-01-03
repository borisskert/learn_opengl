#version 330 core

out vec4 FragColor;

vec3 CalcColor();

void main()
{
    FragColor = vec4(CalcColor(), 1.0f);
}
