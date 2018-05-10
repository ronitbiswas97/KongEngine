#include <cassert>
#include <cmath>

#include "SVector2.h"

SVector2::SVector2()
	: SVector2(0.0f)
{
}

SVector2::SVector2(float x)
	: SVector2(x, x)
{
}

SVector2::SVector2(float x, float y)
	: x(x), y(y)
{
}

SVector2::SVector2(const SVector2& SVector)
	: SVector2(SVector.x, SVector.y)
{
}

float& SVector2::operator[](size_t index)
{
	assert(index >= 0 && index < 2);
	return *(&x + index);
}

const float& SVector2::operator[](size_t index) const
{
	assert(index >= 0 && index < 2);
	return *(&x + index);
}

SVector2& SVector2::operator+=(const SVector2& right)
{
	x += right.x;
	y += right.y;

	return *this;
}

SVector2& SVector2::operator-=(const SVector2& right)
{
	x -= right.x;
	y -= right.y;

	return *this;
}

SVector2& SVector2::operator*=(const SVector2& right)
{
	x *= right.x;
	y *= right.y;

	return *this;
}

SVector2& SVector2::operator/=(const SVector2& right)
{
	x /= right.x;
	y /= right.y;

	return *this;
}

SVector2 operator+(float left, const SVector2& right)
{
	return SVector2
	(
		left + right.x,
		left + right.y
	);
}

SVector2 operator+(const SVector2& left, float right)
{
	return SVector2
	(
		left.x + right,
		left.y + right
	);
}

SVector2 operator+(const SVector2& left, const SVector2& right)
{
	return SVector2
	(
		left.x + right.x,
		left.y + right.y
	);
}

SVector2 operator-(float left, const SVector2& right)
{
	return SVector2
	(
		left - right.x,
		left - right.y
	);
}

SVector2 operator-(const SVector2& left, float right)
{
	return SVector2
	(
		left.x - right,
		left.y - right
	);
}

SVector2 operator-(const SVector2& left, const SVector2& right)
{
	return SVector2
	(
		left.x - right.x,
		left.y - right.y
	);
}

SVector2 operator*(float left, const SVector2& right)
{
	return SVector2
	(
		left * right.x,
		left * right.y
	);
}

SVector2 operator*(const SVector2& left, float right)
{
	return SVector2
	(
		left.x * right,
		left.y * right
	);
}

SVector2 operator*(const SVector2& left, const SVector2& right)
{
	return SVector2
	(
		left.x * right.x,
		left.y * right.y
	);
}

SVector2 operator/(float left, const SVector2& right)
{
	return SVector2
	(
		left / right.x,
		left / right.y
	);
}

SVector2 operator/(const SVector2& left, float right)
{
	return SVector2
	(
		left.x / right,
		left.y / right
	);
}

SVector2 operator/(const SVector2& left, const SVector2& right)
{
	return SVector2
	(
		left.x / right.x,
		left.y / right.y
	);
}

bool operator==(const SVector2& left, const SVector2& right)
{
	return (left.x == right.x && left.y == right.y);
}

bool operator!=(const SVector2& left, const SVector2& right)
{
	return !(left == right);
}

std::ostream& operator<<(std::ostream& ost, const SVector2& SVector)
{
	ost << SVector.x << " " << SVector.y;
	return ost;
}

float SVector2::Dot(const SVector2& left, const SVector2& right)
{
	SVector2 result(left * right);
	return (result.x + result.y);
}

float SVector2::Magnitud(const SVector2& SVector)
{
	return sqrtf(SVector2::Dot(SVector, SVector));
}

SVector2 SVector2::Normalize(const SVector2& SVector)
{
	return SVector2((SVector / SVector2::Magnitud(SVector)));
}

float SVector2::Distance(const SVector2& left, const SVector2& right)
{
	return SVector2::Magnitud(left - right);
}

SVector2 SVector2::Projection(const SVector2 & left, const SVector2 & right)
{
	float scalar
	(
		SVector2::Dot(left, right) / SVector2::Dot(right, right)
	);

	return SVector2(scalar * right);
}

SVector2 SVector2::Lerp(const SVector2& a, const SVector2& b, float t)
{
	return SVector2((1 - t) * a + b * t);
}