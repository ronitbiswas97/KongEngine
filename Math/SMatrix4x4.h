#ifndef SMATRIX4X4_H
#define SMATRIX4X4_H

#include "SVector3.h"
#include "SVector4.h"

struct SMatrix4x4
{
	SVector4 data[4];

	SMatrix4x4();
	SMatrix4x4(const SVector4& col1, const SVector4& col2, const SVector4& col3, const SVector4& col4);

	SVector4& operator[](size_t index);
	const SVector4& operator[](size_t index) const;
	friend SMatrix4x4 operator+(const SMatrix4x4& left, float right);
	friend SMatrix4x4 operator+(float left, const SMatrix4x4& right);
	friend SMatrix4x4 operator+(const SMatrix4x4& left, const SMatrix4x4& right);
	friend SMatrix4x4 operator-(const SMatrix4x4& left, const SMatrix4x4& right);
	friend SMatrix4x4 operator*(const SMatrix4x4& left, float right);
	friend SMatrix4x4 operator*(float left, const SMatrix4x4& right);
	friend SVector4 operator*(const SVector4& left, const SMatrix4x4& right);
	friend SVector4 operator*(const SMatrix4x4& left, const SVector4& right);
	friend SMatrix4x4 operator*(const SMatrix4x4& left, const SMatrix4x4& right);
	friend std::ostream& operator<<(std::ostream& ost, const SMatrix4x4& mat);
	friend bool operator==(const SMatrix4x4& left, const SMatrix4x4& right);
	friend bool operator!=(const SMatrix4x4& left, const SMatrix4x4& right);

	static SMatrix4x4 Inverse(const SMatrix4x4& matrix);
	static SMatrix4x4 Transpose(const SMatrix4x4& matrix);
	static SMatrix4x4 Translate(const SMatrix4x4& matrix, const SVector3& vector);
	static SMatrix4x4 Scale(const SMatrix4x4& matrix, const SVector3& vector);
	static SMatrix4x4 Rotate(const SMatrix4x4& matrix, float angle, const SVector3& axis);
	static SMatrix4x4 Ortho(float left, float right, float bottom, float top, float near, float far);
	static SMatrix4x4 Perspective(float fovy, float apect, float near, float far);
	static SMatrix4x4 LookAt(const SVector3& eye, const SVector3& target, const SVector3& up);

};

#endif