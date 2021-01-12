#version 330 core

in vec3 Normal;
in vec3 FragPos;

uniform vec3 viewPos;
uniform vec3 lightPos;

struct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform DirLight dirLight;


vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);


struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
#define MAX_NR_POINT_LIGHTS 128

uniform int countLights = 1;
uniform PointLight pointLights[MAX_NR_POINT_LIGHTS];

struct FlashLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};
uniform FlashLight flashlight;

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

vec3 CalcAmbientColor();
vec3 CalcDiffuseColor();
vec3 CalcSpecularColor();
float CalcMaterialShininess();
vec3 CalcSpotLight(FlashLight light, vec3 norm, vec3 FragPos, vec3 viewDir);


vec3 CalcLight() {
    vec3 lightResult = vec3(0.0f);

    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    lightResult += CalcDirLight(dirLight, norm, viewDir);

    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    for (int i = 0; i < countLights; i++) {
        lightResult += CalcPointLight(pointLights[i], norm, FragPos, viewDir);
    }

    lightResult += CalcSpotLight(flashlight, norm, FragPos, viewDir);

    return lightResult;
}


vec3 CalcColor() {
    return CalcLight();
}


vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);

    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), CalcMaterialShininess());

    // combine results
    vec3 ambient  = light.ambient  * CalcAmbientColor();
    vec3 diffuse  = light.diffuse  * diff * CalcDiffuseColor();
    vec3 specular = light.specular * spec * CalcSpecularColor();

    return (ambient + diffuse + specular);
}


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), CalcMaterialShininess());

    // attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance +
    light.quadratic * (distance * distance));

    // combine results
    vec3 ambient  = light.ambient  * CalcAmbientColor();
    vec3 diffuse  = light.diffuse  * diff * CalcDiffuseColor();
    vec3 specular = light.specular * spec * CalcSpecularColor();

    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}


vec3 CalcSpotLight(FlashLight light, vec3 norm, vec3 FragPos, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - FragPos);

    // check if lighting is inside the spotlight cone
    float theta = dot(lightDir, normalize(-light.direction));

    if(theta > light.cutOff) // remember that we're working with angles as cosines instead of degrees so a '>' is used.
    {
        // ambient
        vec3 ambient = light.ambient * CalcAmbientColor();

        // diffuse
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = light.diffuse * diff * CalcDiffuseColor();

        // specular
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), CalcMaterialShininess());
        vec3 specular = light.specular * spec * CalcSpecularColor();

        // attenuation
        float distance    = length(light.position - FragPos);
        float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

        // ambient  *= attenuation; // remove attenuation from ambient, as otherwise at large distances the light would be darker inside than outside the spotlight due the ambient term in the else branche
        diffuse   *= attenuation;
        specular *= attenuation;

        return ambient + diffuse + specular;
    }
    else
    {
        // else, use ambient light so scene isn't completely dark outside the spotlight.
        return vec3(0.0f);
    }
}
