#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 ambientLightColor;
uniform float ambientLightStrength;

void main()
{
    vec4 texture1Color = texture(texture1, TexCoord);
    vec4 texture2Color = texture(texture2, TexCoord);

    vec4 mixedTextureColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
    vec4 objectColor = vec4(ambientLightStrength * ambientLightColor * ourColor, 1.0);

    FragColor = mixedTextureColor * objectColor;
}
