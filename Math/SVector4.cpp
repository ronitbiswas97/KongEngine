#include <cassert>
#include <cmath>

#include "SVector4.h"

SVector4::SVector4()
	: SVector4(0.0f)
{
}

SVector4::SVector4(float x)
	: SVector4(x, x, x, x)
{
}

SVector4::SVector4(float x, float y, float z, float w)
	: x(x), y(y), z(z), w(w)
{
}

SVector4::SVector4(const SVector4& vector)
	: SVector4(vector.x, vector.y, vector.z, vector.w)
{
}

float& SVector4::operator[](size_t index)
{
	assert(index >= 0 && index < 4);
	return *(&x + index);
}

const float& SVector4::operator[](size_t index) const
{
	assert(index >= 0 && index < 4);
	return *(&x + index);
}

SVector4& SVector4::operator+=(const SVector4& right)
{
	x += right.x;
	y += right.y;
	z += right.z;
	w += right.w;

	return *this;
}

SVector4& SVector4::operator-=(const SVector4& right)
{
	x -= right.x;
	y -= right.y;
	z -= right.z;
	w -= right.w;

	return *this;
}

SVector4& SVector4::operator*=(const SVector4& right)
{
	x *= right.x;
	y *= right.y;
	z *= right.z;
	w *= right.w;

	return *this;
}

SVector4& SVector4::operator/=(const SVector4& right)
{
	x /= right.x;
	y /= right.y;
	z /= right.z;
	w /= right.w;

	return *this;
}

SVector4 operator+(float left, const SVector4& right)
{
	return SVector4
	(
		left + right.x,
		left + right.y,
		left + right.z,
		left + right.w
	);
}

SVector4 operator+(const SVector4& left, float right)
{
	return SVector4
	(
		left.x + right,
		left.y + right,
		left.z + right,
		left.w + right
	);
}

SVector4 operator+(const SVector4& left, const SVector4& right)
{
	return SVector4
	(
		left.x + right.x,
		left.y + right.y,
		left.z + right.z,
		left.w + right.w
	);
}

SVector4 operator-(float left, const SVector4& right)
{
	return SVector4
	(
		left - right.x,
		left - right.y,
		left - right.z,
		left - right.w
	);
}

SVector4 operator-(const SVector4& left, float right)
{
	return SVector4
	(
		left.x - right,
		left.y - right,
		left.z - right,
		left.w - right
	);
}

SVector4 operator-(const SVector4& left, const SVector4& right)
{
	return SVector4
	(
		left.x - right.x,
		left.y - right.y,
		left.z - right.z,
		left.w - right.w
	);
}

SVector4 operator*(float left, const SVector4& right)
{
	return SVector4
	(
		left * right.x,
		left * right.y,
		left * right.z,
		left * right.w
	);
}

SVector4 operator*(const SVector4& left, float right)
{
	return SVector4
	(
		left.x * right,
		left.y * right,
		left.z * right,
		left.w * right
	);
}

SVector4 operator*(const SVector4& left, const SVector4& right)
{
	return SVector4
	(
		left.x * right.x,
		left.y * right.y,
		left.z * right.z,
		left.w * right.w
	);
}

SVector4 operator/(float left, const SVector4& right)
{
	return SVector4
	(
		left / right.x,
		left / right.y,
		left / right.z,
		left / right.w
	);
}

SVector4 operator/(const SVector4& left, float right)
{
	return SVector4
	(
		left.x / right,
		left.y / right,
		left.z / right,
		left.w / right
	);
}

SVector4 operator/(const SVector4& left, const SVector4& right)
{
	return SVector4
	(
		left.x / right.x,
		left.y / right.y,
		left.z / right.z,
		left.w / right.w
	);
}

bool operator==(const SVector4& left, const SVector4& right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w);
}

bool operator!=(const SVector4& left, const SVector4& right)
{
	return !(left == right);
}

std::ostream& operator<<(std::ostream& ost, const SVector4& vector)
{
	ost << vector.x << " " << vector.y << " " << vector.z << " " << vector.w;
	return ost;
}

float SVector4::Dot(const SVector4& left, const SVector4& right)
{
	SVector4 result(left * right);
	return (result.x + result.y + result.z + result.w);
}

float SVector4::Magnitud(const SVector4& vector)
{
	return sqrtf(SVector4::Dot(vector, vector));
}

SVector4 SVector4::Normalize(const SVector4& vector)
{
	return SVector4((vector / SVector4::Magnitud(vector)));
}

float SVector4::Distance(const SVector4& left, const SVector4& right)
{
	return SVector4::Magnitud(left - right);
}

SVector4 SVector4::Projection(const SVector4 & left, const SVector4 & right)
{
	float scalar
	(
		SVector4::Dot(left, right) / SVector4::Dot(right, right)
	);

	return SVector4(scalar * right);
}

SVector4 SVector4::Lerp(const SVector4& a, const SVector4& b, float t)
{
	return SVector4((1 - t) * a + b * t);
}