#include <cassert>
#include <cmath>

#include "SVector4.h"


SVector4::SVector4(): x{ 0 }, y{ 0 },z{ 0 },w{ 0 }
{
}

SVector4::SVector4(float x, float y, float z, float w): x{ x },y{ y },z{ z },w{ w }
{
}

SVector4::SVector4(const SVector4& v): x{ v.x },y{ v.y },z{ v.z },w{ v.w }
{
}

float& SVector4::operator[](size_t index)
{
    assert(index < m_length && index >= 0);
    return *(&x + index);
}

const float& SVector4::operator[](size_t index) const
{
    assert(index < m_length && index >= 0);
    return *(&x + index);
}

SVector4& SVector4::operator=(const SVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

SVector4 operator+(const SVector4 & left, float right)
{
    return SVector4
    (
        left.x + right,
        left.y + right,
        left.z + right,
        left.w + right
    );
}

SVector4 operator+(float left, const SVector4 & right)
{
    return SVector4
    (
        left + right.x,
        left + right.y,
        left + right.z,
        left + right.w
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

SVector4 operator-(const SVector4 & left, float right)
{
    return SVector4
    (
        left.x - right,
        left.y - right,
        left.z - right,
        left.w - right
    );
}

SVector4 operator-(float left, const SVector4 & right)
{
    return SVector4
    (
        left - right.x,
        left - right.y,
        left - right.z,
        left - right.w
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

SVector4 operator*(const SVector4 & left, float right)
{
    return SVector4
    (
        left.x * right,
        left.y * right,
        left.z * right,
        left.w * right
    );
}

SVector4 operator*(float left, const SVector4 & right)
{
    return SVector4
    (
        left * right.x,
        left * right.y,
        left * right.z,
        left * right.w
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

SVector4 operator/(const SVector4 & left, float right)
{
    return SVector4
    (
        left.x / right,
        left.y / right,
        left.z / right,
        left.w / right
    );
}

SVector4 operator/(float left, const SVector4 & right)
{
    return SVector4
    (
        left / right.x,
        left / right.y,
        left / right.z,
        left / right.w
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

std::ostream& operator<<(std::ostream& ost, const SVector4& v)
{
	ost << v.x << " " << v.y << " " << v.z <<" "<<v.w;
	return ost;
}

float SVector4::Dot(const SVector4& left, const SVector4& right)
{
    SVector4 temp(left * right);
    return (temp.x + temp.y + temp.z + temp.w);
}

float SVector4::Magnitud(const SVector4 & v)
{
    float x{ v.x * v.x };
    float y{ v.y * v.y };
    float z{ v.z * v.z };
    float w{ v.w * v.w };
    return sqrtf(x + y + z + w);
}

SVector4 SVector4::Normalize(const SVector4& v)
{
    float x{ v.x * v.x };
    float y{ v.y * v.y };
    float z{ v.z * v.z };
    float w{ v.z * v.w };
    float magnitud{ sqrtf(x + y + z + w) };
    return SVector4(x / magnitud, y / magnitud, z / magnitud, w / magnitud);
}

float SVector4::Distance(const SVector4& left, const SVector4& right)
{
    float x((left.x - right.x) * (left.x - right.x));
    float y((left.y - right.y) * (left.y - right.y));
    float z((left.z - right.z) * (left.z - right.z));
    float w((left.w - right.w) * (left.w - right.w));
    return sqrtf(x + y + z + w);
}


