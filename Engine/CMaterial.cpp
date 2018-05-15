#include "CMaterial.h"

CMaterial::CMaterial()
{}

CMaterial::CMaterial(const CShader& shader)
{
	this->shader = shader;
}

void CMaterial::SetInt(const char* name, int val)
{
	shader(name, val);
}

void CMaterial::SetInt(int name, int val)
{
	shader(name, val);
}

void CMaterial::SetFloat(const char* name, float val)
{
	shader(name, val);
}

void CMaterial::SetFloat(int name, float val)
{
	shader(name, val);
}

void CMaterial::SetVector2(const char* name, const SVector2& vec2)
{
	shader(name, vec2);
}

void CMaterial::SetVector2(int name, const SVector2& vec2)
{
	shader(name, vec2);
}

void CMaterial::SetVector3(const char* name, const SVector3& vec3)
{
	shader(name, vec3);
}

void CMaterial::SetVector3(int name, const SVector3& vec3)
{
	shader(name, vec3);
}

void CMaterial::SetVector4(const char* name, const SVector4& vec4)
{
	shader(name, vec4);
}

void CMaterial::SetVector4(int name, const SVector4& vec4)
{
	shader(name, vec4);
}

void CMaterial::SetMatrix4x4(const char* name, const SMatrix4x4& mat4)
{
	shader(name, mat4);
}

void CMaterial::SetMatrix4x4(int name, const SMatrix4x4& mat4)
{
	shader(name, mat4);
}