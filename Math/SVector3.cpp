#include <cassert>
#include <cmath>

#include "SVector3.h"

SVector3::SVector3()
	: SVector3(0.0f)
{
}

SVector3::SVector3(float x)
	: SVector3(x, x, x)
{
}

SVector3::SVector3(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

SVector3::SVector3(const SVector3& vector)
	: SVector3(vector.x, vector.y, vector.z)
{
}

float& SVector3::operator[](size_t index)
{
	assert(index >= 0 && index < 3);
	return *(&x + index);
}

const float& SVector3::operator[](size_t index) const
{
	assert(index >= 0 && index < 3);
	return *(&x + index);
}

SVector3& SVector3::operator+=(const SVector3& right)
{
	x += right.x;
	y += right.y;
	z += right.z;

	return *this;
}

SVector3& SVector3::operator-=(const SVector3& right)
{
	x -= right.x;
	y -= right.y;
	z -= right.z;

	return *this;
}

SVector3& SVector3::operator*=(const SVector3& right)
{
	x *= right.x;
	y *= right.y;
	z *= right.z;

	return *this;
}

SVector3& SVector3::operator/=(const SVector3& right)
{
	x /= right.x;
	y /= right.y;
	z /= right.z;

	return *this;
}

SVector3 operator+(float left, const SVector3& right)
{
	return SVector3
	(
		left + right.x,
		left + right.y,
		left + right.z
	);
}

SVector3 operator+(const SVector3& left, float right)
{
	return SVector3
	(
		left.x + right,
		left.y + right,
		left.z + right
	);
}

SVector3 operator+(const SVector3& left, const SVector3& right)
{
	return SVector3
	(
		left.x + right.x,
		left.y + right.y,
		left.z + right.z
	);
}

SVector3 operator-(float left, const SVector3& right)
{
	return SVector3
	(
		left - right.x,
		left - right.y,
		left - right.z
	);
}

SVector3 operator-(const SVector3& left, float right)
{
	return SVector3
	(
		left.x - right,
		left.y - right,
		left.z - right
	);
}

SVector3 operator-(const SVector3& left, const SVector3& right)
{
	return SVector3
	(
		left.x - right.x,
		left.y - right.y,
		left.z - right.z
	);
}

SVector3 operator*(float left, const SVector3& right)
{
	return SVector3
	(
		left * right.x,
		left * right.y,
		left * right.z
	);
}

SVector3 operator*(const SVector3& left, float right)
{
	return SVector3
	(
		left.x * right,
		left.y * right,
		left.z * right
	);
}

SVector3 operator*(const SVector3& left, const SVector3& right)
{
	return SVector3
	(
		left.x * right.x,
		left.y * right.y,
		left.z * right.z
	);
}

SVector3 operator/(float left, const SVector3& right)
{
	return SVector3
	(
		left / right.x,
		left / right.y,
		left / right.z
	);
}

SVector3 operator/(const SVector3& left, float right)
{
	return SVector3
	(
		left.x / right,
		left.y / right,
		left.z / right
	);
}

SVector3 operator/(const SVector3& left, const SVector3& right)
{
	return SVector3
	(
		left.x / right.x,
		left.y / right.y,
		left.z / right.z
	);
}

bool operator==(const SVector3& left, const SVector3& right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z);
}

bool operator!=(const SVector3& left, const SVector3& right)
{
	return !(left == right);
}

std::ostream& operator<<(std::ostream& ost, const SVector3& vector)
{
	ost << vector.x << " " << vector.y << " " << vector.z;
	return ost;
}

float SVector3::Dot(const SVector3& left, const SVector3& right)
{
	SVector3 result(left * right);
	return (result.x + result.y + result.z);
}

float SVector3::Magnitud(const SVector3& vector)
{
	return sqrtf(SVector3::Dot(vector, vector));
}

SVector3 SVector3::Normalize(const SVector3& vector)
{
	return SVector3((vector / SVector3::Magnitud(vector)));
}

float SVector3::Distance(const SVector3& left, const SVector3& right)
{
	return SVector3::Magnitud(left - right);
}

SVector3 SVector3::Projection(const SVector3 & left, const SVector3 & right)
{
	float scalar
	(
		SVector3::Dot(left, right) / SVector3::Dot(right, right)
	);

	return SVector3(scalar * right);
}

SVector3 SVector3::Cross(const SVector3& left, const SVector3& right)
{
	return SVector3
	(
		left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x
	);
}

SVector3 SVector3::Lerp(const SVector3& a, const SVector3& b, float t)
{
	return SVector3((1 - t) * a + b * t);
}