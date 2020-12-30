#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 viewPos;
uniform vec3 lightPos;
uniform vec3 lightColor;

uniform float lightStrength;

void main()
{
    float ambientLightStrength = lightStrength * 0.1f;
    vec3 ambient = ambientLightStrength * lightColor;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightStrength * lightColor;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    float specularStrength = 0.5f;
    vec3 specular = specularStrength * spec * lightColor;

    vec4 texture1Color = texture(texture1, TexCoord);
    vec4 texture2Color = texture(texture2, TexCoord);

    vec4 mixedTextureColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);

    FragColor = vec4((diffuse + ambient + specular) * ourColor, 1.0) * mixedTextureColor;
}
