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

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

uniform Light light;


vec4 texture1Color = texture(texture1, TexCoord);
vec4 texture2Color = texture(texture2, TexCoord);

vec4 mixedTextureColor = mix(texture1Color, texture2Color, 0.2);


vec3 CalcMaterialColor() {
    return ourColor;
}


vec3 CalcAmbientColor() {
    return material.ambient * vec3(mixedTextureColor * vec4(ourColor, 1.0f));
}

vec3 CalcDiffuseColor() {
    return material.diffuse * vec3(mixedTextureColor * vec4(ourColor, 1.0f));
}

vec3 CalcSpecularColor() {
    return material.specular;
}

float CalcMaterialShininess() {
    return material.shininess;
}
