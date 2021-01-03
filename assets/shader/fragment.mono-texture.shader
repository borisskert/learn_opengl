#version 330

in vec2 TexCoord;


struct Material {
    sampler2D diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;


vec3 CalcMaterialColor() {
    return vec3(texture(material.diffuse, TexCoord));
}


vec3 CalcAmbientColor() {
    return vec3(texture(material.diffuse, TexCoord));
}

vec3 CalcDiffuseColor() {
    return vec3(texture(material.diffuse, TexCoord));
}

vec3 CalcSpecularColor() {
    return material.specular;
}

float CalcMaterialShininess() {
    return material.shininess;
}
