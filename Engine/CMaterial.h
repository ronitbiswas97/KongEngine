#ifndef CMATERIAL_H
#define CMATERIAL_H

#include "CShader.h"

class CMaterial
{
public:
	CShader shader;

public:
	CMaterial();
	CMaterial(const CShader& shader);

	void SetInt(const char* name, int val);
	void SetInt(int name, int val);
	void SetFloat(const char* name, float val);
	void SetFloat(int name, float val);
	void SetVector2(const char* name, const SVector2& vec2);
	void SetVector2(int name, const SVector2& vec2);
	void SetVector3(const char* name, const SVector3& vec3);
	void SetVector3(int name, const SVector3& vec3);
	void SetVector4(const char* name, const SVector4& vec4);
	void SetVector4(int name, const SVector4& vec4);
	void SetMatrix4x4(const char* name, const SMatrix4x4& mat4);
	void SetMatrix4x4(int name, const SMatrix4x4& mat4);
};

#endif