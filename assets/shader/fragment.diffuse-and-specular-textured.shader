#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 viewPos;
uniform vec3 lightPos;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

uniform Material material;

vec3 materialDiffuse = vec3(texture(material.diffuse, TexCoord));
vec3 materialSpecular = vec3(texture(material.specular, TexCoord));


vec3 CalcMaterialColor() {
    return materialDiffuse;;
}


vec3 CalcAmbientColor() {
    return materialDiffuse;
}

vec3 CalcDiffuseColor() {
    return materialDiffuse;
}

vec3 CalcSpecularColor() {
    return materialSpecular;
}

float CalcMaterialShininess() {
    return material.shininess;
}
