#ifndef SVECTOR4_H
#define SVECTOR4_H

#include <ostream>

struct SVector4
{
	struct { float x, y, z, w; };

	SVector4();
	SVector4(float x);
	SVector4(float x, float y, float z, float w);
	SVector4(const SVector4& copy);

	float& operator[](size_t index);
	const float& operator[](size_t index) const;

	SVector4& operator+=(const SVector4& right);
	SVector4& operator-=(const SVector4& right);
	SVector4& operator*=(const SVector4& right);
	SVector4& operator/=(const SVector4& right);

	friend SVector4 operator+(float left, const SVector4& right);
	friend SVector4 operator+(const SVector4& left, float right);
	friend SVector4 operator+(const SVector4& left, const SVector4& right);
	friend SVector4 operator-(float left, const SVector4& right);
	friend SVector4 operator-(const SVector4& left, float right);
	friend SVector4 operator-(const SVector4& left, const SVector4& right);
	friend SVector4 operator*(float left, const SVector4& right);
	friend SVector4 operator*(const SVector4& left, float right);
	friend SVector4 operator*(const SVector4& left, const SVector4& right);
	friend SVector4 operator/(float left, const SVector4& right);
	friend SVector4 operator/(const SVector4& left, float right);
	friend SVector4 operator/(const SVector4& left, const SVector4& right);

	friend bool operator==(const SVector4& left, const SVector4& right);
	friend bool operator!=(const SVector4& left, const SVector4& right);
	friend std::ostream& operator<<(std::ostream& ost, const SVector4& vector);

	static float Dot(const SVector4& left, const SVector4& right);
	static float Magnitud(const SVector4& vector);
	static SVector4 Normalize(const SVector4& vector);
	static float Distance(const SVector4& left, const SVector4& right);
	static SVector4 Projection(const SVector4& left, const SVector4& right);
	static SVector4 Lerp(const SVector4& a, const SVector4& b, float t);
};

#endif // !SVECTOR4_H
