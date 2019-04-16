// Fragment shader:
// ================
#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 LightPos;   // extra in variable, since we need the light position in view space we calculate this in the vertex shader

uniform vec3 lightColor;
uniform vec3 objectColor;
const bool blinn = true;
void main()
{
    // ambient
    float ambientStrength = 0.3;
    vec3 ambient = ambientStrength * objectColor;    
    
     // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * objectColor;
    
	vec3 specularReflection;
	if(!blinn)
	{
		if (dot(norm, lightDir) < 0.0) // light source on the wrong side?
		{
			specularReflection = vec3(0.0, 0, 0); // no specular reflection
		}
		else // light source on the right side
		{
			specularReflection = 0.5 * vec3(1,1,1) * pow(max(0.0, dot(reflect(lightDir, norm), normalize(-FragPos))), 8);
		}
	}
   

	if(blinn)
	{
		float specularStrength = 0.3;
		vec3 viewDir = normalize(-FragPos);

		vec3 halfAngle = normalize(lightDir - viewDir);
		float blinnTerm = dot(norm, halfAngle);
		blinnTerm = clamp(blinnTerm, 0, 1);
		blinnTerm = diff != 0.0 ? blinnTerm : 0.0;
		blinnTerm = pow(blinnTerm, 32);

		specularReflection = specularStrength * blinnTerm * lightColor; 
	}
  
	  // = vec3(0,1,1);
   
	vec3  result = (ambient+specularReflection+diffuse);;
	

   
    FragColor = vec4(result, 1.0);
}