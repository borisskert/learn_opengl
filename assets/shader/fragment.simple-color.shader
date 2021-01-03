#version 330 core

in vec3 ourColor;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;


vec3 CalcMaterialColor() {
    return ourColor;
}


vec3 CalcAmbientColor() {
    return ourColor * material.ambient;
}

vec3 CalcDiffuseColor() {
    return ourColor * material.diffuse;
}

vec3 CalcSpecularColor() {
    return ourColor * material.specular;
}

float CalcMaterialShininess() {
    return material.shininess;
}
