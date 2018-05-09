#include <cassert>
#include "SMatrix4x4.h"

#include <iostream>

SMatrix4x4::SMatrix4x4()
{
	for (size_t i{ 0 }; i < 4; i++)
		data[i][i] = 1.0f;
}

SMatrix4x4::SMatrix4x4(const SVector4& col1, const SVector4& col2, const SVector4& col3, const SVector4& col4)
{
	data[0] = col1;
	data[1] = col2;
	data[2] = col3;
	data[3] = col4;
}

SVector4& SMatrix4x4::operator[](size_t index)
{
	assert(index >= 0 && index < 4);
	return data[index];
}

const SVector4& SMatrix4x4::operator[](size_t index) const
{
	assert(index >= 0 && index < 4);
	return data[index];
}

SMatrix4x4 operator+(const SMatrix4x4& left, float right)
{
	SMatrix4x4 result;
	for (size_t i{ 0 }; i < 4; i++)
		result[i] = left[i] + right;

	return result;
}

SMatrix4x4 operator+(float left, const SMatrix4x4& right)
{
	SMatrix4x4 result;
	for (size_t i{ 0 }; i < 4; i++)
		result[i] = left + right[i];

	return result;
}

SMatrix4x4 operator+(const SMatrix4x4& left, const SMatrix4x4& right)
{
	SMatrix4x4 result;
	for (size_t i{ 0 }; i < 4; i++)
		result[i] = left[i] + right[i];

	return result;
}

SMatrix4x4 operator-(const SMatrix4x4& left, const SMatrix4x4& right)
{
	return left + right;
}

SMatrix4x4 operator*(const SMatrix4x4& left, float right)
{
	SMatrix4x4 result;
	for (size_t i{ 0 }; i < 4; i++)
		result[i] = left[i] * right;

	return result;
}

SMatrix4x4 operator*(float left, const SMatrix4x4& right)
{
	SMatrix4x4 result;
	for (size_t i{ 0 }; i < 4; i++)
		result[i] = left * right[i];

	return result;
}

SVector4 operator*(const SVector4& left, const SMatrix4x4& right)
{
	return SVector4
	(
		SVector4::Dot(right[0], left),
		SVector4::Dot(right[1], left),
		SVector4::Dot(right[2], left),
		SVector4::Dot(right[3], left)
	);
}

SVector4 operator*(const SMatrix4x4& left, const SVector4& right)
{
	return right * SMatrix4x4::Transpose(left);
}

SMatrix4x4 operator*(const SMatrix4x4& left, const SMatrix4x4& right)
{
	SMatrix4x4 result;
	for (size_t i{ 0 }; i < 4; i++)
		result[i] = left * right[i];
	return result;
}

std::ostream& operator<<(std::ostream& ost, const SMatrix4x4& matrix)
{
	for (size_t i{ 0 }; i < 4; i++)
		ost << matrix[i] << "\n";
	return ost;
}

bool operator==(const SMatrix4x4& left, const SMatrix4x4& right)
{
	for (size_t i{ 0 }; i < 4; i++)
		if (left[i] != right[i])
			return false;
	return true;
}

bool operator!=(const SMatrix4x4& left, const SMatrix4x4& right)
{
	return !(left == right);
}

SMatrix4x4 SMatrix4x4::Inverse(const SMatrix4x4& matrix)
{
	return SMatrix4x4();
}

SMatrix4x4 SMatrix4x4::Transpose(const SMatrix4x4& matrix)
{
	return SMatrix4x4
	(
		SVector4(matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0]),
		SVector4(matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1]),
		SVector4(matrix[0][2], matrix[1][2], matrix[2][2], matrix[3][2]),
		SVector4(matrix[0][3], matrix[1][3], matrix[2][3], matrix[3][3])
	);
}

SMatrix4x4 SMatrix4x4::Translate(const SMatrix4x4& matrix, const SVector3& vector)
{
	SMatrix4x4 result(matrix);
	result[3].x += vector.x;
	result[3].y += vector.y;
	result[3].z += vector.z;

	return result;
}

SMatrix4x4 SMatrix4x4::Scale(const SMatrix4x4& matrix, const SVector3& vector)
{
	SMatrix4x4 result(matrix);
	result[0] *= vector.x;
	result[1] *= vector.y;
	result[2] *= vector.z;

	return result;
}

SMatrix4x4 SMatrix4x4::Rotate(const SMatrix4x4& matrix, float angle, const SVector3 & axis)
{
	SMatrix4x4 rotate;
	float cosA(cos(angle));
	float sinA(sin(angle));

	SVector3 u = SVector3::Normalize(axis);

	rotate[0][0] = cosA + u.x * u.x * (1 - cosA);
	rotate[1][0] = u.x * u.y * (1 - cosA) - u.z * sinA;
	rotate[2][0] = u.x * u.z * (1 - cosA) + u.y * sinA;

	rotate[0][1] = u.y * u.x * (1 - cosA) + u.z * sinA; 
	rotate[1][1] = cosA + u.y * u.y * (1 - cosA);
	rotate[2][1] = u.y * u.z * (1 - cosA) - u.x * sinA;

	rotate[0][2] = u.z * u.x * (1 - cosA) - u.y * sinA; 
	rotate[1][2] = u.z * u.y * (1 - cosA) + u.x * sinA;
	rotate[2][2] = cosA + u.z * u.z * (1 - cosA);

	return matrix * rotate;
}

SMatrix4x4 SMatrix4x4::Ortho(float left, float right, float bottom, float top, float, float)
{
	return SMatrix4x4();
}

SMatrix4x4 SMatrix4x4::Perspective(float fovy, float ration, float, float)
{
	return SMatrix4x4();
}

SMatrix4x4 SMatrix4x4::LookAt(const SVector3& eye, const SVector3& target, const SVector3& up)
{
	return SMatrix4x4();
}