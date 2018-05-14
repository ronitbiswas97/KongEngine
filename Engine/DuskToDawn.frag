#version 430 core

layout (location = 0) uniform vec2 u_resolution;
layout (location = 1) uniform vec2 u_mouse;
layout (location = 2) uniform float u_time;

out vec4 FragColor;

vec3 colorA = vec3(0.438,0.675,0.912);
vec3 colorB = vec3(1.000,0.9568627,0.8392157);

void main()
{
	vec2 st = gl_FragCoord.xy / u_resolution;
	vec2 sunPos = u_mouse / u_resolution;
	
	float y = 1 / distance(sunPos, st) * 0.16;

	vec3 pct =clamp(vec3(y), 0.0, 2.);

	vec3 color1 = mix(colorA, colorB, pct);
	vec3 color2 = clamp(vec3(y), vec3(0.0, 0.2, 0.0), vec3(1.0, 0.3, 0.0));
	vec3 color = mix(color1, color2, clamp(sin(u_time), 0.0, 0.865));
	FragColor = vec4(color, 1.0);
}