#ifndef CSHADER_H
#define CSHADER_H

#include <string>
#include "Maths.h"

enum ShaderType
{
	VERTEX = 0x8B31,
	FRAGMENT = 0x8B30,
	PROGRAM = 0
};

class CShader
{
private:
	unsigned int ID;

public:
	CShader();
	CShader(const std::string& vertexSourceFileName, const std::string& fragmentFileName);

	void operator()(const char* name, int value);
	void operator()(int name, int value);
	void operator()(const char* name, float value);
	void operator()(int name, float value);
	void operator()(const char* name, const SVector2& vec2);
	void operator()(int name, const SVector2& vec2);
	void operator()(const char* name, const SVector3& vec3);
	void operator()(int name, const SVector3& vec3);
	void operator()(const char* name, const SVector4& vec4);
	void operator()(int name, const SVector4& vec4);
	void operator()(const char* name, const SMatrix4x4& mat4);
	void operator()(int name, const SMatrix4x4& mat4);

	unsigned int GetID()const;
	void Use() const;
	void Delete() const;

	static std::string ReadFile(const std::string& fileName);
private:
	unsigned int Compile(const char* shaderSource, ShaderType type);
	void Errors(unsigned int shader, ShaderType type);
};

#endif
