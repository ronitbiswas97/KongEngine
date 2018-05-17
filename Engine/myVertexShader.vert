#version 430 core

layout (location = 0) in vec4 vPos;

layout (location = 6) uniform mat4 M;
layout (location = 7) uniform mat4 V;
layout (location = 8) uniform mat4 P;

out vec3 color;

void main()
{
	gl_Position = P * V * M * vPos;
	color = vec3(vPos);
}